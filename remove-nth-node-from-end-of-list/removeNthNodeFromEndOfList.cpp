/* 
  From Leetcode:
  https://leetcode.com/problems/remove-nth-node-from-end-of-list/

  Remove Nth Node From End of List:
  Given the head of a linked list, remove the nth node from the end of the list and return its head.

  Example 1:


  Input: head = [1,2,3,4,5], n = 2
  Output: [1,2,3,5]
  Example 2:

  Input: head = [1], n = 1
  Output: []
  Example 3:

  Input: head = [1,2], n = 1
  Output: [1]
  

  Constraints:

  The number of nodes in the list is sz.
  1 <= sz <= 30
  0 <= Node.val <= 100
  1 <= n <= sz
  

  Follow up: Could you do this in one pass?

*/

#include <iostream>
#include <string>

#include "solution.h"


void printListValuesBeforeAndAfter(ListNode *head, std::string beforeOrAfter) {
  std::cout << beforeOrAfter << ": ";
  ListNode *curr = head;
  while (curr) {
    std::cout << curr->val << " ";
    curr = curr->next;
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  Solution aSolution;

  int nums1[] = {1,2,3,4,5};
  ListOfNodes aList(nums1, 5);
  printListValuesBeforeAndAfter(aList.head, "Before");
  printListValuesBeforeAndAfter(aSolution.removeNthFromEnd(aList.head, 3), "After");

  int nums2[] = {1};
  ListOfNodes aList2(nums2, 1);
  printListValuesBeforeAndAfter(aList2.head, "Before");
  printListValuesBeforeAndAfter(aSolution.removeNthFromEnd(aList2.head, 1), "After");

  int nums3[] = {1,2};
  ListOfNodes aList3(nums3, 2);
  printListValuesBeforeAndAfter(aList3.head, "Before");
  printListValuesBeforeAndAfter(aSolution.removeNthFromEnd(aList3.head, 1), "After");

  return 0;
}