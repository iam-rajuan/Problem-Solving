#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8}; // Use a vector to store the numbers
    int prev = 7; // Declare and initialize prev
    int n = nums.size(); // Get the size of the vector

    for (int i = 0; i < n; ++i) {
        swap(nums[i], prev); // Swap nums[i] with prev
    }

    // Display the updated nums array and prev
    cout << "Updated nums: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Final value of prev: " << prev << endl;

    return 0;
}
