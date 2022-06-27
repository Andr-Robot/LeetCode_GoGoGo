/*
 * Author: robot
 * Source : https://leetcode.cn/problems/remove-linked-list-elements/
 */
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        ListNode *cur = new_head;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return new_head->next;
    }
    ListNode *removeElements_v2(ListNode *head, int val) {
        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        ListNode *pre = new_head;
        ListNode *cur = head;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return new_head->next;
    }
};