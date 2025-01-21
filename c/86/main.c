#include "../include/leetcode.h"

struct ListNode *partition(struct ListNode *head, int x) {
  struct ListNode lessDummy = {0, NULL};
  struct ListNode greaterDummy = {0, NULL};
  struct ListNode *less = &lessDummy;
  struct ListNode *greater = &greaterDummy;
  printf("partitioning\n");
  while (head != NULL) {
    if (head->val < x) {
      less->next = head;
      less = less->next;
    } else {
      greater->next = head;
      greater = greater->next;
    }
    head = head->next;
  }
  greater->next = NULL;
  less->next = greaterDummy.next;
  return lessDummy.next;
}

int main() {
  printf("Hello\n");
  int arr[] = {1, 4, 3, 2, 5, 2};
  int expect[] = {1, 2, 2, 4, 3, 5};
  struct ListNode l;
  struct ListNode *c = &l;
  for (int i = 0; i < 6; i++) {
    c->val = arr[i];
    struct ListNode n = {0, NULL};
    c->next = &n;
    c = c->next;
  }
  struct ListNode *out = partition(&l, 3);
  printf("partitioned\n");
  c = out;
  int i = 0;
  while (c != NULL) {
    assert(c->val == expect[i++]);
    c = c->next;
  }

  return 0;
}
