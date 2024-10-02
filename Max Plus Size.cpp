#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Length of the array
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Variables to track the max value of red elements and count of red elements
        int max_value = 0;
        int count = 0;
        
        // Iterate through the array and pick non-adjacent elements
        for (int i = 0; i < n; i += 2) { // Start from index 0 and skip every second element
            max_value = max(max_value, a[i]);
            count++;
        }
        
        int max_score = max_value + count;
        
        // Now let's check for another possible configuration: start from index 1
        if (n > 1) { // Ensure there are at least 2 elements
            int max_value_alt = 0;
            int count_alt = 0;
            
            for (int i = 1; i < n; i += 2) { // Start from index 1
                max_value_alt = max(max_value_alt, a[i]);
                count_alt++;
            }
            
            // Calculate alternative score
            int max_score_alt = max_value_alt + count_alt;
            
            // Take the best score between the two strategies
            max_score = max(max_score, max_score_alt);
        }
        
        // Output the result for this test case
        cout << max_score << endl;
    }
    
    return 0;
}
