#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int deep(string& s, vector<vector<int>>& dp, int l, int r) {
        if (r < l) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        dp[l][r] = deep(s, dp, l + 1, r) + 1;
        for (int x = l + 1; x <= r; ++x) {
            if (s[l] == s[x]) {
                dp[l][r] = min(dp[l][r], deep(s, dp, l, x - 1) + deep(s, dp, x + 1, r));
            }
        }
        return dp[l][r];
    }
public:
    int strangePrinter(string s) {
        string ls;
        ls.push_back(s[0]);
        for (char& el : s) if (ls.back() != el) ls.push_back(el);
        int n = ls.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return deep(ls, dp, 0, n - 1);
    }
};