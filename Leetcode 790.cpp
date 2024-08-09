class Solution {
public:
    const int mod= 1e9 + 7;
    int dp[1001] = {};
    int numTilings(int n) {
         if(n <= 2)return n;
         if(n == 3)return 5;
         return dp[n]?dp[n]:dp[n] = ((numTilings(n-1)*2)%mod + (numTilings(n-3))%mod)%mod;
    }
};
