// calculate the effective length of sentence
// S: a-bcde-def-hshaha
// case 1 :  a-bcde             S[effective_len%len]==' ', then we saved one space: first '-' in second row 
//           def---
// case 2 : a-bcde-def-         S[effective_len%len]!=' ' and S[(effective_len-1)%len]==' ', then continue
//          hshaha-----
// case 3 : a-bcde--            effective_len--, we waste some space at end of first row
//          def-----
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string S;
        for(auto w : sentence)  S+=(w+" ");
        int len = S.size();
        int effective_len = 0;
        for(int i=0;i<rows;i++){
             effective_len+=cols;
             if(S[effective_len%len]==' '){
                effective_len++;
                continue;
             }
            if(S[effective_len%len]!=' ' and S[(effective_len-1)%len]==' ') continue;
            while(effective_len>0 and S[(effective_len-1)%len]!=' ') effective_len--;
        }
        return effective_len/len;
    }
};
