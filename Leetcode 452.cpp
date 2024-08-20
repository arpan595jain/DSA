class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0;
        int n =  points.size();

        sort(points.begin(), points.end());

        for(int i = 0; i < n; ) {
            int start = points[i][0];
            int end = points[i][1];

            int k = i + 1;
            while(k < n && (points[k][0] <= end && points[k][1] >= start)) {
                start = max(start, points[k][0]);
                end = min(end, points[k][1]);
                k++;
            }
            count++;
            i = k;
        }

        return count;
    }
};
