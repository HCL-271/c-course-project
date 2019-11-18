/*
 * File:  logger.h
 * Brief: Logger header
 * Created on 18.11.2019
 * (c) MIPT 2019
 */

#pragma once

#include <stdio.h>

enum LOG_LEVEL
{
  ERROR,
  DEBUG,
  INFO,
  MAX_LEVEL
};

// To access the variable from other modules
// extern FILE *g_log;

int log_init();

void log_deinit();

int log(int log_level, char *format, ...);