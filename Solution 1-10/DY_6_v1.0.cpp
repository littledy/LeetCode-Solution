//6. ZigZag Conversion
//Runtime: 20 ms, faster than 94.23% of C++ online submissions for ZigZag Conversion.
//Memory Usage: 12.8 MB, less than 99.14% of C++ online submissions for ZigZag Conversion.
//将每行对应的字符存入vector对应的行中，若在首行或为行则上/下行方向改变
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)   return s;
        vector<string> rows(min(numRows,int(s.size())));
        int current_row = 0;
        bool down = false;

        for (auto c:s) {
            rows[current_row] += c;
            if (current_row==0 || current_row == numRows-1) down = !down;
            current_row += down?1:-1;
        }

        string s1;
        for (auto c:rows)
            s1 += c;
        return s1;
    }
};
