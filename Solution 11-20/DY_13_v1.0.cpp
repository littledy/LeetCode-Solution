/*13. Roman to Integer
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII,
which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle
applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.*/

//Runtime: 28 ms, faster than 96.33% of C++ online submissions for Roman to Integer.
//Memory Usage: 10.3 MB, less than 98.40% of C++ online submissions for Roman to Integer.
//思路：s每个字符跟后面一个比较，如果大于则加上当前字符对应值，小于则加上后面字符对应值-前面字符对应值

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> T = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int sum = 0;
        for (int i = 0; i < s.size(); i+=2) {
            if (i < s.size()-1 && T[s[i]] < T[s[i+1]]) sum += (T[s[i+1]] - T[s[i]]);
            else   { sum += T[s[i]]; i--; }
        }
        return sum;
    }
};
