#include <bits/stdc++.h>
using namespace std;

// Function to find MEX of a set
int findMEX(const set<int> &s) {
    int mex = 0;
    while (s.find(mex) != s.end()) {
        ++mex;
    }
    return mex;
}

// Function to assign values to the dragons based on the problem constraints
vector<int> assignValues(int n, int x, int y) {
    vector<int> a(n, -1);
    vector<set<int>> friends(n);

    // Defining friendships in a circle
    for (int i = 0; i < n; ++i) {
        friends[i].insert((i + 1) % n);
        friends[i].insert((i - 1 + n) % n);
    }  

    // Adding friendship between x and y
    x--; y--;
    friends[x].insert(y);
    friends[y].insert(x);

    // Assigning values ensuring the MEX condition
    for (int i = 0; i < n; ++i) {
        set<int> neighborValues;
        for (int friendIndex : friends[i]) {
            if (a[friendIndex] != -1) {
                neighborValues.insert(a[friendIndex]);
            }
        }
        a[i] = findMEX(neighborValues);
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> result = assignValues(n, x, y);
        for (int value : result) {
            cout << value << " ";
        }
        cout << "\n";
    }

    return 0;
}
