//from https://zxi.mytechroad.com/blog/graph/leetcode-959-regions-cut-by-slashes/

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int len = grid.size();
        Uionfind uion(len*len*4);
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                int index = 4*(i*len+j);
                if(grid[i][j] =='/'){
                    uion.merge(index+0,index+3);
                    uion.merge(index+1,index+2);
                }
                else if(grid[i][j] =='\\'){
                    uion.merge(index+0,index+1);
                    uion.merge(index+2,index+3);
                }
                else if(grid[i][j] ==' '){
                    uion.merge(index+0,index+1);
                    uion.merge(index+1,index+2);
                    uion.merge(index+2,index+3);
                }
                
                if(i<len-1) uion.merge(index + 2, index + 4 * len + 0);
                if(j<len-1) uion.merge(index + 1, index + 4 + 3);
            }
        }
        int ans =0;
        for (int i = 0; i < 4 * len * len; ++i)
            if (uion.find(i) == i) ++ans;
            return ans;
    }
private:
    class Uionfind{
        private:
            vector<int> fa;
        public:
            Uionfind(int n):fa(n){
                for(int i =0;i<n;i++) fa[i] = i;
            }
            
            int find(int x){
                if(x==fa[x]) return x;
                else{
                    fa[x] = find(fa[x]);
                }
                return fa[x];
            }
        
            void merge(int i, int j){
                int fai = find(i);
                int faj = find(j);
                fa[fai] = faj;
            }
    };
};
