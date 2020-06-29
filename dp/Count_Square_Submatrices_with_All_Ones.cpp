//TLE dp[i][j] the number of squares in [0:i][0:j]
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        vector<vector<int>> area(row+1,vector<int>(col+1,0));
        area_cal(matrix,area);
        for(int i = 1;i<=row;i++){
            for(int j= 1;j<=col;j++){
                int count = 0;
                int idi = i;
                int idj = j;
                while(idi>=1 and idj>=1){
                    if(area_sum(i,j,idi,idj,area)==(i-idi+1)*(j-idj+1)) count++;
                    idi--; idj--;
                }
                dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1]*count;
            }
        }
        return dp[row][col];
    }
    
    
    void area_cal(vector<vector<int>> matrix, vector<vector<int>> &area){
        int m = matrix.size();
        int n = matrix[0].size(); 
        for(int i = 1; i<=m ;i++){
            for(int j = 1; j<=n; j++){
                area[i][j] = area[i][j - 1] + area[i - 1][j] - area[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    
    int area_sum(int row1, int col1, int row2, int col2,vector<vector<int>> area){
        return area[row1][col1] - area[row2-1][col1] - area[row1][col2-1] + area[row2-1][col2-1];
    }
};


// correct dp[i][j] max edges of square in [0:i][0:j]
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1));
        int ans =0;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(matrix[i-1][j-1]==0) continue;
                dp[i][j] =min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})+1;
                // the number of squares containing i,j equal to the max edge
                //dp[i][j]= 3 has three squares 1, 2, 3
                ans+=dp[i][j];
            }  
        }
        return ans;
    }
};

