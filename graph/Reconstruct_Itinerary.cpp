//Hierholzer algorithm
//recursion from the start node, for current node x, scan for all connected node y(ordered)
// recursion for node y and push x to array

class Solution {
private: 
    vector<string> ans;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> store;
        for(auto& w : tickets){
            store[w[0]].push(w[1]);
        }

        string src = "JFK";
        dfs(store,src);
        return vector<string>(ans.crbegin(), ans.crend());
    }
    void dfs( unordered_map<string,priority_queue<string,vector<string>,greater<string>>> &store,string src){
         while(!store[src].empty()){
             string des = store[src].top(); store[src].pop();
             dfs(store,des);
         }
        ans.push_back(src);
    }
};
