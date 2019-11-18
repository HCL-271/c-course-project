/*
 * File:  color.c
 * Brief: Print colorful message to console
 * Created on 18.11.2019
 * (c) MIPT 2019
 */

#include <Windows.h>
#include <stdio.h>
#include "color.h"

/* This structure is not in header file, because it won't be shared */
typedef struct _CONSOLE_COLOR
{
  HANDLE hConsole;
  WORD saved_attributes;
} CONSOLE_COLOR;

CONSOLE_COLOR g_console;

void init_color()
{
  g_console.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO info;

  GetConsoleScreenBufferInfo(g_console.hConsole, &info);
  g_console.saved_attributes = info.wAttributes;
}

void deinit_color()
{
  CloseHandle(g_console.hConsole);
}

void print_color(COLOR color, char *message)
{
  switch (color)
  {
  case COLOR_GREEN:
    color = FOREGROUND_GREEN;
    break;
  case COLOR_RED:
    color = FOREGROUND_RED;
    break;
  default:
    color = FOREGROUND_BLUE;
    break;
  }

  SetConsoleTextAttribute(g_console.hConsole, color);
  printf(message);
  SetConsoleTextAttribute(g_console.hConsole, g_console.saved_attributes);
}