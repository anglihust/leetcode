class Solution {
public:
    vector<string> generatePalindromes(string s) {
        map<char,int> store;
        vector<char> c;
        for(int i=0;i<s.size();i++){
            store[s[i]]+=1; 
        }
        int count = 0;
        char last=0;
        for(auto w : store){
            if(w.second%2==1){
                count++;
                last = w.first;
            } 
            for(int i=0;i<w.second/2;i++) c.push_back(w.first); 
        } 
        if(count>=2) return {};
        vector<bool> visited(c.size(),false);
        vector<string> half,ans;
        string temp="";
        backtracking(temp, c, half, visited);
        string in ,sechalf;
        for(int i=0;i<half.size();i++){
             sechalf =half[i];
            reverse(sechalf.begin(),sechalf.end());
            if(last>0) in = half[i]+last+sechalf;
            else in = half[i]+sechalf;
            ans.push_back(in);
        }
        return ans;
    }
    
    void backtracking(string &temp, vector<char> c,vector<string>& ans,vector<bool> &visited){
        if(temp.size()==c.size()){
            ans.push_back(temp);
            return;
        }
        else{
            for(int i=0;i<c.size();i++){
                if(i>=1 and c[i]==c[i-1] and !visited[i-1] or visited[i]) continue;
                visited[i]=true;
                temp.push_back(c[i]);
                backtracking(temp,c,ans,visited);
                temp.pop_back();
                visited[i]=false;
            }
        }
    }
};

