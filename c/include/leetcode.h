#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#ifndef LEETCODE_H
#define LEETCODE_H

// NOTE: make some helper to read desire data
// #define READ_LINKED_LIST
// #define READ_BT
// #define READ_STRING
/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  struct ListNode *next;
};


int* parse_array(const char* str, int* size) {
    int* array = NULL;
    int count = 0;
    const char* p = str;

    while (*p) {
        if (*p >= '0' && *p <= '9') {
            array = realloc(array, (count + 1) * sizeof(array));
            array[count++] = strtol(p, (char**)&p, 10);
        } else {
            p++;
        }
    }

    *size = count;
    return array;
}

long long* parse_array_ll(const char* str, int* size) {
    long long* array = NULL;
    int count = 0;
    const char* p = str;

    while (*p) {
        if (*p >= '0' && *p <= '9') {
            array = realloc(array, (count + 1) * sizeof(array));
            array[count++] = strtoll(p, (char**)&p, 10);
        } else {
            p++;
        }
    }

    *size = count;
    return array;
}

#endif
