#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sol() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    int found = 0, nonzero = 0;

    for (int i : v) {
        if (i != 0 && !nonzero) found++, nonzero = 1;
        if (i == 0) nonzero = 0;
    }

    cout << (found > 2 ? 2 : found);
}

int main() {
    int tc; cin >> tc; while (tc--) sol(), cout << '\n';
    return 0;
}
