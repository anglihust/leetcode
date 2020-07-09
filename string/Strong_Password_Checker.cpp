// three operation replace, delete, add
//replace = max(miss_element,repeat_3)
//if n<6:add + replace ans = min(add#,replace#)
//if n~6-20: replace ans= replace
//if n>20: sort repeat number by remainder(a%3), greedy delete small repeat with samll remainder to eliminate repeat effectively

class Solution {
public:
    int strongPasswordChecker(string s) {
        if(s.size()==0) return 6; 
        int lower=1, upper=1, digit=1;
        int len = s.size();
        int count = 1;
        int repeat =0;
        auto cmp =[](const int a,const int b){return (a%3)>(b%3);};
        priority_queue<int,vector<int>,decltype(cmp)> consective_array(cmp);
        for(int i=0;i<len;i++){
            if(isdigit(s[i])) digit = 0;
            if(isupper(s[i])) upper = 0;
            if(islower(s[i])) lower = 0;
            if(i==0) continue;
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                if(count>=3){
                    repeat +=count/3;
                    consective_array.push(count);
                }
                count = 1;
            }
        }
        if(count>=3){
            repeat +=count/3;
            consective_array.push(count);
        }
        int need_replace = lower+upper+digit;
        if(len<6){
            return max(6-len,max(need_replace,repeat));
        } 
        else if(len>=6 and len<=20) return max(need_replace,repeat);
        else{
            repeat=0;
            int del_num = len-20;
            while(del_num>0 and !consective_array.empty()){
                int cur = consective_array.top();
                consective_array.pop();
                cur--;
                if(cur>=3) consective_array.push(cur);
                del_num--;
            }
            while(!consective_array.empty()){
                int cur = consective_array.top();
                consective_array.pop();
                repeat +=cur/3;
            }    
            return len-20+max(need_replace,repeat);
        }
    }
};
