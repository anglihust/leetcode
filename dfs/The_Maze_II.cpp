//dfs TLE
class Solution {
public:
    vector<pair<int,int>> dir;
    int M,N;
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<pair<int,int>> temp ={{0,1},{0,-1},{1,0},{-1,0}};
        dir.swap(temp);
        M=maze.size();
        N=maze[0].size();
        vector<vector<int>> dist(M,vector<int>(N,INT_MAX));
        dist[start[0]][start[1]] = 0;
        dfs(maze, start,destination,dist);
        return dist[destination[0]][destination[1]]==INT_MAX ? -1 : dist[destination[0]][destination[1]];
    }
    
    void dfs(vector<vector<int>> maze, vector<int> start,vector<int> destination,vector<vector<int>>& dist){
        if(start==destination) return;
        for(int i=0;i<4;i++){
            int cur_x = start[0];
            int cur_y = start[1];
            int dir_x = dir[i].first;
            int dir_y =dir[i].second;
            int local_dist = 0;
            while(cur_x+dir_x>=0 and cur_x+dir_x<M and cur_y+dir_y>=0 and cur_y+dir_y<N and !maze[cur_x+dir_x][cur_y+dir_y]){
                cur_x+= dir_x;
                cur_y+= dir_y;
                local_dist++;
            }
            if(local_dist+dist[start[0]][start[1]]<dist[cur_x][cur_y]){
                dist[cur_x][cur_y]=local_dist+dist[start[0]][start[1]];
                dfs(maze,{cur_x,cur_y},destination,dist);
            }    
        }
    }
};
