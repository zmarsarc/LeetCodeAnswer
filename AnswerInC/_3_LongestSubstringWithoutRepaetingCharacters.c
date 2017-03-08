/*
    基本思路是一个回溯的搜索算法
    使用一张表来保存当前字符搜索历史中出现的情况
    效率最大的障碍是两个：
        每次搜索最大串失败时，都要进行回溯
        每次回溯发生时都要清空历史记录表
    由于表的大小固定，清空表的开销可以视为一个常数
    所以主要的开销来自回溯
    优化思路是通过全面了解串的结构来避免回溯
    类似 KMP 算法中提前对串进行扫描
*/

/*
    正确率 100%
    983 组 Sample 用时 42ms
    在 C 提交中排名前 76.55%
*/

#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int curent = 0;
    int last = 0;
    char table[128];
    int len = 0;

    while (s[curent] != '\0') {
        for (int i = 0; i < 128; i++) {
            table[i] = 0;
        }

        for (int pos; s[curent] != '\0'; curent++) {
            pos = (unsigned int)s[curent];
            if (table[pos] != 0) break;
            table[pos] = 1;
        }
        int this_len = curent - last;
        len = (this_len > len) ? this_len : len;
        curent = last = last + 1;
    }
    return len;
}