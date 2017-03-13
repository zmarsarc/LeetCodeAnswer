/*
    正着看和反着看一样的数，那么只要反过来还和原来一样就是回文数了
*/

// 11507/11507 AC // 215ms // top 72.62% in cpp

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int tmp = x;
        int reverser = 0;
        while (tmp != 0) {
            reverser = reverser * 10 + (tmp % 10);
            tmp /= 10;
        }
        return reverser == x;
    }
};
