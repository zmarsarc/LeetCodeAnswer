/*
    使用一个栈将每一位上的数入栈
    然后再出栈时乘以该位的指数
    如果出站后数字的符号与原数的符号不同则出现溢出
*/

// 1032/1032 AC // 16ms // top 29.54% in cpp // 还挺快的

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x > -10 && x < 10) return x;

        vector<int> temp;
        int sign = (x >= 0) ? 1 : -1;
        int result = 0;

        for (int num = x; x != 0; x /= 10) {
            temp.push_back(x % 10);
        }

        for (int i = 0, ret = 0; !temp.empty(); ++i) {
            ret += temp.back() * pow(10.0, i);
            if (sign * ret < 0) break;
            temp.pop_back();
            if (temp.empty()) {
                result = ret;
            }
        }
        return result;
    }
};
