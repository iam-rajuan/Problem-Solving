#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
//#define int long long
#define pii pair<int, int>
#define se second
#define fi first
#define pb push_back
#define maxel(v) *max_element(v.begin(), v.end())
#define minel(v) *min_element(v.begin(), v.end())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define m1 cout << "-1\n"
#define no cout << "NO\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef int64_t i64;

void precalc() {}

void solve() {
    int n, m;
    cin >> n >> m;
    vec<ll> a(n+1), b(m+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    const int INF = n + 5;
    vec<int> L(m+1, INF);
    L[0] = 0;
    int p = 1;

    for (int i = 1; i <= m; i++) {
        while (p <= n && a[p] < b[i]) p++;
        if (p <= n) {
            L[i] = p;
            p++;
        } else {
            break;
        }
    }

    if (L[m] >= INF) {
        cout << 0 << "\n";
        return;
    }

    vec<ll> ar(n+1), br(m+1);
    for (int i = 1; i <= n; i++) ar[i] = a[n - i + 1];
    for (int i = 1; i <= m; i++) br[i] = b[m - i + 1];

    vec<int> Lr(m+1, INF);
    Lr[0] = 0;
    p = 1;

    for (int i = 1; i <= m; i++) {
        while (p <= n && ar[p] < br[i]) p++;
        if (p <= n) {
            Lr[i] = p;
            p++;
        } else {
            break;
        }
    }

    vec<int> R(m+2, 0);
    for (int j = 1; j <= m; j++) {
        int idx = m - j + 1;
        if (Lr[idx] < INF)
            R[j] = n - Lr[idx] + 1;
        else
            R[j] = 0;
    }
    R[m+1] = n + 1;

    ll ans = LLONG_MAX;
    for (int t = 1; t <= m; t++) {
        if (L[t-1] < R[t+1]) {
            ans = min(ans, b[t]);
        }
    }

    if (ans == LLONG_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}

signed main() {
    precalc();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
}
