class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char,int>> store1;
        // loop over S and count each char
        for(int i=0;i<S.size();i++){
            if(i==0 or S[i]!=S[i-1]) store1.push_back({S[i],1});
            else store1.back().second++;
        }
        int res =0;
        int len =store1.size();
        for(auto w : words){
            pair<char,int> temp{w[0],1};
            int index = 0;
            bool flag= true;
            //for each word in words, check whether the char is the same and length match
            for(int i = 1; i<=w.size();i++){
                if(i==w.size() or w[i]!=w[i-1]){
                    if(temp.first==store1[index].first and ((store1[index].second>=3 and temp.second<=store1[index].second) or (store1[index].second<3 and store1[index].second==temp.second))){
                        //if length match then go to next char
                        temp.first=w[i];
                        temp.second=1;
                        index++;
                    }
                    else{
                        //if char or length dosen't match then set the count flag to false
                        flag=false;
                        continue;
                    }
                }
                else temp.second++;
            }
            // if char/length match and the word has all chars in S, then count
            if(flag and index==len) res++;
        }
        return res;
    }
};
