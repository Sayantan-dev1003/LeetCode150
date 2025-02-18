class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, temp;
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            temp = nums[i];
            if (nums[index] == temp)
            {
                if (count == 1)
                {
                    nums.erase(remove(nums.begin() + i, nums.end(), nums[index]), nums.end());
                    count = 0;
                }
                else count += 1;
            }
            else count = 0;
            index = i;
        }
        return nums.size();
    }
};
