/*
 * File:  color.h
 * Brief: Print colorful message to console
 * Created on 18.11.2019
 * (c) MIPT 2019
 */

#pragma once

typedef enum _COLOR
{
  COLOR_GREEN,
  COLOR_RED
} COLOR;

void init_color();

void deinit_color();

void print_color(COLOR color, char *message);