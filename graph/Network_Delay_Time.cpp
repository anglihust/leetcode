class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> graph(N,vector<pair<int,int>>()) ;
        for(auto w : times){
            graph[w[0]-1].push_back({w[2],w[1]-1});
        }
        auto comp =[](pair<int,int> a, pair<int,int> b){return a.first>b.first;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> q(comp);
        q.push({0,K-1});
        vector<int> dist(N,INT_MAX), parent(N,0);
        dist[K-1]=0;
        vector<bool> visited(N,false);
        
        while(!q.empty()){
            pair<int,int> cur = q.top();
            q.pop();
            visited[cur.second] = true;
            for(auto w : graph[cur.second]){
                if(visited[w.second]) continue;
                if(cur.first+w.first<dist[w.second]){
                    dist[w.second]=cur.first+w.first;
                    parent[w.second]=cur.second;
                    q.push({dist[w.second],w.second});
                }
            }
        }
        int ans=0;
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
