#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run_case() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    for (auto& row : mat)
        for (auto& val : row)
            cin >> val;

    vector<int> diag_map(2 * n + 1, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int idx = i + j + 2;
            if (!diag_map[idx])
                diag_map[idx] = mat[i][j];
        }

    vector<bool> seen(2 * n + 1, false);
    for (int i = 2; i <= 2 * n; ++i)
        if (diag_map[i] <= 2 * n)
            seen[diag_map[i]] = true;

    auto it = find(seen.begin() + 1, seen.end(), false);
    diag_map[1] = it - seen.begin();

    for (int i = 1; i <= 2 * n; ++i)
        cout << diag_map[i] << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        run_case();

    return 0;
}
