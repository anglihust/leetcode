// recursion + memorization 
// https://www.youtube.com/watch?v=xJ1Rc30Pyes

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        vector<vector<int>> dp(len,vector<int>(len,0));
        for(int i = 0; i<len;i++) dp[i][i] = piles[i];
        for(int n=2;n<=len;n++){
            for(int i=0;i<len-n+1;i++){
                int j =i+n-1;
                dp[i][j] = max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
            }
        }
        return dp[0][len-1]>0;
    }
};
