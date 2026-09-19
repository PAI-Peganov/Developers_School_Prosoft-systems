#include <vector>


using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long i = 1, s = 0, j = 0, b = 0;
        int answer = 0;
        while (i <= n) {
            while (j < nums.size()) {
                if (nums[j] <= i) { s += nums[j]; ++j; }
                else break;
            }
            if (s < i) {
                ++answer;
                s += i;
                i = s;
            } else {
                ++i;
            }
        }
        return answer;
    }
};