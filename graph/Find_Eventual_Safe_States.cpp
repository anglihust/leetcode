//first find node without outward edge, safe node
//use bfs to find out node connected to safe nodes

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<set<int>> g(graph.size(),set<int>());
        vector<int> in(graph.size(),0);
        queue<int> store;
        vector<int> ans;
        for(int i=0;i<graph.size();i++){
            if(graph[i].empty()){
                ans.push_back(i);
                store.push(i);
            } 
            else{
                for(int j=0;j<graph[i].size();j++){
                    g[graph[i][j]].insert(i);
                    in[i]++;
                }
            }
        }
        
        while(!store.empty()){
            int cur = store.front();
            store.pop();
            for(auto w : g[cur]){
                in[w]--;
                if(in[w]==0){
                    ans.push_back(w);
                    store.push(w);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
