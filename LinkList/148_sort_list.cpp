/*
 * Author: robot
 * Source : https://leetcode.cn/problems/sort-list/
 */
#include <iostream>
#include <vector>
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

/**
 * @brief 排序链表
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 */
class Solution {
   public:
    // 归并排序，自顶向下
    // 时间复杂度: O(nlogn)
    // 空间复杂度: O(logn)
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
    /**
     * @brief 对原链表进行分割
     * 
     * @param start 
     * @param end 
     * @return ListNode* 
     */
    ListNode* sortList(ListNode* start, ListNode* end) {
        if (start == nullptr) return start;
        if (start->next == end) {
            start->next = nullptr;
            return start;
        }
        // 使用快慢指针寻找mid节点
        ListNode* slow = start;
        ListNode* fast = start;
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 当遇到的是偶数节点时，这里找到的mid节点并不是严格意义上的中间节点，而是中间节点的下一个节点
        ListNode* mid = slow;
        // 这里需要考虑首位指针的位置
        return merge(sortList(start, mid), sortList(mid, end));
    }
    /**
     * @brief 按大小顺序合并两个链表
     * 
     * @param head1 
     * @param head2 
     * @return ListNode* 
     */
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* new_head = new ListNode(-1);
        ListNode* pre = new_head;
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                pre->next = p1;
                p1 = p1->next;
            } else {
                pre->next = p2;
                p2 = p2->next;
            }
            pre = pre->next;
        }
        if (p1 != nullptr) {
            pre->next = p1;
        }
        if (p2 != nullptr) {
            pre->next = p2;
        }
        return new_head->next;
    }
    // 归并排序，自底向上
    // 先1 1合并，再2 2 合并，然后4 4合并，直到完成整个长度的合并
    // 时间复杂度: O(nlogn)
    // 空间复杂度: O(1)
    ListNode* sortList_v2(ListNode* head) {
        if (head == nullptr) return nullptr;
        // 统计链表长度
        int length = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            length++;
        }
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        for (int sub_len = 1; sub_len < length; sub_len = sub_len * 2) {
            ListNode* pre = new_head;
            ListNode* cur = new_head->next;
            while (cur != nullptr) {
                ListNode* head1 = cur;
                int t = sub_len - 1;
                while (cur != nullptr && cur->next != nullptr && t > 0) {
                    t--;
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = nullptr;  // 将前半部分和后半部分断开连接，方便后面的merge
                cur = head2;
                t = sub_len - 1;
                while (cur != nullptr && cur->next != nullptr && t > 0) {
                    t--;
                    cur = cur->next;
                }
                // 断开第二个链表和后面的连接
                ListNode* nxt = nullptr;
                if (cur != nullptr) {
                    nxt = cur->next;
                    cur->next = nullptr;
                }
                ListNode* merge_node = merge(head1, head2);
                pre->next = merge_node;
                // 移动pre指针到合并后的地方
                while (pre->next != nullptr) {
                    pre = pre->next;
                }
                // 更新下一步合并的起点
                cur = nxt;
            }
        }
        return new_head->next;
    }
};