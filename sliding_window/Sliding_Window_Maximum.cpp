// sliding window, using deque to record local maximum
//1 3 -1 -3 5 3
//[1] 3 -1 -3 5 -3     [1]
//[1 3] -1 -3 5 -3     [3]
//[1 3 -1] -3 5 -3     [3 -1]
//1 [3 -1 -3] 5 -3     [3 -1 -3]
//1 3 [-1 -3 5] -3     [5]
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> slidw;
        for(int i=0;i<nums.size();i++){
            // if the first element is out of the window, them delete it 
            if(!slidw.empty() and slidw.front() == i-k) slidw.pop_front();
            while(!slidw.empty() and nums[slidw.back()]<=nums[i]) slidw.pop_back();
            slidw.push_back(i);
            if(i>=k-1) res.push_back(nums[slidw.front()]);
        }
         return res;
    }
};
