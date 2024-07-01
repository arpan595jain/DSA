class Solution {
public:
    string removeStars(string s) {
        string st = "";
        for (auto ch : s) {
            if (ch == '*') {
                st.pop_back();
            } else {
                st += ch;
            }
        }
        return st;
    }
};
