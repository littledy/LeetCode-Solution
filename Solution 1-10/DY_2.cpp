//思路：创建一个ListNode对象保存结果，然后创建一个List*类型的指针指向对象；
//设置进位，如果l1，l2有一个非空或者进位不为0则需继续计算；
//每次对应位相加，空则为0，将计算的结果存放到新节点中，最后返回头指针即可

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
        ListNode result(0);    //建立新链表储存结果
        ListNode* p = &result;  //指针p指向result的引用，通过修改p指向的值修改result
        int carry = 0;      //进位
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry + (l1==nullptr ? 0:l1->val) + (l2==nullptr ? 0:l2->val);
            carry = sum / 10;   //重新产生进位
            sum %= 10;
            p->next = new ListNode(sum);    //建立新节点储存l1和l2对应数相加进位后的值
            p = p->next;    //p指向下一个节点
            l1 = (l1==nullptr ? 0:l1->next);
            l2 = (l2==nullptr ? 0:l2->next);
            /*if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;*/
        }
        return result.next;		//返回头结点，输出全部节点值
		//或者 p = result.next; return p;
    }
};
