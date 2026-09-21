class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> setNums;
        for (auto i : nums) {
            if (setNums.contains(i)) {
                return true;
            }
            setNums.insert(i);
        }
        return false;
    }
};