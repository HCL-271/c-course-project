/*
 * File:  main.c
 * Brief: TBD
 * Created on 18.11.2019
 * (c) MIPT 2019
 */

#include "common.h"
#include "dl_test.h"
#include "dl_task.h"

void print_usage(char *prog_name)
{
  int test_num = 1;
  printf("%s <mode>\n", prog_name);
  printf("Modes:\n");
  printf("\ttests\n\t\tRun all tests\n");
  printf("\ttest <test_num>\n\t\tRun specific test\n");
  printf("\t\t\t%d\ttest create\n\t\t\t%d\ttest_add\n\t\t\t%d\ttest_remove\n", test_num, test_num + 1, test_num + 2);
  printf("\ttask\n\t\tRun task code\n");
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    print_usage(argv[0]);
    return -1;
  }

  if (!strcmp(argv[1], "tests"))
  {
    init_tests();
    run_all_tests();
    deinit_tests();
    return 0;
  }
  else if (!strcmp(argv[1], "test"))
  {
    if (argc >= 3)
    {
      int test_num = atoi(argv[2]);

      init_tests();
      switch (test_num)
      {
      case 1:
        run_test(test_num, "Create list", test_create);
        break;
      case 2:
        run_test(test_num, "Add element", test_add);
        break;
      case 3:
        run_test(test_num, "Remove element", test_remove);
        break;
      }
      deinit_tests();
      return 0;
    }
  }
  else if (!strcmp(argv[1], "task"))
  {
    brackets();
    return 0;
  }

  print_usage(argv[0]);
  return 0;
}