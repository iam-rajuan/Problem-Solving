#include <iostream>
using namespace std;

// Function to check if the given points form a square
bool isSquareFormed(int a, int b, int c, int d) {
    // Check if opposite sides are equal
    if (a != b || c != d) return false;
    // Ensure the distances are consistent
    return (a == c);
}

int main() {
    // Optimize input/output for faster performance
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTestCases;
    cin >> numTestCases;

    while (numTestCases--) {
        int side1, side2, side3, side4;
        cin >> side1 >> side2 >> side3 >> side4;

        // Check if the sides form a square
        bool isSquare = isSquareFormed(side1, side2, side3, side4);

        // Output the result
        if (isSquare) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}