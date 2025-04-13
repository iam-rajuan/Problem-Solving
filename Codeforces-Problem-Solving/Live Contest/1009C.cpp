#include <iostream>
using namespace std;

bool is_power_of_two(int n) {
    return (n & (n - 1)) == 0;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // If x is a power of 2 or x+1 is a power of 2, no valid y exists
        if (is_power_of_two(x) || is_power_of_two(x + 1)) {
            cout << "-1\n";
            continue;
        }

        // Find the largest power of 2 less than x
        int p = 1;
        while (p * 2 < x) {
            p *= 2;
        }

        int y = p - 1; // y has all lower bits set
        cout << y << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
