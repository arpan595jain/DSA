class Solution {
public:
    int longestSubarray(vector<int>& nums) {
     int count=0;
     int maxvalue=0;
     int backup=0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
        }else{
            maxvalue=max(maxvalue,count);
            count-=backup;
            backup=count;
        }
     } 
     maxvalue=max(maxvalue,count);
     return maxvalue==nums.size()?maxvalue-1:maxvalue;  
    }
};
