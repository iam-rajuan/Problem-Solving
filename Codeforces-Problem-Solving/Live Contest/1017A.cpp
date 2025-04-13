#include <iostream>
#include <cctype>
#include <array>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;

    while (cases--) {
        array<string, 3> words;
        for (int i = 0; i < 3; ++i) {
            cin >> words[i];
        }
        for (const auto& w : words) {
            cout << char(tolower(w.front()));
        }
        cout << '\n';
    }

    return 0;
}
