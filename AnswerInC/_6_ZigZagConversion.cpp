/*
    所见即所得的直白方案
*/

// 1158/1158 AC // 32ms // top 58.7 % in cpp

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.empty()) return s;

        vector<string> strings;
        for (decltype(numRows) i = 0; i < numRows; ++i) {
            strings.push_back(string());
        }

        int step = 1;
        int curent = 0;
        for (auto c: s) {
            strings[curent].push_back(c);
            curent += step;
            if (curent == 0 || curent == numRows - 1) step *= -1;
        }

        string zigzag;
        for (auto s : strings) zigzag += s;
        return zigzag;
    }
};
