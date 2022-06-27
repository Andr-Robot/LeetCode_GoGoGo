/*
 * Author: robot
 * Source : https://leetcode.cn/problems/swap-nodes-in-pairs/
 */
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    // 维持3个指针，进行相邻节点的调换
    ListNode* swapPairs(ListNode* head) {
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* cur = new_head;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* t1 = cur->next;
            ListNode* t2 = cur->next->next;
            ListNode* tmp = t2->next;
            t2->next = t1;
            t1->next = tmp;
            cur->next = t2;
            cur = t1;
        }
        return new_head->next;
    }
};