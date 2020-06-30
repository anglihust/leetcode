class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>> store;
        int res =INT_MAX;
        for(auto w : points) store[w[0]].insert(w[1]);
        for(int i = 0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1]) continue;
                if(store[points[i][0]].count(points[j][1]) and store[points[j][0]].count(points[i][1])) res = min(res, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
            }
        }     
        return res==INT_MAX? 0 : res;
    }
};

