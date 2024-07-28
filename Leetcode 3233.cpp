class Solution {
public:
    int nonSpecialCount(int l, int r) {
        // Step 1: Find all primes up to sqrt(r)
        int upperBound = std::sqrt(r) + 1;
        std::vector<bool> isPrime(upperBound, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes
        
        for (int i = 2; i * i < upperBound; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < upperBound; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Step 2: Identify all special numbers in the range [l, r]
        std::vector<int> specialNumbers;
        for (int i = 2; i < upperBound; ++i) {
            if (isPrime[i]) {
                int square = i * i;
                if (square >= l && square <= r) {
                    specialNumbers.push_back(square);
                }
            }
        }
        
        // Step 3: Calculate the count of non-special numbers
        int totalNumbers = r - l + 1;
        int specialCount = specialNumbers.size();
        int nonSpecialCount = totalNumbers - specialCount;
        
        return nonSpecialCount;
    }
};
