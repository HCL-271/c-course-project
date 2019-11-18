/*
 * File:  dl_list.c
 * Brief: Double linked list implementation
 * Created on 18.11.2019
 * (c) MIPT 2019
 */

#include "common.h"
#define LOG_LEVEL INFO

LIST *list_new()
{
  if (!log_init(LOG_LEVEL))
  {
    return NULL;
  }

  log(INFO, "%s: Allocate memory\n", __FUNCTION__);
  LIST *list = malloc(sizeof(LIST));
  if (NULL == list)
  {
    log(ERROR, "%s: Fail to allocate memory\n", __FUNCTION__);
    return NULL;
  }

  list->first = NULL;
  log(INFO, "%s: Completed\n", __FUNCTION__);
  return list;
}

void list_delete(LIST *list)
{
  if (NULL == list)
  {
    log(ERROR, "%s: list is NULL\n", __FUNCTION__);
    return;
  }

  int value;
  while (pop(list, &value));

  log(INFO, "%s: Free memory\n", __FUNCTION__);
  free(list);
  log_deinit();
}

int push(LIST *list, int value)
{
  log(INFO, "%s: Not supported\n", __FUNCTION__);
  return FALSE;
}

int pop(LIST *list, int *value)
{
  if (NULL == list)
  {
    log(ERROR, "%s: list is NULL\n", __FUNCTION__);
    return FALSE;
  }

  if (NULL == list->first)
  {
    log(INFO, "%s: list is empty\n", __FUNCTION__);
    return FALSE;
  }

  LIST_ENTRY *current = list->first;
  log(INFO, "%s: first element is %p (%d)\n", __FUNCTION__, current, current->value);
  while (current->next != NULL)
  {
    current = current->next;
    log(INFO, "%s: current element is %p (%d)\n", __FUNCTION__, current, current->value);
  }

  *value = current->value;
  if (current->prev != NULL)
  {
    current->prev->next = NULL;
  }
  else
  {
    list->first = NULL;
  }

  log(ERROR, "%s: free element %p (%d)\n", __FUNCTION__, current, current->value);
  free(current);
  return TRUE;
}

int unshift(LIST *list, int value)
{
  log(INFO, "%s: Not supported\n", __FUNCTION__);
  return FALSE;
}

int shift(LIST *list, int *value)
{
  log(INFO, "%s: Not supported\n", __FUNCTION__);
  return FALSE;
}