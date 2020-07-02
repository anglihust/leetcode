class Solution {
public:
    int shortestWay(string source, string target) {
        set<char> s1(source.begin(),source.end());
        set<char> s2(target.begin(),target.end());
        if(!includes(s1.begin(),s1.end(),s2.begin(),s2.end())) return -1;
        
        int len = source.size();
        int count=0;
        for(int i =0;i<target.size();i++){
            int pos=0;
            while(pos<len and i<target.size()){
                if(source[pos]==target[i]) i++;
                pos++;
            }
            i--;
            count++;
        }
        return count;
    }
};
