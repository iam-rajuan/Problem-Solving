#include <iostream>
#include <string>

int main() {
    int t; // Number of test cases
    std::cin >> t;

    while (t--) {
        int n;
        std::string s;

        // Read the length of the string and the binary string itself
        std::cin >> n >> s;

        int ones = 0;

        // Count how many '1's are in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            }
        }

        // Apply the formula: ones * (n - 2) + n
        long long result = 1LL * ones * (n - 2) + n;

        // Print the result for this test case
        std::cout << result << "\n";
    }

    return 0;
}
