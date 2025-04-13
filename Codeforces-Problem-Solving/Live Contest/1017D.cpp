#include <iostream>
#include <string>
#include <vector>

struct Block {
    char ch;
    int freq;
};

// Break string into character blocks
std::vector<Block> segmentify(const std::string& input) {
    std::vector<Block> result;

    int len = input.length();
    if (len == 0) return result;

    char lastChar = input[0];
    int streak = 1;

    for (int idx = 1; idx < len; ++idx) {
        if (input[idx] == lastChar) {
            ++streak;
        } else {
            result.push_back(Block{lastChar, streak});
            lastChar = input[idx];
            streak = 1;
        }
    }

    result.emplace_back(Block{lastChar, streak});
    return result;
}

bool validateTransformation(const std::string& origin, const std::string& transformed) {
    if (transformed.length() < origin.length()) return false;
    if (transformed.length() > 2 * origin.length()) return false;

    std::vector<Block> base = segmentify(origin);
    std::vector<Block> test = segmentify(transformed);

    if (base.size() != test.size()) return false;

    for (size_t i = 0; i < base.size(); ++i) {
        if (base[i].ch != test[i].ch) return false;

        int minAllowed = base[i].freq;
        int maxAllowed = 2 * base[i].freq;
        if (test[i].freq < minAllowed || test[i].freq > maxAllowed)
            return false;
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int numberOfTests;
    std::cin >> numberOfTests;

    while (numberOfTests--) {
        std::string baseStr, checkStr;
        std::cin >> baseStr >> checkStr;

        bool result = validateTransformation(baseStr, checkStr);
        std::cout << (result ? "YES" : "NO") << '\n';
    }

    return 0;
}
