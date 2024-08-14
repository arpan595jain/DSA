class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int>ans(n+1,0);
        for(int i=0;i<=n;++i){
         ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
