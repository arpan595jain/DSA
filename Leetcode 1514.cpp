class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,float>>> ans(n);
        for(int i=0;i<edges.size();i++){
            ans[edges[i][0]].emplace_back( edges[i][1] ,succProb[i]);
            ans[edges[i][1]].emplace_back( edges[i][0] ,succProb[i]);
        }
        
        //Floyd Warshall Algorithm ---> TLE
        // for(int k=0;k<n;k++){
        //     for(int i=0;i<n;i++){
        //         for(int j=0;j<n;j++){
        //             if(ans[i][k]!=0 && ans[k][j]!=0)
        //                 ans[i][j]=max(ans[i][j],ans[i][k]*ans[k][j]);
        //         }
        //     }
        // }

       
        return dijkastra(ans,start,n,end);
        // return 0;
       
    }
    //dijkastra Algorithm
    float dijkastra(vector<vector<pair<int,float>>>&edges,int s,int n,int end){
        vector<float> dist(n,0.000);

        dist[s]=1;
        priority_queue<pair<int,float>> q;
        q.push({s,1});

        while(!q.empty()){
            int node=q.top().first;
            float distance=q.top().second;
            q.pop();

            for(auto it:edges[node]){
                auto [adj,weight]=it;
                if(weight*distance>dist[adj]){
                   
                    dist[adj]=weight*distance;
                    q.push({adj,weight*distance});
                }
            }
        }

        return dist[end];
    }
};
