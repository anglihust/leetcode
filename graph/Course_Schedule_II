// construct graph and calculate in degree
// bfs find path

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> graph;
        vector<int> in(numCourses,0);
        for(auto w : prerequisites){
            graph[w[1]].push_back(w[0]);
            in[w[0]]++;
        } 
        queue<int> store;
        for(int i=0;i<in.size();i++) if(in[i]==0) store.push(i);
        vector<int> ans;
        while(!store.empty()){
            int len = store.size();
            for(int i=0;i<len;i++){
                int cur = store.front(); store.pop();
                ans.push_back(cur);
                for(auto w : graph[cur]){
                    in[w]--;
                    if(in[w]==0) store.push(w);
                }
            }
        }
        for(int i = 0; i < numCourses; ++i) if(in[i]!=0) return {}; 
        return ans;
    }
};
