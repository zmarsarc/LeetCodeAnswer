/*
    直接了当的思路
    首先对空格和前缀进行处理
    然后进行转换
    空间复杂度 O(1)， 原地算法
    时间复杂度 O(n)
*/

// 1047/1247 AC // 12ms // top 7.84% !! in cpp // 基本和最快的 C 实现一样快了

#include <cctype>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int sign = 1;
		int num = 0;
		bool is_prepare = true;
		int max = numeric_limits<int>::max();
		int min = numeric_limits<int>::min();
		for (auto it = str.begin(); it != str.end(); ++it) {
			if (is_prepare) {
				switch (*it) {
				case '-':
					sign = -1;
				case '+':
					is_prepare = false;
					*it = '0';
				case ' ':
					break;
				default:
					if (isdigit(*it)) {
						is_prepare = false;
						break;
					}
					else {
						return 0;
					}
				}
				if (is_prepare) continue;
			}

			if (!isdigit(*it)) break;

			if (num >= 0 && num > max / 10) {
				return max;
			}
			else if (num < 0 && num < min / 10) {
				return min;
			}
			num *= 10;
			num += sign * static_cast<int>(*it - '0');
			if (sign * num < 0) return (sign < 0) ? min : max;
		}
		return num;
	}
};
