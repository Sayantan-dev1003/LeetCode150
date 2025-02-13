class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = 0, count = 0;

        for (int num : nums) {
            if (count == 0)
                val = num;
            count += (num == val) ? 1 : -1;
        }

        return val;
    }
}; //Boyer-Moore Voting Algorithm TC - O(n)
