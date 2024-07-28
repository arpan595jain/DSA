class Solution {
public:
    bool canAliceWin(std::vector<int>& nums) {
        int singleDigitSum = 0;
        int doubleDigitSum = 0;
        int totalSum = 0;
        
        for(int num : nums) {
            totalSum += num;
            if(num < 10) {
                singleDigitSum += num;
            } else {
                doubleDigitSum += num;
            }
        }
        
        int bobSumWhenAliceChoosesSingleDigit = totalSum - singleDigitSum;
        int bobSumWhenAliceChoosesDoubleDigit = totalSum - doubleDigitSum;
        
        return (singleDigitSum > bobSumWhenAliceChoosesSingleDigit) || (doubleDigitSum > bobSumWhenAliceChoosesDoubleDigit);
    }
};
