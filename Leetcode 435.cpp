class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int ans = 0;
        vector<int> prev = intervals[0];
        for (auto i : intervals) {
            if (i[0] < prev[1]) ans++;
            else prev = i;
        }
        return ans - 1;
    }
};
