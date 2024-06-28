class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int t=accumulate(nums.begin(),nums.end(),0);
       int lt=0;
       for(int i=0;i<nums.size();++i){
        int rt=t-lt-nums[i];
        if(rt==lt){
            return i;
        }
        lt+=nums[i];
       } 
       return -1;
    }
};
