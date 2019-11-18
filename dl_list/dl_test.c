/*
 * File:  dl_test.c
 * Brief: Double linked list testing
 * Created on 18.11.2019
 * (c) MIPT 2019
 */

#include "common.h"
#include <assert.h>
#include "color.h"
#include "dl_test.h"

int test_create(void)
{
  printf("%s: Create list\n", __FUNCTION__);
  LIST *list = list_new();
  if (NULL == list)
  {
    printf("%s: Fail to create list\n", __FUNCTION__);
    return -1;
  }

  if (NULL != list->first)
  {
    printf("%s: First element is not NULL\n", __FUNCTION__);
    return -2;
  }

  printf("%s: Delete list\n", __FUNCTION__);
  list_delete(list);
  return 0;
}

int test_add(void)
{
  return 0;
}

int test_remove(void)
{
  return 0;
}

// Test using assert
void test_assert(void)
{
  LIST *list = list_new();
  assert(NULL != list);
  printf("%s: Create list\n", __FUNCTION__);

  assert(NULL == list->first);

  printf("%s: Delete list\n", __FUNCTION__);
  list_delete(list);
}

void init_tests()
{
  init_color();
}

void deinit_tests()
{
  deinit_color();
}

void run_test(int num, char *description, TEST test)
{
  printf("TEST #%d %s:\t\tExecution\n", num, description);
  int result = test();
  printf("TEST #%d %s:\t\tExecution completed with code 0x%08x\n", num, description, result);
  printf("TEST #%d %s:\t\t", num, description);
  (result == 0) ? print_color(COLOR_GREEN, "PASS\n") : print_color(COLOR_RED, "FAIL\n");
}

int run_all_tests()
{
  printf("Run all tests:\n");
  int test_num = 0;

  run_test(++test_num, "Create list", test_create);
  run_test(++test_num, "Add element", test_add);
  run_test(++test_num, "Remove element", test_remove);

  return 0;
}