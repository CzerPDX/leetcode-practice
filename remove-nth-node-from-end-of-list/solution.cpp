#include "solution.h"

#include <iostream>

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
  ListNode* endNode = head;
  int count = 1;  // count is 1-indexed for this algorithm
  ListNode* nodeToDelete = head;
  ListNode* prevToDelete = head;

  // Drag a secondary pointer n spaces behind endNode
  // Also drag a pointer to the one previous to that.
  while (endNode->next != nullptr) {
    endNode = endNode->next;

    if (count >= n) {
      nodeToDelete = nodeToDelete->next;
    }
    if (count >= (n + 1)) {
      prevToDelete = prevToDelete->next;
    }
    count++;
  }
  
  if (nodeToDelete == head) {
    head = head->next;
  } else {
    prevToDelete->next = nodeToDelete->next;
    delete nodeToDelete;
  }

  return head;
}

ListOfNodes::ListOfNodes(int nums[], int size) {
  head = nullptr;
  this->size = size;
  if (this->size > 0) {
    head = new ListNode(nums[0]);
    ListNode *prev = head;

    for (int i = 1; i < size; i++) {
      ListNode *newNode = new ListNode(nums[i]);
      prev->next = newNode;
      prev = newNode;
    }
  }
}

ListOfNodes::~ListOfNodes() {
  if (head) {
    ListNode *nodeToDelete;
    while (head) {
      nodeToDelete = head;
      head = head->next;
      delete nodeToDelete;
    }
  }
}