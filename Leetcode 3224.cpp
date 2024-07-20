class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size(), s = 0, ans = INT_MAX;
        vector<int> m(k + 2, 0);
        for (int i = 0; i < n / 2; i++)
        {
            if (nums[i] > nums[n - 1 - i])
                swap(nums[i], nums[n - 1 - i]);
            m[nums[n - 1 - i] - nums[i]]--;
            m[nums[n - 1 - i] - nums[i] + 1]++;
            m[0]++;
            m[max(nums[n - 1 - i], k - nums[i]) + 1]++;
        }
        for (int j = 0; j <= k; j++)
        {
            s += m[j];
            ans = min(ans, s);
        }
        return ans;
    }
};
