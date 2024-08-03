class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        while(start < end)
        {
            int mid = start + (end - start)/2;
            int total = 0;
            for(int pile : piles)
            {
                total = total + ceil((double)pile / mid);
            }
            if(total > h)
            {
                start = mid + 1;
            }
             else {
                end = mid;
            }
        }
        return start;
    }
};
