class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2idx;
        int num;
        int complement;
        int halfIdx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            num = nums[i];
            complement = target - num;
            if (2*num == target) {
                if (halfIdx == -1) {
                    halfIdx = i;
                } else {
                    return {halfIdx, i};
                }
                continue;
            }
            if (num2idx.contains(num)) {
                continue;
            }
            if (num2idx.contains(complement)) {
                return {num2idx[complement], i};
            }
            num2idx[num] = i;
        }
    }
};
