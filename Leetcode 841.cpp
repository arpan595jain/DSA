class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        vector<bool> v(rooms.size(),false);
        while(!q.empty()){
            int p=q.front();
            v[p]=true;
            for(int i=0;i<rooms[p].size();i++){
                if(v[rooms[p][i]]==false)
                    q.push(rooms[p][i]);
            }
            q.pop();
        }
        for(int i=0;i<v.size();i++){
            if(!v[i]){
                return false;
            }
        }
        return true;
    }
};
