// prefix tree
class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        node = root;
        str_input="";
        // construct Trie
        for(int i=0;i<sentences.size();i++){
            insert(sentences[i],times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> ans;
        if(c=='#'){
        //if input end, reset
            insert(str_input,1);
            node = root;
            str_input="";
            return{};
        }
        else{
        // node is the node of c in Trie
        // then search for sentence from char c using dfs
        // set the number of each sentence to negative or write a compare func
        
            str_input+=c;
            if(!node->next.count(c)) node->next[c] = new TrieNode();
            node=node->next[c];
            vector<pair<int,string>> store;
            dfs(node,store, str_input);
            sort(store.begin(),store.end());
            for(int i=0;i<min(3,(int)store.size());i++) ans.push_back(store[i].second);
        }
        return ans;
    }
private: 
    struct TrieNode{
    //unordered_map instread of vector(TLE)
        unordered_map<char,TrieNode*> next;
        int count;
        TrieNode(){
            count=0;
        }
    };
    
    void insert(string s, int times){
        TrieNode* p = root;
        int len=s.size();
        for(int i=0;i<len;i++) {
            if(!p->next.count(s[i])){ 
                p->next[s[i]]=new TrieNode();
            } 
            p=p->next[s[i]];
        }
        p->count-=times;
    }
    
    void dfs(TrieNode* root,vector<pair<int,string>>& store, string temp){
        if(root==NULL) return;
        if(root->count!=0) store.push_back(make_pair(root->count,temp));
        for(auto w : root->next){
            dfs(w.second,store,temp+w.first);
        }
    }
    TrieNode* root;
    TrieNode* node;
    string str_input;
    
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
