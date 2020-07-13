class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()<=1) return nums;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<int> dp(len,0);
        vector<int> track(len,-1);
        int count = 0;
        int record=-1;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++)
            if(nums[j]%nums[i]==0){
                if(dp[j]<dp[i]+1) dp[j]=dp[i]+1, track[j] = i;               
                if(dp[j]>count){
                    count = dp[j];
                    record = j;
                }
            }
        }
        vector<int> ans;
        while(record!=-1){
            ans.push_back(nums[record]);
            record = track[record];
        }
        if(ans.empty()) ans.push_back(nums[0]);
        return ans;
    } 
    
};
