class Solution {
public:
    set<string> res;
    int max;

    void helper(int n, string& cur, int left_p) {
        if (cur.size() == 2 * max) {
            res.insert(cur);
            return;
        }
        if (n == max) {
            cur += ')';
            helper(n, cur, left_p - 1);
            cur.pop_back();
        } else {
            if (left_p > 0) {
                cur += ')';
                helper(n, cur, left_p - 1);
                cur.pop_back();
            }
            cur += '(';
            helper(n + 1, cur, left_p + 1);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        max = n;
        string cur = "";
        helper(0, cur, 0);
        vector<string> r(res.begin(), res.end());

        return r;
    }
};
