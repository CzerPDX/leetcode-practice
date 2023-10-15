/*
  From Leetcode:
  https://leetcode.com/problems/merge-two-sorted-lists/

  Merge Two Sorted Lists
  You are given the heads of two sorted linked lists list1 and list2.

  Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

  Return the head of the merged linked list.


  Example 1:


  Input: list1 = [1,2,4], list2 = [1,3,4]
  Output: [1,1,2,3,4,4]
  Example 2:

  Input: list1 = [], list2 = []
  Output: []
  Example 3:

  Input: list1 = [], list2 = [0]
  Output: [0]
  

  Constraints:

  The number of nodes in both lists is in the range [0, 50].
  -100 <= Node.val <= 100
  Both list1 and list2 are sorted in non-decreasing order.
*/

#include "solution.h"

#include <iostream>
#include <string>

// Would not usually define the printing outside of the LLL but due to the leetcode setup I am
void printLLL(ListNode *head) {
  ListNode *curr = head;
  while (curr) {
    std::cout << curr->val << " ";
    curr = curr->next;
  }
  std::cout << std::endl;
}


int main(int argc, char *argv[]) {
  Solution aSolution;

  int arr1[] = {1,2,4};
  int arr2[] = {1,3,4};
  LLL aList1(arr1);
  LLL aList2(arr2);
  printLLL(aSolution.mergeTwoLists(aList1.head, aList2.head));

  
  printLLL(aSolution.mergeTwoLists(nullptr, nullptr));

  int arr3[] = {0};
  LLL aList3(arr3);
  printLLL(aSolution.mergeTwoLists(nullptr, aList3.head));

  return 0;
}