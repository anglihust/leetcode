class TireNode{
    public:
        TireNode* next[26];
        bool isword;
        TireNode(){
            memset(next,NULL,sizeof(next));
            isword = false;
        }
        ~TireNode(){
            for(int i=0;i<26;i++){
                if(next[i]!=NULL) delete next[i];
            }
        }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TireNode* root;
    Trie() {
        root = new TireNode(); 
    }
    ~Trie() {
        delete root; 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TireNode* p = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i]-'a';
            if(p->next[idx]==NULL) p->next[idx]= new TireNode();
            p=p->next[idx];
        }
        p->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TireNode* p = root;  
        for(int i=0;i<word.size();i++){
            int idx =word[i]-'a';
            if(p->next[idx]==NULL) return false;
            p=p->next[idx]; 
        }
        return p->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TireNode* p = root;  
        for(int i=0;i<prefix.size();i++){
            int idx =prefix[i]-'a';
            if(p->next[idx]==NULL) return false;
            p=p->next[idx]; 
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
