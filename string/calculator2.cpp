class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        stack<long long > store;
        long long cur_num = 0;
        long long ans = 0;
        int sign = 1;
        for(int i = 0;i<len;i++){
            if(s[i]>='0' and s[i]<='9'){
                cur_num = cur_num*10+s[i]-'0';
                store.push(cur_num);
            } 
            else if(s[i]=='+'){
                ans+=cur_num*sign;
                sign = 1;
                cur_num=0;
            }
            else if(s[i]=='-'){
                ans+=cur_num*sign;
                sign = -1;
                cur_num=0;
            }
            else if(s[i]=='*'){
                cur_num= 0;
                long long  temp_num  = store.top();store.pop();
                i++;
                while(s[i]==' ' or s[i]>='0' and s[i]<='9'){
                    if(s[i]!=' ') cur_num = cur_num*10+s[i]-'0';
                    i++;
                }
                i--;
                cur_num = temp_num*cur_num;
                store.push(cur_num);
            }
            else if(s[i]=='/'){
                cur_num= 0;
                long long  temp_num  = store.top();store.pop();
                i++;
                while(s[i]==' ' or s[i]>='0' and s[i]<='9'){
                    if(s[i]!=' ') cur_num = cur_num*10+s[i]-'0';
                    i++;
                }
                i--;
                cur_num = temp_num/cur_num;
                store.push(cur_num);
            }
        }
    if(cur_num!=0) ans+=cur_num*sign;
        return ans;
    }
};
