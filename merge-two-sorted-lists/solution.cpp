#include "solution.h"

#include <iostream>


ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode *retHead = nullptr;
  ListNode *currRetHead = nullptr;
  ListNode *currList1 = list1;
  ListNode *currList2 = list2;

  // First set up the head
  if ((currList1) && (currList2)) {
    if (currList1->val < currList2->val) {
      retHead = new ListNode(currList1->val);
      currList1 = currList1->next;
    } else {
      retHead = new ListNode(currList2->val);
      currList2 = currList2->next;
    }
  } else if (currList1) {
    retHead = new ListNode(currList1->val);
    currList1 = currList1->next;
  } else if (currList2) {
    retHead = new ListNode(currList2->val);
    currList2 = currList2->next;
  }
  
  currRetHead = retHead;

  // Zipper them together while there are still entries in both list1 and list2
  while ((currList1) && (currList2)) {
    if (currList1->val < currList2->val) {
      currRetHead->next = new ListNode(currList1->val);
      currList1 = currList1->next;
    } else {
      currRetHead->next = new ListNode(currList2->val);
      currList2 = currList2->next;
    }
    currRetHead = currRetHead->next;
  }

  // Take care of any remaining entries in either list1 or list2
  // They can just be tacked onto the end.
  while (currList1) {
    currRetHead->next = new ListNode(currList1->val);
    currList1 = currList1->next;
    currRetHead = currRetHead->next;
  }

  while (currList2) {
    currRetHead->next = new ListNode(currList2->val);
    currList2 = currList2->next;
    currRetHead = currRetHead->next;
  }

  return retHead;
}