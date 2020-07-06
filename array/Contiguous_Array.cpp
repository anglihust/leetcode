//change 0 to -1
//if sum[i]==sum[j] then i to j is a continuous array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> store;
        for(auto& w : nums) if(w==0) w=-1;
        store.insert({0, -1});
        int sumval=0,ans=0;
        for(int i = 0;i<nums.size();i++){
            sumval+=nums[i];
            if(store.count(sumval)) ans=max(ans,i-store[sumval]);
            else store.insert({sumval,i});
            
        }
        return ans;
    }
};

