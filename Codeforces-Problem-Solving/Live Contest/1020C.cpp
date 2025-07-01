#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void processTestCase() {
    int n;
    long long maxValue;
    cin >> n >> maxValue;

    vector<long long> first(n), second(n);
    for (int i = 0; i < n; ++i) cin >> first[i];
    for (int i = 0; i < n; ++i) cin >> second[i];

    bool hasKnownSum = false;
    long long requiredSum = -1;
    bool isConsistent = true;

    // Check for consistent predefined sums
    for (int i = 0; i < n; ++i) {
        if (second[i] != -1) {
            long long currentSum = first[i] + second[i];
            if (!hasKnownSum) {
                requiredSum = currentSum;
                hasKnownSum = true;
            } else if (currentSum != requiredSum) {
                isConsistent = false;
                break;
            }
        }
    }

    if (!isConsistent) {
        cout << "0\n";
        return;
    }

    // If we have a fixed sum, validate missing values
    if (hasKnownSum) {
        for (int i = 0; i < n; ++i) {
            if (second[i] == -1) {
                long long missing = requiredSum - first[i];
                if (missing < 0 || missing > maxValue) {
                    cout << "0\n";
                    return;
                }
            }
        }
        cout << "1\n";
    } else {
        // No fixed value, calculate range
        long long lower = 0;
        long long upper = numeric_limits<long long>::max();

        for (int i = 0; i < n; ++i) {
            lower = max(lower, first[i]);
            upper = min(upper, first[i] + maxValue);
        }

        if (upper < lower) {
            cout << "0\n";
        } else {
            cout << upper - lower + 1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        processTestCase();
    }

    return 0;
}
