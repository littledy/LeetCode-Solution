//若x为负，则不可能为回文数，故只需考虑x为非负的情况
//将x的各位存入一个deque队列，然后首位比较，不相等则return，相等
//则pop出首尾元素继续比较，直到deque长为1或为空

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;


        //建立一个deque，可以双端操作
        deque <int> q;

        //将x的各位由低到高放入q
        while (x > 0)
        {
            q.push_back(x%10);
            x /= 10;
        }

        while (!q.empty())
        {
            if (q.size()<=1)
                return true;
            //比较首尾元素
            else if (q.front() != q.back())
                return false;
            else
            {
                q.pop_front();
                q.pop_back();
            }
        }
        //若q为空，则不进入while循环，需单独判断
        if (!q.empty()) return true;
        return true;
    }
};
