// use find_last_of to find ?
// similar with using stack
class Solution {
public:
    string parseTernary(string expression) {
       string res = expression;
        while(res.size()>1){
            int index = res.find_last_of("?");
            char temp = res[index-1]=='T'? res[index+1] : res[index+3];
            res = res.substr(0,index-1)+temp+res.substr(index + 4);
        }
        return res;
    }
    
};
