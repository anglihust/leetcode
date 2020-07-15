class SummaryRanges {
public:
    vector<vector<int>> ans;
    vector<vector<int>> temp;
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        temp.clear();
        vector<int> newinterval ={val,val};
        int pos = 0;
        for(int i=0;i<ans.size();i++){
            vector<int> cur =ans[i];
            if(cur[0]>newinterval[1]+1) temp.push_back(cur);
            else if(cur[1]+1<newinterval[0]) temp.push_back(cur), pos++;
            else newinterval[0] = min(cur[0],newinterval[0]), newinterval[1] = max(cur[1],newinterval[1]);
        }
        temp.insert(begin(temp)+pos,newinterval);
        ans.swap(temp);
    }
    
    vector<vector<int>> getIntervals() {
        return ans;   
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
