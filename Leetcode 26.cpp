
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int position=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=nums[position-1]){
                nums[position]=nums[i];
                position++;
            }
        }
        return position;
    }
};
