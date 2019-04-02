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
思路：建栈，如果每次碰到开括号（ie. '(','{','['）则入栈，每次遇到闭括号（ie. ')',']','}'）首先判断栈是否为空，为空则肯定
不匹配，若非空则判断栈顶元素是否为对应的开括号，是则栈顶元素出栈，否则返回false。所有元素都遍历完后看栈是否为空，非空说明
还有元素未匹配，返回false。可使用map结构，也可以每次遇到闭括号的时候判断栈顶元素是否等于对应开括号。
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
