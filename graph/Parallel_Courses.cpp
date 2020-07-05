class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        unordered_map<int,vector<int>> graph;
        vector<int> in(N+1,0);
        in[0]=1;
        for(auto w : relations){
            graph[w[0]].push_back(w[1]);
            in[w[1]]++;
        } 
        queue<int>  store;
        for(int i=0;i<in.size();i++) if(in[i]==0) store.push(i);
        if(store.empty()) return -1;
        int count = 0;
        int ans = 0;
        while(!store.empty()){
            int len = store.size();
            for(int i=0;i<len;i++){
                int cur = store.front(); store.pop();
                count++;
                vector<int> next = graph[cur];
                for(int j = 0;j<next.size();j++){
                    in[next[j]]--;
                    if(in[next[j]]==0) store.push(next[j]);
                }
            }
            ans++;
        }
        if(count != N) return -1;
        return ans;
    }
};
