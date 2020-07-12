class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n =req_skills.size();
        int m = people.size();
        int target = 1<<n;
        vector<int> peo(m,0);
        map<string,int> skills;
        for(int i =0;i<n;i++) skills.insert({req_skills[i],i});
        for(int i=0;i<m;i++){
            for(int j=0;j<people[i].size();j++) peo[i]|=(1<<skills[people[i][j]]);
        }
        
        vector<int> pre_state(target,-1),state_peo(target),dp(target,INT_MAX);
        //dp[i]代表i这个skill 组合的最少人数
        //dp[new_state]>dp[i]+1 多加一个人从i状态到新的状态 记录最小人数
        //state_peo记录到达new_state的这个人 j
        //pre_state记录new_state的上个状态i;
        dp[0] = 0;
        for(int i=0;i<target;i++){
            if(dp[i]==INT_MAX) continue;
            for(int j=0;j<m;j++){
                int new_state = i|peo[j];
                if(dp[new_state]>dp[i]+1){
                    dp[new_state] = dp[i]+1;
                    state_peo[new_state] = j;
                    pre_state[new_state] = i; 
                }
            }
        }
        vector<int> res;
        int tem=target-1;
        while(pre_state[tem]!=-1){
            res.push_back(state_peo[tem]);
            tem=pre_state[tem];
        }
        return res;
    }
};
