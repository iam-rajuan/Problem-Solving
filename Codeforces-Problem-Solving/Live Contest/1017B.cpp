#include <iostream>
using namespace std;

void find_segment() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;

        int start = max(l, r - m);
        int end = start + m;

        if (0 >= l && 0 <= r) {
            int mid_start = max(l, 0 - m / 2);
            int mid_end = mid_start + m;

            if (mid_end <= r) {
                start = mid_start;
                end = mid_end;
            } else {
                end = r;
                start = end - m;
            }
        }

        cout << start << " " << end << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    find_segment();
    return 0;
}
