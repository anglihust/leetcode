//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
//if two stone share the same row or column, then they are in the connected region/
//using the union find to find the connected region
// ans = total stones - number of connected region 

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int len =stones.size();
        unionfind dsu(len);
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]) dsu.merge(i,j);
            }
        }
        int count=0;
        for(int i=0;i<len;i++) if(dsu.find(i)==i) count++;
        return len-count;
    }
    
private:
    class unionfind{
      private:
        vector<int> fa;
      public:
        unionfind(int n):fa(n){
            for(int i=0;i<n;i++) fa[i] = i;
        }
        
        int find(int x){
             if(fa[x]==x) return x;
             else{
                 fa[x] = find(fa[x]);
             }
            return fa[x];
        }
        
        void merge(int x, int y){
            int f1 = find(x);
            int f2 = find(y);
            fa[f1]=f2;
        }
    };
};
