//backtracking TLE
class Solution {
private:
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_set<string> ans(words.begin(),words.end());
        string temp;
        dfs(S,0,ans,temp);
        return words.size()-ans.size();
    }
    
    void dfs(string S, int start, unordered_set<string> &word,string temp){
        if(word.count(temp)){
            word.erase(temp);
        } 
        for(int i=start;i<S.size();i++){
            if(i>0 and S[i-1] ==S[i]) continue;
            temp.push_back(S[i]);
            dfs(S,i+1,word,temp);
            temp.pop_back();
        }
    }
};


//Binary search

class Solution {
private:
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char,vector<int>> maping;
        unordered_map<string,bool> store;
        int ans = 0;
        for(int i = 0;i<S.size();i++){
            maping[S[i]].push_back(i);
        }
        for(auto w : words){
            if(store.count(w)){
                ans+=store[w];
                continue;
            }
            
            int prev=-1;
            for(int i=0;i<w.size();i++){
                vector<int> cur =maping[w[i]];
                auto pos = lower_bound(cur.begin(),cur.end(),prev+1);
                if(pos==cur.end()) store[w]=false;
                else{
                    prev =*pos; 
                }
            }
            if(!store.count(w)){
                store[w]=true;
                ans++;
            } 
        }
        return ans;
    }
};
