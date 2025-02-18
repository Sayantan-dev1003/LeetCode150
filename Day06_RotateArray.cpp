class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() > 1) {
            if (nums.size() < k)
                k %= nums.size();
            vector<int> temp1(nums.begin(), nums.end() - k);
            vector<int> temp2(nums.end() - k, nums.end());
            nums = {};
            nums.insert(nums.end(), temp2.begin(), temp2.end());
            nums.insert(nums.end(), temp1.begin(), temp1.end());
        }
    }
};
