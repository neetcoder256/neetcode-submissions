class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2idx;
        int num;
        int halfIdx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            num = nums[i];
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
            num2idx[num] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            num = target - nums[i];
            auto find = num2idx.find(num);
            if (find != nullptr) {
                return {i, find->second};
            }
        }
    }
};
