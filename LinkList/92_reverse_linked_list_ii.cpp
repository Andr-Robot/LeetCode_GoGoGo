/*
 * Author: robot
 * Source : https://leetcode.cn/problems/reverse-linked-list-ii/
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
    // 将链表分成3部分，第一部分是翻转前的，第二部分是翻转的，第三部分是翻转后的
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* new_head = new ListNode(-999);
        new_head->next = head;
        ListNode* cur = head;
        ListNode* p1_end = new_head; // 这个是用来记录翻转前的最后一个节点，方便后续拼接
        bool find = false;
        int index = 0;
        // 找到left node，并记录前一节链表的尾部p1_end
        while (cur != nullptr) {
            index++;
            if (index == left) {
                find = true;
                break;
            }
            p1_end = cur;
            cur = cur->next;
        }
        if (!find) return head;
        // 当找到left，则进行翻转
        ListNode* pre = nullptr;
        while (cur != nullptr && index <= right) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
            index++;
        }
        // 将3部分重新拼接生成新的链表
        p1_end->next->next = cur;
        p1_end->next = pre;
        return new_head->next;
    }
};