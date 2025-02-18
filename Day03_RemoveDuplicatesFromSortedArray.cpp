class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int temp = nums[0];
        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i] == temp)
        //         nums.erase(remove(nums.begin()+i, nums.end(), nums[i]),
        //         nums.end());
        //     temp = nums[i];
        // } TC = O(N^2)

        auto last = std::unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());
        return nums.size(); // TC = O(N)
    }
};
