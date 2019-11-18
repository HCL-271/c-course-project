/*
 * File:  dl_test.h
 * Brief: Double linked list testing
 * Created on 18.11.2019
 * (c) MIPT 2019
 */

#pragma once

typedef int(*TEST)(void);

void init_tests();

void deinit_tests();

int run_all_tests();

void run_test(int num, char *description, TEST test);

int test_create(void);

int test_add(void);

int test_remove(void);

