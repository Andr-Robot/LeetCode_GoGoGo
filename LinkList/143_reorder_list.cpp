/*
 * Author: robot
 * Source : https://leetcode.cn/problems/reorder-list/
 */
#include <iostream>
#include <stack>
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

// 重排链表
class Solution {
   public:
    // 时间复杂度:O(n)
    // 空间复杂度:O(n)
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* cur = head;
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->next;
        }
        cur = head;
        ListNode* top_node = st.top();
        while (cur->next != top_node && cur != top_node) {
            st.pop();
            ListNode* tmp = cur->next;
            cur->next = top_node;
            top_node->next = tmp;
            cur = tmp;
            top_node = st.top();
        }
        top_node->next = nullptr;
    }
    
    // 返回中间节点
    ListNode* findMid(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 翻转链表
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    // 合并链表
    void merge(ListNode* head1, ListNode* head2) {
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        while (p1 != nullptr && p2 != nullptr) {
            ListNode* tmp2 = p2->next;
            ListNode* tmp1 = p1->next;
            p1->next = p2;
            p2->next = tmp1;
            p1 = tmp1;
            p2 = tmp2;
        }
    }
    // 方法二：优化版
    // 1. 找到链表中间位置
    // 2. 从中间位置断开链表
    // 3. 翻转后半段链表
    // 4. 合并链表
    // 时间复杂度:O(n)
    // 空间复杂度:O(1)
    void reorderList_v2(ListNode* head) {
        if (head == nullptr) return;
        ListNode* mid_node = findMid(head);
        // 缓存后半段的头结点
        ListNode* other_half_head = mid_node->next;
        // 更新前半段的尾部
        mid_node->next = nullptr;
        ListNode* first_half_head = head;
        // 翻转后半段
        ListNode* new_half_head = reverseLinkedList(other_half_head);
        merge(first_half_head, new_half_head);
    }
};