class Solution {
private:
    // n represents total number of A's required
    // current Number of A's that are currently present on the Notepad screen
    // copied contains the number of A's that are copied and can be used for pasting
    int helper(int n, int current, int copied, bool lastCopied){
        if(current == n) return 0;
        if(copied > n) return 1e5;
        if(current + copied > n) return 1e5;
        // Two cases
        // Copy
        int copy = 1e5;
        if(lastCopied == false)
            copy = helper(n, current, current, true);
        int paste = 1e5;
        if(copied != 0)
            paste = helper(n, current + copied, copied, false);
        return min(copy, paste) + 1;
    }
public:
    int minSteps(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note points
        // We have a notepad
        // Find the number of operations that needs to be performed to get n number of A's on the notepad
        // The idea is to use the recurrsion calls
        return helper(n, 1, 0, false);
    }
};
