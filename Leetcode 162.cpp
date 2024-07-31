class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        int n=nums.size();
       while(low <= high)
		{
			int mid = (low + high) / 2;

			if((mid == 0 || nums[mid - 1] <= nums[mid]) &&
				(mid == n - 1 || nums[mid + 1] <= nums[mid]))
				return mid;
			if(mid > 0 && nums[mid - 1] >= nums[mid])
				high = mid -1;
			else
				low = mid + 1;
		}
	return -1;
    }
};
     
