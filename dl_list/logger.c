/*
 * File:  logger.ñ
 * Brief: Logger implementation
 * Created on 18.11.2019
 * (c) MIPT 2019
 */

#include "common.h"
#include <time.h>
#include <string.h>
#define SIZE 1024
#define EPOCH_YEAR 1900
#define EPOCH_MON 1

FILE *g_log;
int g_log_level;

int log_init(int log_level)
{
  // Generate log name using current time
  char *log_name[SIZE];
  time_t curr_time = time(NULL);
  struct tm* local_time = localtime(&curr_time);
  sprintf(log_name, "log-%04d.%02d.%02d-%02d-%02d-%02d.txt",
    local_time->tm_year + EPOCH_YEAR,
    local_time->tm_mon + EPOCH_MON,
    local_time->tm_mday,
    local_time->tm_hour,
    local_time->tm_min,
    local_time->tm_sec);

  // Open log with write access
  g_log = fopen(log_name, "w");
  if (NULL == g_log)
  {
    printf("Can't open log file\n");
    return 0;
  }

  g_log_level = log_level;
  fprintf(g_log, "%s: Init log\n", __FUNCTION__);
  return 1;
}

void log_deinit()
{
  if (NULL != g_log)
  {
    fprintf(g_log, "%s: Deinit log\n", __FUNCTION__);
    fclose(g_log);
    g_log = NULL;
  }
}

int log(int log_level, char *format, ...)
{
  if (g_log_level < log_level)
  {
    // Skip this message
    return -1;
  }

  // Add time to log message
  char message[SIZE];
  int result = 0;
  time_t curr_time = time(NULL);
  sprintf(message, "%s", ctime(&curr_time));
  message[strlen(message) - 1] = ' '; // change '\n' to space
  switch (log_level)
  {
  case ERROR:
    strcat(message, "[E] ");
    break;
  case DEBUG:
    strcat(message, "[D] ");
    break;
  default:
    strcat(message, "[I] ");
    break;
  }
  strcat(message, format);

  // Pass to print
  va_list args;
  va_start(args, format);
  result = vfprintf(g_log, message, args);
  va_end(args);

  return result;
}