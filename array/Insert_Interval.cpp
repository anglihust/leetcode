class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int pos=0;
        for(int i = 0;i<intervals.size();i++){
            vector<int> cur = intervals[i];
            if(cur[0]>newInterval[1]){
                ans.push_back(cur);
            } 
            else if(newInterval[0]>cur[1]){
                ans.push_back(cur);
                pos++;
            }
            else{
                newInterval[0] = min(newInterval[0],cur[0]);
                newInterval[1] = max(newInterval[1],cur[1]);
            }
        }
        ans.insert(ans.begin()+pos,newInterval);
        return ans;
    }
};
