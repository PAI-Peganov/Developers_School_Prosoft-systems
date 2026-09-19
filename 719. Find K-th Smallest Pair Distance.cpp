#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compute(vector<int>& nums, int max_dif) {
        int amount = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int l = i;
            int r = n;
            while (r - l > 1) {
                int m = (r + l) / 2;
                if (nums[m] - nums[i] < max_dif) {
                    l = m;
                } else {
                    r = m;
                }
            }
            amount += l - i;
        }
        return amount;
    }


    int smallestDistancePair(vector<int>& nums_raw, int k) {
        vector<int> nums = nums_raw;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.back() - nums[0] + 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            int cur = compute(nums, m);
            if (cur < k) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};