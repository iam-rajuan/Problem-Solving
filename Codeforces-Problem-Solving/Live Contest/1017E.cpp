#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCount;
    std::cin >> testCount;

    while (testCount--) {
        int n;
        std::cin >> n;
        std::vector<uint32_t> numbers(n);
        for (auto& val : numbers) {
            std::cin >> val;
        }

        // Reverse logic: track unset bit counts instead of set bits
        std::vector<int> unsetBitCounts(30, n);  // all bits are unset initially (total n)
        for (const auto& num : numbers) {
            for (int bit = 0; bit < 30; ++bit) {
                if ((num >> bit) & 1) {
                    unsetBitCounts[bit]--;  // if bit is set, remove from unset count
                }
            }
        }

        // Now compute contribution using inverse perspective
        uint64_t maxTotal = 0;
        for (const auto& candidate : numbers) {
            uint64_t score = 0;
            for (int bit = 0; bit < 30; ++bit) {
                uint64_t weight = 1ULL << bit;
                bool isBitSet = (candidate >> bit) & 1;

                if (isBitSet) {
                    // Current has 1, so we add weight * number of others with 0
                    score += static_cast<uint64_t>(unsetBitCounts[bit]) * weight;
                } else {
                    // Current has 0, add weight * number of others with 1 (n - unset)
                    score += static_cast<uint64_t>(n - unsetBitCounts[bit]) * weight;
                }
            }
            if (score > maxTotal) {
                maxTotal = score;
            }
        }

        std::cout << maxTotal << '\n';
    }

    return 0;
}
