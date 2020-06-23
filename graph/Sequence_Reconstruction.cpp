// bfs TLE
//construct graph and calculate the in-degree
//in BSF, every time there is a number with zero in-degree, compare it with the element in org sequence

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(org.empty() or seqs.empty() or seqs[0].empty()) return false;
        unordered_map<int,vector<int>> graph;
        unordered_map<int,int> in;
        for(auto w : seqs){
            for(int i=0;i<w.size();i++){
                in[w[i]]=0;
                for(int j=i+1;j<w.size();j++){
                    graph[w[i]].push_back(w[j]);
                }
            }
        }
        
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                in[graph[i][j]]++;
            }
        }
        queue<int> store;
        for(auto w : org) if(in.count(w) and in[w]==0) store.push(w);
        if(store.empty() or store.front()!=org[0] or store.size()>1) return false;
        int count = 0;
        while(!store.empty()){
            if(store.size()>1) return false;
            int cur = store.front(); store.pop();
            if(cur!=org[count]) return false;
            for(auto w : graph[cur]){
                in[w]--;
                if(in[w]==0){
                store.push(w);
                }
            }
            count++;
        }
        return count==org.size();
    }
};
