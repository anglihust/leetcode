class Solution {
public:
    int stoneGameII(vector<int>& piles) {
    // 记忆化递归
    // 每轮递归算相对的收益，及这轮的收益减去对手下轮的收益
    // dp[i][j] = ith 石堆开始 取j个
        int len=piles.size();
        vector<vector<int>> dp(len,vector<int>(len+1,0));
        int dif = recursivem(piles,dp,0,1);
        int total = accumulate(begin(piles),end(piles),0);
        return (total+dif)/2;
        
    }
    
    int recursivem(vector<int> piles,vector<vector<int>> &dp,int cur, int M){
        int len = piles.size();
        if(cur>=len) return 0;
        M= min(M,len);
        if(dp[cur][M]>0) return dp[cur][M];
        if(len-cur<=2*M) return accumulate(begin(piles)+cur,end(piles),0);
        int best = INT_MIN;
        int round = 0;
        for(int i=1;i<=M*2;i++){
            round += piles[cur+i-1];
            best = max(best, round - recursivem(piles,dp,i+cur,max(M,i)));
        }
        dp[cur][M] = best;
        return best;
    }
};
