class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> graph;
        // constructed undirected graph
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]][equations[i][1]]=values[i];
            graph[equations[i][1]][equations[i][0]]=1.0/values[i];
        }
        vector<double> ans;
        // do dfs search for each pair of start and end point
        for(int i =0;i<queries.size();i++){
            string a = queries[i][0];
            string b = queries[i][1];
            if(!graph.count(a) or !graph.count(b)){
                ans.push_back(-1);
                continue;
            } 
            unordered_set<string> visited;
            ans.push_back(dfs(a,b,graph,visited));
        }
        return ans;
    }
    // dfs
    // recurively multiply weight from node to node 
    double dfs(string a, string b,unordered_map<string,unordered_map<string,double>> graph,unordered_set<string> &visited){
        if(a==b) return 1;
        visited.insert(a);
        for(auto w : graph[a]){
            string cur = w.first;
            if(visited.count(cur)) continue;
            double follow_path = dfs(cur,b,graph,visited);
            if(follow_path>0) return follow_path*graph[a][cur];
        }
        return -1; 
    }
};
