//8. String to Integer (atoi)
//Runtime: 8 ms, faster than 99.90% of C++ online submissions for String to Integer (atoi).
//Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for String to Integer (atoi).
class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        bool negative = false;
        size_t index = str.find_first_not_of(' ');
        if (index == string::npos) return 0;
        if (str[index] == '-') {
            negative = true;
            index++;
        } else if (str[index] == '+') {
            index++;
        }
        for (int i=index; i < str.size(); i++) {
            if (isdigit(str[i])) {
                result = result*10 + (str[i] - '0');    //ASCII码差值即为str[i]数值
                if (negative && -result <= INT_MIN) return INT_MIN;
                if (!negative && result >= INT_MAX) return INT_MAX;
            } else
                break;
        }
        if (negative)   result = -result;
        return result;
    }
};
