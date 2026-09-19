#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> arr(profits.size());
        for (int i = 0; i != profits.size(); ++i) {
            arr[i] = {capital[i], profits[i]};
        }
        sort(arr.begin(), arr.end());
        arr.push_back({INT_MAX, INT_MAX});
        priority_queue<int> heap;
        heap.push(0);
        int j = 0, answer = w, n = profits.size();
        for (int i = 0; i != k; ++i) {
            while (j < n && arr[j].first <= answer) {
                heap.push(arr[j++].second);
            }
            if (heap.top() < 1) {
                return answer;
            } else {
                answer += heap.top();
                heap.pop();
            }
        }
        return answer;
    }
};