class DSU{
  public:
    vector<int> rank,par;
    DSU(int n){
        rank.resize(n+1);par.resize(n+1);
        for(int i=0;i<=n;i++){rank[i]=1;par[i]=i;}
    }
    int find_par(int x){
        if(x==par[x]){return x;}
        return par[x]=find_par(par[x]);
    }
    void union_by_rank(int x,int y){
        int a=find_par(x),b=find_par(y);
        if(a==b){return ;}
        
        if(rank[a]>rank[b]){
            // rank[a]+=rank[b];
            par[b]=a;
        }else if(rank[a]<rank[b]){
            // rank[b]+=rank[a];
            par[a]=b;
        }else{
            rank[a]++;
            par[b]=a;
        }
    }
};
class Solution {
public:
    using ll = long long;
    bool canReachCorner(int x, int y, vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<bool>> to(n);
        
        for(int i=0;i<n;i++)
        {
            bool u=0,d=0,r=0,l=0;
            int cx=v[i][0],cy=v[i][1],cr=v[i][2];
            
            //up
            if((cy+cr)>=y){u|=true;}
            //down
            if((cy-cr)<=0){d|=true;}
            //left
            if((cx-cr)<=0){l|=true;}
            //right
            if((cx+cr)>=x){r|=true;}
            
            if(u and r||l and d||u and d||r and l){return false;}
            to[i]={u,l,r,d};
        }
        
        DSU ds(n);
        for(int i=0;i<n;i++)
        {
            ll x1=v[i][0],y1=v[i][1],r1=v[i][2];
            for(int j=i+1;j<n;j++)
            {
                int a=ds.find_par(i),b=ds.find_par(j);
                ll x2=v[j][0],y2=v[j][1],r2=v[j][2];
                ll dis = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                ll rad=(r1+r2)*(r1+r2);
                
                if(dis<=rad){
                    if(a!=b){
                        ds.union_by_rank(a,b);
                        for(int k=0;k<4;k++)
                        {
                            to[a][k]=(to[b][k] or to[a][k]);
                        }
                    }
                }
                
            }
        }
        
        for(int i=0;i<n;i++)
        {
            bool u=to[i][0],d=to[i][3],r=to[i][2],l=to[i][1];
            if(u and r||l and d||u and d||r and l){return false;}
        }
       
        
        return true;
    }
};
