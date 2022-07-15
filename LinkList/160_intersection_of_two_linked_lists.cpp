/*
 * Author: robot
 * Source : https://leetcode.cn/problems/intersection-of-two-linked-lists/
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
    // 使用双指针进行遍历
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1->next != NULL && p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        int cnt = 0;
        // 调整起始搜索的位置
        if (p1->next == NULL) {
            // headB对应的链表更长
            while (p2->next != NULL) {
                p2 = p2->next;
                cnt++;
            }
            p1 = headA;
            p2 = headB;
            while (cnt > 0) {
                p2 = p2->next;
                cnt--;
            }
        } else {
            // headA对应的链表更长
            while (p1->next != NULL) {
                p1 = p1->next;
                cnt++;
            }
            p1 = headA;
            p2 = headB;
            while (cnt > 0) {
                p1 = p1->next;
                cnt--;
            }
        }
        // 此时p1和p2到链表尾部的步长是一样的
        while (p1 != NULL && p2 != NULL) {
            if (p1 == p2) {
                return p1;
            } else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return NULL;
    }
    // 使用双指针进行遍历 v2
    ListNode* getIntersectionNode_v2(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != p2) {
            p1 = p1 == NULL ? headB : p1->next;
            p2 = p2 == NULL ? headA : p2->next;
        }
        return p1;
    }
};