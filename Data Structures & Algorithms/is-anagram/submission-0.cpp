class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> charCount;
        for (char c : s) {
            auto letter = charCount.find(c);
            if (letter == nullptr) {
                charCount[c] = 1;
            } else {
                letter->second += 1;
            }
        }
        for (char c: t) {
            auto letter = charCount.find(c);
            // Letter in t that is not in s
            if (letter == nullptr) {
                return false;
            }
            letter->second -= 1;
            // Letter in t that has more instances than in s
            if (letter->second < 0) {
                return false;
            }
        }
        return true;
    }
};
