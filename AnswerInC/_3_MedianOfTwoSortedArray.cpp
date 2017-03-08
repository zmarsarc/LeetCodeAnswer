/*
    思路：合并，排序，求中值
*/

/*
    AC / 2080 samples in 62ms / top 46.30% in cpp
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> numbers(nums1);
        for (auto it = nums2.begin(); it != nums2.end(); it++) {
            numbers.push_back(*it);
        }
        sort(numbers.begin(), numbers.end());

        double ret = 0.0;
        if (numbers.size() % 2 != 0) {
            ret = numbers[(numbers.size() - 1) / 2];
        } else {
            ret = (numbers[(numbers.size() - 1) / 2] + numbers[(numbers.size() - 1) / 2 + 1]) / 2.0;
        }
        return ret;
    }
};