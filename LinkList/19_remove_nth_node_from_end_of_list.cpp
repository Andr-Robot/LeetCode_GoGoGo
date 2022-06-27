/*
 * Author: robot
 * Source : https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
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
    // 方法1：两次遍历，第一次确定链表长度找到删除的位置，第二次遍历完成删除
    // 方法2：一次遍历，使用两个指针，第一个指针先走n步，然后两个指针一起移动，
    //       这样当指针1到达尾部的时候可以保证指针2刚好在需要删除的那个元素的前一个元素
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto ptr1 = head;
        auto ptr2 = head;
        while (n > 0) {
            ptr1 = ptr1->next;
            n--;
        }
        // 为了处理删除的是head的时候
        if (ptr1 == nullptr) {
            auto newhead = head->next;
            return newhead;
        }
        while (ptr1->next != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr2->next->next;
        return head;
    }
};