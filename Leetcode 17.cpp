class Solution {
private:
    // Recursive function to generate letter combinations
    void solve(string digits, vector<string>& ans, int index, string output, string mapping[]) {
        // Base case: If we have processed all digits, add the output to the result
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0'; // Convert the current digit to an integer
        string temp = mapping[number];    // Get the corresponding letters for the digit

        // Iterate through the letters associated with the current digit
        for (int i = 0; i < temp.length(); i++) {
            output.push_back(temp[i]); // Add the current letter to the output
            solve(digits, ans, index + 1, output, mapping); // Recursively generate combinations
            output.pop_back(); // Backtrack by removing the last added letter
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans; // Final output storage

        if (digits.length() == 0) return ans; // If input is empty, return an empty result

        int index = 0;
        string output = "";
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, ans, index, output, mapping); // Start generating letter combinations
        return ans;
    }
};
