class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=0;
        for(int j=0;j<m&&i<n;j++){
            if(t[j]==s[i]){
                i++;
            }
        }
        return(i==n);
    }
};
