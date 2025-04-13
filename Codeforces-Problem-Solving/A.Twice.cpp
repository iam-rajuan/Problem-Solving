#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    map<int, int> freq;
    for (auto x : v) freq[x]++;

    int ans = 0;
    for (auto x : freq) {
        ans += x.second / 2; // Count pairs
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
