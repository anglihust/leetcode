class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        // dp[i][j]: vocation days at week i city j
        // then dp[i-1][k] represent prev status, flight from city k to j. 
        // loop over k dp[i][j] = max(dp[i][j],dp[i-1][k]+days[j][i]) if there is flight from k to j and dp[i-1][k] has a valid value
        int N = flights.size();
        int K = days[0].size();
        int ans=0;
        for(int i=0;i<N;i++) flights[i][i]=1;
        vector<vector<int>> dp(K,vector<int>(N,-1));
        for(int i=0;i<N;i++) if(flights[0][i]) dp[0][i] = days[i][0];
        for(int i = 1;i<K;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    if(flights[k][j]==1 and dp[i-1][k]!=-1) dp[i][j] = max(dp[i][j],dp[i-1][k]+days[j][i]);
                }
                 if(i==K-1) ans = max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};

