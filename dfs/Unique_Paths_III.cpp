//dfs
//go through all possible path and mark the visited position as -1
//the count number of zeros as judgement condition should be noted, in this code it should be count+1==0
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        int ans = 0,count=0;
        int curx,cury,tarx,tary;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) count++;
                if(grid[i][j]==1){
                    curx = i;
                    cury = j;
                }
                if(grid[i][j]==2){
                    tarx = i;
                    tary = j;
                }
            }
        }
        dfs(grid,dir,curx,cury,ans,count,tarx,tary);
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid,vector<pair<int,int>> dir, int curx, int cury, int &ans, int count,int tarx,int tary){
        if(curx<0 or curx>=grid.size() or cury<0 or cury>=grid[0].size() or grid[curx][cury]==-1) return;
        if(curx==tarx and cury==tary){
        if(count+1==0) ans++;
            return;
        } 
        grid[curx][cury]=-1;
        for(int i=0;i<4;i++){
            int nx =dir[i].first+curx;
            int ny =dir[i].second+cury;
            dfs(grid,dir,nx,ny,ans,count-1,tarx,tary);
        }
        grid[curx][cury]=0;
    }
};
