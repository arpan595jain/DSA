class Solution {
public:
    int minimumLength(string s) {
        map<int, int>mp;
        
        for(auto it:s){
            mp[it]++;
        }
        
        int ans = 0;
        for(auto it:mp){
            ans+=((it.second+1)%2)+1;
        }
        return ans;
    }
};
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}
();
