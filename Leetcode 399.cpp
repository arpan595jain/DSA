class Solution {
    unordered_map<string,int>m;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& times, vector<vector<string>>& queries) {
        int n=equations.size(),j=0;
        for(int i=0;i<n;i++){
            if(m.find(equations[i][0])==m.end()){
                m[equations[i][0]]=j;
                j++;
            }
            if(m.find(equations[i][1])==m.end()){
                m[equations[i][1]]=j;
                j++;
            }
        }
        // vector<pair<int,double>>adj[j];
        vector<vector<double>>graph(j,vector<double>(j,1e9+7));
        for(int i=0;i<n;i++){
            int a=m[equations[i][0]],b=m[equations[i][1]];
            graph[a][b]=times[i];
            graph[b][a]=1/times[i];
        }
        n=j;
        vector<double>res;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        graph[i][j]=1;
                        continue;
                    }
                    if(graph[i][k]!=1e9+7&&graph[k][j]!=1e9+7){
                        graph[i][j]=graph[i][k]*graph[k][j];
                    }
                }
            }
        }
        n=queries.size();
        // vector<res>double;
        for(int i=0;i<n;i++){
            if(m.find(queries[i][0])==m.end()||m.find(queries[i][1])==m.end()){
                res.push_back(-1);
                continue;
            }
            if(graph[m[queries[i][0]]][m[queries[i][1]]]==1e9+7){
                res.push_back(-1);
            }
            else{
                res.push_back(graph[m[queries[i][0]]][m[queries[i][1]]]);
            }
        }
        return res;
    }
};
