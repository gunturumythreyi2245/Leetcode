class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        // isPrime[i] will represent whether (2 * i + 1) is prime.
        // This cuts our space requirements in half.
        int limit = n / 2;
        vector<bool> isPrime(limit, true);
        // Start counting with 1 (to account for the number 2)
        int primeCount = 1; 
        int sqrtN = sqrt(n);
        for (int i = 1; 2 * i + 1 < n; ++i) {
            if (isPrime[i]) {
                primeCount++;   
                // Only start marking if (2 * i + 1)^2 < n
                if (2 * i + 1 <= sqrtN) {
                    int p = 2 * i + 1;
                    // Start marking from p * p. 
                    // The step is 2 * p because adding an odd number to an odd number 
                    // makes it even, so we skip to the next odd multiple.
                    for (int j = p * p; j < n; j += 2 * p) {
                        isPrime[(j - 1) / 2] = false;
                    }
                }
            }
        }
        return primeCount;
    }
};
