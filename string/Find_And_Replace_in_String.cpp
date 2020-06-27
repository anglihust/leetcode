// sort the index with source and target first

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<event> match;
        for(int i =0;i<indexes.size();i++){
            int match_len = sources[i].size();
            if(S.substr(indexes[i],match_len)==sources[i]) match.push_back({indexes[i],sources[i],targets[i]});
        }
        sort(match.begin(),match.end());
        string ans;
        int orilen = S.size();
        for(int i =0;i<match.size();i++){
                int id = S.size()-orilen+match[i].idx;
                S.replace(id,match[i].src.size(),match[i].tag);
        }
        return S;
    }
private:
    struct event{
        int idx;
        string src, tag;
        bool operator<(event a){
            return idx<a.idx;
        }
    };
};
