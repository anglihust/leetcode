// backtracking method
//using set to handle the repeat vector

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int start=0;
        vector<int> cur;
        set<vector<int>> ans;
        dfs(nums,start,ans, cur);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    
    void dfs(vector<int>& nums,int start, set<vector<int>> &ans, vector<int> cur){
        if(cur.size()>=2) ans.insert(cur);
        for(int i=start;i<nums.size();i++){
            if(cur.size()>0 and nums[i]<cur.back()) continue;
            cur.push_back(nums[i]);
            dfs(nums,i+1,ans,cur);
            cur.pop_back();
        }
    }
};
