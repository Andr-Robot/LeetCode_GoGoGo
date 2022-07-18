/*
 * Author: robot
 * Source : https://leetcode.cn/problems/merge-k-sorted-lists/
 */
#include <iostream>
#include <vector>
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

// 合并K个升序链表
// 归并法，先两两合并，然后在继续直到剩下最后一个
class Solution {
   private:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        ListNode* head_a = a;
        ListNode* head_b = b;
        while (head_a != nullptr && head_b != nullptr) {
            if (head_a->val < head_b->val) {
                cur->next = head_a;
                head_a = head_a->next;
            } else {
                cur->next = head_b;
                head_b = head_b->next;
            }
            cur = cur->next;
        }
        if (head_a != nullptr) {
            cur->next = head_a;
        } else {
            cur->next = head_b;
        }
        return head->next;
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        ListNode* merge1 = merge(lists, left, mid);
        ListNode* merge2 = merge(lists, mid + 1, right);
        return mergeTwoLists(merge1, merge2);
    }

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        return merge(lists, 0, lists.size() - 1);
    }
};