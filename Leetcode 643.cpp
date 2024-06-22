class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currsum=0,maxsum=0;
        for(int i=0;i<k;i++)
             currsum+=nums[i];
        maxsum=currsum;
        for(int i=k;i<nums.size();i++){
            currsum+=nums[i]-nums[i-k];
            maxsum=max(maxsum,currsum);
        }
        return maxsum/k;
    }
};
