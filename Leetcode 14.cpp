class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int high = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            high = min(high, (int)strs[i].length());
        }
        int low = 1;
        string prefix = "";
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommonPrefix(strs, mid)) {
                prefix = strs[0].substr(0, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return prefix;
    }

private:
    bool isCommonPrefix(vector<string>& strs, int len) {
        string prefix = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].compare(0, len, prefix) != 0) {
                return false;
            }
        }
        return true;
    }
};
