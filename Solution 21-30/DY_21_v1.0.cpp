/*
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list
should be made by splicing together the nodes of the first two lists.
*/

//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Merge Two Sorted Lists.
//Memory Usage: 9.2 MB, less than 99.03% of C++ online submissions for Merge Two Sorted Lists.
//˼·���͹鲢�����˼·һ�����Ƚ�2���������Сֵ��ȡ��С�ķ����µ������У�ֱ������һ��Ϊ���ٽ�
//��һ�������ֵ��������µ������С�
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l = new ListNode(0);
        ListNode* result = l;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                l->next = new ListNode(l1->val);
                l1 = l1->next;
                l = l->next;
            }
            else {
                l->next = new ListNode(l2->val);
                l2 = l2->next;
                l = l->next;
            }
        }
        while (l1 != NULL) {
            l->next = new ListNode(l1->val);
            l1 = l1->next;
            l = l->next;
        }
        while (l2 != NULL) {
            l->next = new ListNode(l2->val);
            l2 = l2->next;
            l = l->next;
        }
        return result->next;
    }
};
