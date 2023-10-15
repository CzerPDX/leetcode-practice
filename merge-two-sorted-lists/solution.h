#ifndef SOLUTION_H
#define SOLUTION_H

#include <cstddef>  // Used for size_t
#include <iostream>

// Definition for singly-linked list.
 struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LLL {
public:
  ListNode *head = nullptr;

  template <size_t N>
  // I am including the definition for the constructor in the header because I am using the size_t 
  // template and method that use templates need to be defined in the header for the compiler
  LLL(int (&sortedIntArray)[N]) {
    int sortedIntArraySize = sizeof(sortedIntArray)/sizeof(sortedIntArray[0]);
    ListNode *prev = nullptr;
    ListNode *newNode = nullptr;

    for (int i = 0; i < sortedIntArraySize; i++) {
      newNode = new ListNode(sortedIntArray[i]);
      // If previous is not nullptr then we aren't at the head
      if (prev) {
        prev->next = newNode;
      } 
      // Otherwise we are at the head of the list so set the head to the newNode
      else {
        head = newNode;
      }
      
      prev = newNode;
    }
  };
  
  // Even though the destructor doesn't need to use templates and therefore doesn't need to be defined in the header,
  // I prefer to keep the constructor and destructor in the same place, so I am defining the destructor here since the
  // constructor must be declared in the header file due to size_t usage.
  ~LLL() {
    ListNode *nodeToDelete = nullptr;
    while (head) {
      nodeToDelete = head;
      head = head->next;
      delete nodeToDelete;
    }
  }
};


class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};



#endif