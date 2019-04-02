/*
20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Note that an empty string is also considered valid.
*/

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
//Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Valid Parentheses.
/*
˼·����ջ�����ÿ�����������ţ�ie. '(','{','['������ջ��ÿ�����������ţ�ie. ')',']','}'�������ж�ջ�Ƿ�Ϊ�գ�Ϊ����϶�
��ƥ�䣬���ǿ����ж�ջ��Ԫ���Ƿ�Ϊ��Ӧ�Ŀ����ţ�����ջ��Ԫ�س�ջ�����򷵻�false������Ԫ�ض��������ջ�Ƿ�Ϊ�գ��ǿ�˵��
����Ԫ��δƥ�䣬����false����ʹ��map�ṹ��Ҳ����ÿ�����������ŵ�ʱ���ж�ջ��Ԫ���Ƿ���ڶ�Ӧ�����š�
*/

class Solution {
public:
    bool isValid(string s) {
        map<char,char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';

        stack<char> aux;
        for (int i = 0; i < s.size(); i++) {
            if (s[i]=='(' || s[i]=='{' || s[i]=='[')
                aux.push(s[i]);
            else if (aux.empty() || m[aux.top()] != s[i])
                return false;
            else
                aux.pop();
        }
        return aux.empty();
    }
};
