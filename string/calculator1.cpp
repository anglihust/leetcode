//use stack to for the priroity of calculation
//after end of loop, the number need to be added to the result
class Solution {
public:
    int calculate(string str) {
        long long ans = 0;
        stack<int> store;
        long long cur_num = 0;
        int sign = 1;
        for(char w : str){
            if(w>='0' and w<='9') cur_num = cur_num*10 + w-'0';
            else if(w=='+'){
                ans+= sign*cur_num;
                sign=1;
                cur_num = 0;
            }
            else if(w=='-'){
                ans+= sign*cur_num;
                sign=-1;
                cur_num = 0;
            }
            else if(w=='('){
                store.push(ans);
                store.push(sign);
                ans = 0;
                sign =1;
                cur_num=0; 
            }
            else if(w==')'){
                int temp_sign = store.top();store.pop();
                long long temp_ans = store.top();store.pop();
                ans+= sign*cur_num;
                ans=temp_sign*ans+temp_ans;
                sign = 1;
                cur_num=0;
            }
        }
        if(cur_num!=0) ans+=sign*cur_num;
        return ans;
    }
};
