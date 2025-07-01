#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void createPermutation(int size, int x) {
    vector<int> values;
    for (int i = 0; i < size; ++i) {
        values.push_back(i);
    }

    if (x == 0) {
        rotate(values.begin(), values.begin() + size - 1, values.end());
    } 
    else if (x < size) {
        int temp = values[x];
        values.erase(values.begin() + x);
        values.push_back(temp);
    }
    // If x == size, do nothing, already identity

    for (int i = 0; i < size; ++i) {
        cout << values[i] << (i == size - 1 ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_count;
    cin >> test_count;

    while (test_count--) {
        int n, x;
        cin >> n >> x;
        createPermutation(n, x);
    }

    return 0;
}
