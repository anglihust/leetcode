// from https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-546-remove-boxes
// Transition:
//dp[l][r][k] = max(dp[l][r-1][0] + (k + 1)*(k + 1),  # case 1
                  dp[l][i][k+1] + dp[i+1][r-1][0])  # case 2
//# "ABACA|AAAA" 
//# case 1: dp("ABAC") + score("AAAAA") drop j and the tail.
//# case 2: box[i] == box[r], l <= i < r, try all break points
//# max({dp("A|AAAAA") + dp("BAC")}, {dp("ABA|AAAAA") + dp("C")})

class Solution {
public:
  int removeBoxes(vector<int>& boxes) {
    const int n = boxes.size();
    m_ = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n)));
    return dfs(boxes, 0, n - 1, 0);
  }
private:
  vector<vector<vector<int>>> m_;
  
  int dfs(const vector<int>& boxes, int l, int r, int k) {
    if (l > r) return 0;    
    if (m_[l][r][k] > 0) return m_[l][r][k];
    m_[l][r][k] = dfs(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
    for (int i = l; i < r; ++i)
      if (boxes[i] == boxes[r])
        m_[l][r][k] = max(m_[l][r][k], dfs(boxes, l, i, k + 1) + dfs(boxes, i + 1, r - 1, 0));
    return m_[l][r][k];
  }
};
