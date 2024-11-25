#include <iostream>

void solve() {
    int numLights;
    std::cin >> numLights;
    int switchStates[2 * numLights];
    int numOff = 0, numOn = 0;

    for (int i = 0; i < 2 * numLights; i++) {
        std::cin >> switchStates[i];
    }

    for (int i = 0; i < 2 * numLights; i++) {
        if (switchStates[i] == 0) {
            numOff++;
        } else {
            numOn++;
        }
    }

    if (numOff == 0) {
        std::cout << "0 0" << std::endl;
    } else {
        if (numOff >= numOn) {
            std::cout << (numOff % 2) << " " << numOn << std::endl;
        } else {
            std::cout << (numOn % 2) << " " << numOff << std::endl;
        }
    }
}

int main() {
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        solve();
    }
    return 0;
}
