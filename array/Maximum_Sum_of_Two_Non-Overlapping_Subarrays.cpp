class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sum_val;
        sum_val.push_back(0);
        int ans = 0;
        for(int i =0;i<A.size();i++) sum_val.push_back(sum_val.back()+A[i]);
        for(int i=L;i<=A.size();i++){
            int maxM = 0;
            int j = M;
            while(j<(i-L)){
                maxM = max(maxM,sum_val[j]-sum_val[j-M]);
                j++;
            }
            j = i+M;
            while(j<=A.size()){
                maxM = max(maxM,sum_val[j]-sum_val[j-M]);
                j++;
            } 
            ans =max(ans,sum_val[i]-sum_val[i-L]+maxM);
        }
        return ans;
    }
};
