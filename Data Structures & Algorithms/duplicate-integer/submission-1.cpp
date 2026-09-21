class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> setNums;
        for (auto i : nums) {
            if (setNums.contains(i)) {
                return true;
            }
            setNums.insert(i);
        }
        return false;
    }
};