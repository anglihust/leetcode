class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> store;
        int sum_val = 0, ans =0;
        store.insert({0,-1});
        for(int i=0;i<nums.size();i++){
            sum_val+= nums[i];
            int pre=sum_val-k;
            if(store.count(pre)) ans=max(ans,i-store[pre]);
            store.insert({sum_val,i});
        }
        return ans;
    }
};
