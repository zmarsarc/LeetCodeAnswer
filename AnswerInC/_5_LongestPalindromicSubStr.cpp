/*
    基本思路是 DP
    优化思路是：

    如果一个串 S 中存在回文串 s，则其逆转串 S` 中一定存在子串 s` 使得 s = s`
    如此，可以将该问题转化为求两个串的最大公共子串问题，并且可以应用 KMP 算法
    该思路空间复杂度为 2n （逆转串和失配向量） 时间复杂度为 n + n
*/

/*
    DP 法求最长子回文串
    空间复杂度 2 * (n^2)
    时间复杂度 n^2
*/
// 83/94 / timeout

class Solution {
public:
    string longestPalindrome(string s) {
        auto len = s.length();
        if (len < 2) return s;
        bool dp_table[len][len];
        string longest = string();

        for (decltype(len) i = 0; i < len; i++) {
            for (decltype(len) j = i + 1; j < len; j++) {
                dp_table[i][j] = (s[i] == s[j]);
            }
        }

        for (decltype(len) i = 0; i < len; i++) {
            for (decltype(len) j =  i + 1; j < len; j++) {
                if (dp_table[i][j]) {
                    decltype(len) head, tail;
                    head = i;
                    tail = j;
                    string current = s.substr(head, tail - head + 1);
                    while (head < tail) {
                        if (!dp_table[head][tail]) {
                            current.clear();
                        }
                        head++;
                        tail--;
                    }
                    longest = (current.length() > longest.length()) ? current : longest;
                }
            }
        }

        if (longest.length() == 0) {
            for (decltype(len) i = 0; i < len; i++) {
                if (dp_table[i][i]) longest = s.substr(i, 1);
            }
        }
        return longest;
    }
};

/*
    优化的 DP 算法
    采用惰性求真值的方式，将两个循环压缩为一个
    并保存了首次匹配的位置
    空间复杂度 0
    时间复杂度 n^2
*/

// 94/94 ac / 472
class Solution {
public:
    string longestPalindrome(string s) {
        auto len = s.length();
        if (len < 2) return s;

        string longest = string();
        string current = string();
        decltype(len) first_match = 0;

        for (decltype(len) i = 0; i < len; i++) {
            for (decltype(len) j = i + 1; j < len; j++) {
                if (s[i] != s[j]) continue;
                if (!first_match) first_match = i;

                decltype(len) head, tail;
                head = i;
                tail = j;
                current = s.substr(head, tail - head + 1);
                while (head < tail) {
                    if (s[head] != s[tail]) {
                        current.clear();
                        break;
                    }
                    head++;
                    tail--;
                }
                longest = (current.length() > longest.length()) ? current : longest;
                if (longest.length() == len) return longest;
            }
        }

        return (longest.length()) ? longest: s.substr(first_match, 1);
    }
};