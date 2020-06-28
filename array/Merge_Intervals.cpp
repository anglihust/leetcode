// sort first and then merge one by one
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        vector<vector<int>> ans; 
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> cur= ans.back(); 
            if(intervals[i][0]<= cur[1]) ans.back()[1] = max(cur[1],intervals[i][1]);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};
