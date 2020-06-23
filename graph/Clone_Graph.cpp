// BFS method
// using a unordered_map to build map between orginal and clone
// in bfs, find the neighbor of original, build clone node for this neighbor
// add this clone node in the unordered_map and clone neighbors
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> visited;
        queue<Node*> q;
        q.push(node);
        Node *clone = new Node(node->val);
        visited[node] = clone;
        while(!q.empty()){
            Node* cur = q.front();q.pop();
            for(auto n : cur->neighbors){
                if(!visited.count(n))
                {
                    Node *nclone = new Node(n->val);
                    visited[n]=nclone;
                    q.push(n);
                }
                visited[cur]->neighbors.push_back(visited[n]);
            }
        }
        return clone;
    }
};

//dfs: same idea, but dfs to scan nodes
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> visited;
        Node* clone = new Node(node->val);
        visited[node] = clone;
        dfs(visited,node);
        return clone;
    }
    
    void dfs(unordered_map<Node*,Node*> &visited,Node* cur){
        if (!cur) return;
        for(auto w : cur->neighbors){
            if(!visited.count(w)){
                Node* nclone = new Node(w->val);
                visited[w]=nclone;
                dfs(visited,w);
            }
                visited[cur]->neighbors.push_back(visited[w]);
        }
    }
};
