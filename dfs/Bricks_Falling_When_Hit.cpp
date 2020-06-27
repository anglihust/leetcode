// dfs to check whether the hits is connected to the first row
// erase is the dfs/bfs to remove connected bricks connected to the hits 
class Solution {
private:
    int visited[200][200];
    vector<vector<int>> g;
    vector<pair<int,int>> dir;
    int width, height;
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        g.swap(grid);
        dir.push_back({-1,0});
        dir.push_back({1,0});
        dir.push_back({0,-1});
        dir.push_back({0,1});
        width = g.size();
        height = g[0].size();
        vector<int> ans;
        int idx = 1;
        for(int i = 0;i<hits.size();i++){
            int remove_num = 0;
            int hitx = hits[i][0];
            int hity = hits[i][1];
            if(g[hitx][hity]==0){
                ans.push_back(0);
                continue;
            }
            g[hitx][hity]=0;
            for(int j=0;j<4;j++){
                int neighborx= hitx+ dir[j].first;
                int neighbory= hity+ dir[j].second;
                if(valid(neighborx,neighbory) and g[neighborx][neighbory]==1 and dfs(neighborx,neighbory,idx)) remove_num+= remove(neighborx,neighbory);
                idx++;
            }
            ans.push_back(remove_num);
        }
        return ans;
    }
    
    bool dfs(int x, int y, int idx){
        if(x==0) return false;
        visited[x][y] = idx;
        for(int i=0;i<4;i++){
            int newx = x+ dir[i].first;
            int newy = y+ dir[i].second;
            if(valid(newx,newy) and g[newx][newy]==1 and visited[newx][newy]!=idx){
                if(!dfs(newx,newy,idx)) return false;
            }
        }
        return true;
    }
    
    int remove(int x, int y){
        int res = 1;
        g[x][y] = 0;
        for(int i=0;i<4;i++){
            int newx = x+ dir[i].first;
            int newy = y+ dir[i].second;
            if(valid(newx,newy) and g[newx][newy]==1) res+=remove(newx, newy);
        }
        return res;
    }
    
    bool valid(int x, int y){
        return x>= 0 and x<width and y>=0 and y<height;
    }
};


    
