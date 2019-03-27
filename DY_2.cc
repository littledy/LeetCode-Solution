//˼·������һ��ListNode���󱣴�����Ȼ�󴴽�һ��List*���͵�ָ��ָ�����
//���ý�λ�����l1��l2��һ���ǿջ��߽�λ��Ϊ0����������㣻
//ÿ�ζ�Ӧλ��ӣ�����Ϊ0��������Ľ����ŵ��½ڵ��У���󷵻�ͷָ�뼴��

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0);    //��������������
        ListNode* p = &result;  //ָ��pָ��result�����ã�ͨ���޸�pָ���ֵ�޸�result
        int carry = 0;      //��λ
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry + (l1==nullptr ? 0:l1->val) + (l2==nullptr ? 0:l2->val);
            carry = sum / 10;   //���²�����λ
            sum %= 10;
            p->next = new ListNode(sum);    //�����½ڵ㴢��l1��l2��Ӧ����ӽ�λ���ֵ
            p = p->next;    //pָ����һ���ڵ�
            l1 = (l1==nullptr ? 0:l1->next);
            l2 = (l2==nullptr ? 0:l2->next);
            /*if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;*/
        }
        return result.next;		//����ͷ��㣬���ȫ���ڵ�ֵ
		//���� p = result.next; return p;
    }
};
