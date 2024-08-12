class Solution {
public:
    int func(vector<vector<int>>&dp, vector<int>&v, int ind, bool flg, int fee){
        int n=v.size();
        if(ind==n) return 0;
        if(dp[ind][flg]!=-1) return dp[ind][flg];

        int ans=0;

        if(flg){
            int take= -v[ind] + func(dp,v,ind+1, 0,fee);
            int ntake= func(dp,v,ind+1, 1,fee);
            ans=max(take,ntake);

        }
        else{
            int take= v[ind] + func(dp,v,ind+1, 1, fee) - fee;
            int ntake= func(dp,v,ind+1, 0,fee);
            ans=max(take,ntake);

        }
        return dp[ind][flg]=ans;

    }

    int maxProfit(vector<int>& v, int fee) {
        int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return func(dp,v,0,1,fee);

    }
};
