#pragma once

// Class definition from leetcode
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n);
};

class ListOfNodes {
public:
  ListNode *head;
  int size;

  ListOfNodes(int nums[], int size);
  ~ListOfNodes();
};
