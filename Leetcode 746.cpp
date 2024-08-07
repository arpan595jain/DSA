class Solution {
public:
int dp[2000];
int f(int i,int n,vector<int>& c)
{
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=1e9;
    ans=c[n-1-i]+min(f(i-1,n,c),f(i-2,n,c));
    return dp[i]=ans;
}
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        int n=cost.size();
        return min(f(n-1,n,cost),f(n-2,n,cost));
    }
};
