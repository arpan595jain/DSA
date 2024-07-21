class Solution {
public:
    void dfs(int x,vector<int>a[],vector<int>&vis)
    {
        for(auto i:a[x])
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                dfs(i,a,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=(isConnected[0]).size();
        vector<int>a[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j])
                {
                    a[j].push_back(i);
                    a[i].push_back(j);   
                 }
            }
        }
        
        int c=0;
        vector<int>vis(n);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                dfs(i,a,vis);
                c++;
            }
        }
        return c;
    }
};
