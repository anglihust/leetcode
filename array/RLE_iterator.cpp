class RLEIterator {
private:
    queue<int> store;
public:
    RLEIterator(vector<int>& A) {
         for(int i=0;i<A.size();i+=2){
            int idx = 0;
             while(idx<A[i]){
                 store.push(A[i+1]);
                 idx++;
             }
         }
    }
    
    int next(int n) {
        int index = 0;
        while(!store.empty() and index<n-1){
            index++;
            store.pop();
        } 
        int ans = store.empty() ? -1 : store.front();
        if(ans!= -1) store.pop();
        return ans;
    }
};
