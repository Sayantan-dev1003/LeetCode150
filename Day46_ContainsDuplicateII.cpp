class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> index_map;

        for (int i = 0; i < nums.size(); i++) {
            if (index_map.find(nums[i]) != index_map.end() &&
                (i - index_map[nums[i]]) <= k) {
                return true;
            }
            index_map[nums[i]] = i;
        }
        return false;
    }
};
