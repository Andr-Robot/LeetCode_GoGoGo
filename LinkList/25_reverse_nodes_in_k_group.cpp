/*
 * Author: robot
 * Source : https://leetcode.cn/problems/reverse-nodes-in-k-group/
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

class Solution {
   private:
    // 将一定范围内的链表翻转，并返回新的首位节点指针
    vector<ListNode*> reverseSubLinkedList(ListNode* head, ListNode* tail) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        // 提前保存终止标识符
        ListNode* end_node = tail->next;
        while (cur != end_node) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        // 下面这种翻转的方式也可以达到效果
        // ListNode* pre = tail->next;
        // ListNode* p = head;
        // while (pre != tail) {
        //     ListNode* nxt = p->next;
        //     p->next = pre;
        //     pre = p;
        //     p = nxt;
        // }
        return {tail, head};
    }

   public:
    // 可以将本题拆解为长度为k的子链表的翻转
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* pre = new_head;

        while (head != nullptr) {
            // 遍历k个节点，找到尾部
            ListNode* tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (tail == nullptr) {
                    // 不足k个，则不需要翻转
                    return new_head->next;
                }
            }
            ListNode* nxt_node = tail->next;
            // 翻转子链表
            vector<ListNode*> sub_end_node = reverseSubLinkedList(head, tail);
            // 将翻转后的子链表原拼接回去
            pre->next = sub_end_node[0];
            sub_end_node[1]->next = nxt_node;
            pre = sub_end_node[1];
            head = sub_end_node[1]->next;
        }
        return new_head->next;
    }
};