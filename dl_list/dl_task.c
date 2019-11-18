/*
 * File:  dl_list.c
 * Brief: 1.4 Double linked list task implementation
 * Created on 18.11.2019
 * (c) MIPT 2019
 */

#include "common.h"

int brackets(void)
{
  LIST *list = list_new();
  if (NULL == list)
  {
    return FALSE;
  }

  // TODO

  list_delete(list);
  return TRUE;
}