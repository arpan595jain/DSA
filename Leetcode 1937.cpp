class Solution {
public:
    int r, c;
    vector<vector<long long>> dp;
    long long f(int i, int j, vector<vector<int>>& points){
        if (i==0) return dp[i][j]=points[i][j];
        if (dp[i][j]!=-1) return dp[i][j];
        long long max_prev=0;
        for (int k=0; k<=j; k++)
            max_prev=max(max_prev, f(i-1, k, points)-(j-k));
        for (int k=j+1; k<c; k++)
            max_prev=max(max_prev, f(i-1, k, points)-(k-j));
        return dp[i][j]=max_prev+points[i][j];
    }
    long long maxPoints(vector<vector<int>>& points) {
        r=points.size(), c=points[0].size();
        dp.assign(r, vector<long long>(c, -1));
        long long ans=0;
        for (int j=0; j<c; j++)
            ans=max(ans, f(r-1, j, points));
        return ans;
    }
};
