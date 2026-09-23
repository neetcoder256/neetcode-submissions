class UnionFind {
public:
    UnionFind (int n) : parents(n) {
        std::iota(parents.begin(), parents.end(), 0);
    }
    int find(int i) {
        if (parents[i] == i) {
            return i;
        }
        return parents[i] = find(parents[i]);
    }
    bool sameClass(int i, int j) {
        return find(i) == find(j);
    }
    void unite(int i, int j) {
        parents[find(j)] = find(i);
    }
private:
    vector<int> parents;
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        vector<pair<string, int>> sortedStrs;
        for (int i = 0; i < strs.size(); ++i) {
            auto sortedS = strs[i];
            sort(sortedS.begin(), sortedS.end());
            sortedStrs.emplace_back(sortedS, i);
        }
        sort(sortedStrs.begin(), sortedStrs.end());
        results.emplace_back(1, strs[sortedStrs[0].second]);
        for (int i = 1; i < sortedStrs.size(); ++i) {
            if (sortedStrs[i - 1].first == sortedStrs[i].first) {
                results.back().emplace_back(strs[sortedStrs[i].second]);
            } else {
                results.emplace_back(1, strs[sortedStrs[i].second]);
            }
        }
        return results;
    }
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        
    }
private:
    array<int, 26> letterCount;
    bool areAnagrams(string& s, string& t) {
        if (s.length() != t.length()) {
            return false;
        }
        letterCount.fill(0);
        for (auto c : s) {
            letterCount[c - 'a'] += 1;
        }
        for (auto c : t) {
            letterCount[c - 'a'] -= 1;
            if (letterCount[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
        
    }
};
