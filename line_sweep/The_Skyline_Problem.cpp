class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int len = buildings.size();
        vector<vector<int>> ans; 
        vector<edgeinfo> edges;
        for(auto w : buildings){
            edges.push_back({w[0],w[2],1});
            edges.push_back({w[1],w[2],-1});
        }
        sort(edges.begin(),edges.end());
        for(int i = 0; i<edges.size();i++){
            // at entering edge, if it's larger than current roof, it's out of rectangle and be a critical point
            if(edges[i].type==1){
                if(edges[i].y>*store.begin()) ans.push_back({edges[i].x,edges[i].y});
                store.insert(edges[i].y);
            }
            //// at leaving edge, find the second largest edge
            else{
                store.erase(store.equal_range(edges[i].y).first);
                if(edges[i].y>*store.begin()) ans.push_back({edges[i].x,*store.begin()});
            }
        }
        return ans;
    }
    
private:
    struct edgeinfo{
        int x;
        int y;
        int type;
        bool operator<(const edgeinfo& e) const{
            // when leaving edge overlap the entering edge
            // entering edge should be before leaving age
            // when entering edge or leaving edge overlap together, entering edge high to low, leaving edge low to high
            if(x==e.x) return type*y>e.type*e.y;
            return x<e.x;
        }
    };
    multiset<int,greater<int>> store;
};
