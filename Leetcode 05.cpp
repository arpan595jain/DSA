class Solution {
public:
    string longestPalindrome(string s) {
        size_t n = s.size();
        size_t start = 0;
        size_t length = 1;
        for (size_t i = 0; i < 2 * n - 1; ++i) {
            size_t k = i / 2;
            size_t parity = i % 2;
            size_t add = (i + 1) % 2;
            int j = 1;
            while (k + parity >= j && k + j < n && s[k + parity - j] == s[k + j]) {
                if (2 * j + add > length) {
                    length = 2 * j + add;
                    start = k - j + parity;
                }
                j++;
            }
        }
        string result = "";
        for (int i = start; i < start + length; ++i) {
            result += s[i];
        }
        return result;
    }
};
