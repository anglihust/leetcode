//TLE
class RangeModule {
    vector<vector<int>> store;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        int pos = 0;
        vector<vector<int>> temp_store;
        for(int i =0;i<store.size();i++){
            vector<int> cur = store[i];
            if(right<cur[0]){
                temp_store.push_back(cur);
            }
            else if(cur[1]<left){
                temp_store.push_back(cur);
                pos++;
            }
            else{
                left = min(left,cur[0]);
                right= max(right,cur[1]); 
            }
        }
        temp_store.insert(temp_store.begin()+pos,{left,right});
        store.swap(temp_store);
    }
    
    bool queryRange(int left, int right) {
        int l = 0; 
        int r = store.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(right<store[mid][0]) r =mid-1;
            else if(left>store[mid][1]) l = mid+1;
            else{
                return left>=store[mid][0] and right<=store[mid][1];
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        vector<vector<int>> temp_store;
        for(int i=0;i<store.size();i++){
            vector<int> cur = store[i];
            if(left>cur[0] and cur[1]>=left and cur[1]<=right){
                temp_store.push_back({cur[0],left});
            }
            else if(right>=cur[0] and cur[1]>right and cur[0]>=left){
                temp_store.push_back({right,cur[1]});
            }
            else if(cur[0]>=left and cur[1]<=right){
                continue;
            }
            else if(cur[0]<left and cur[1]>right){
                temp_store.push_back({cur[0],left});
                temp_store.push_back({right,cur[1]});
            }
            else temp_store.push_back(cur);
        }
        store.swap(temp_store);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
