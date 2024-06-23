class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        std::deque<int> maxq;
        std::deque<int> minq;
        int n = nums.size();
        int j = 0;
        int ans = 0;
        for(int i = 0; i < n; i ++){
            while(!maxq.empty() && nums[i] > maxq.back())
                maxq.pop_back();
            maxq.push_back(nums[i]);
            while(!minq.empty() && nums[i] < minq.back()){
                minq.pop_back();
            }
            minq.push_back(nums[i]);
            if(maxq.front() - minq.front() > limit){
                if(nums[j] == maxq.front()) maxq.pop_front();
                if(nums[j] == minq.front()) minq.pop_front();
                j++;
            }
            ans = std::max(ans, i - j + 1);
        }
        return ans;
    }
};
