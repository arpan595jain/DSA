class Solution {
public:
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int ans=-1, maxi=INT_MAX, chk=1;
		vector<vector<int>>v(maze.size(), vector<int>(maze[0].size(), 0));
		queue<pair<pair<int, int>, int>>q;
		q.push({{entrance[0], entrance[1]}, 0});
		v[entrance[0]][entrance[1]]=1;
		int flag=1;
		while(!q.empty()){
			int x=q.front().first.first, y=q.front().first.second, cnt=q.front().second;
			q.pop();
			if(flag==-1 && (x!=entrance[0] || y!=entrance[1]) && (x==0 || y==0 || x==maze.size()-1 || y==maze[0].size()-1)){maxi=min(maxi, cnt); chk=-1;}
			flag=-1;
			if(x>0 && !v[x-1][y] && maze[x-1][y]=='.'){
				v[x-1][y]=1;
				q.push({{x-1, y}, cnt+1});
			}
			if(y>0 && !v[x][y-1] && maze[x][y-1]=='.'){
				v[x][y-1]=1;
				q.push({{x, y-1}, cnt+1});
			}
			if(x<maze.size()-1 && !v[x+1][y] && maze[x+1][y]=='.'){
				v[x+1][y]=1;
				q.push({{x+1, y}, cnt+1});
			}
			if(y<maze[0].size()-1 && !v[x][y+1] && maze[x][y+1]=='.'){
				v[x][y+1]=1;
				q.push({{x, y+1}, cnt+1});
			}
		}
		if(chk==-1){return maxi;}
		return ans;
	}
};
