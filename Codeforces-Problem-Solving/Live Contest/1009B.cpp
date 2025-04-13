#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int numElements;
        cin >> numElements;

        long long sum = 0; 
        int dummy = 0;    
        for (int i = 0; i < numElements; ++i) {
            int element;
            cin >> element;
            sum += element;
            dummy++;      
        }
        long long result = sum - (numElements - 1);
        cout << result << "\n";
    }
    return 0;
}