class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int max1=0;
        vector<int>ans;
        for(int i=0;i<gain.size();i++){
            sum=sum+gain[i];
            max1=max(max1,sum);
        }
        return max1;
    }
};
