/*
 * File:  dl_list.h
 * Brief: Double linked list header
 * Created on 18.11.2019
 * (c) MIPT 2019
 */

#pragma once

typedef struct _LIST_ENTRY LIST_ENTRY;

typedef struct _LIST
{
  LIST_ENTRY *first;
} LIST;

struct _LIST_ENTRY
{
  int value;
  LIST_ENTRY *prev;
  LIST_ENTRY *next;
};

/*
 * TODO: description
 */
LIST *list_new();

void list_delete(LIST *list);

int push(LIST *list, int value);

int pop(LIST *list, int *value);

int unshift(LIST *list, int value);

int shift(LIST *list, int *value);

