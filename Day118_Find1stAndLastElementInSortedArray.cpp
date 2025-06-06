class Solution {
public:
    int findFirst(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return first;
    }

    int findLast(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, last = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findFirst(nums, target);
        int end = findLast(nums, target);
        return {start, end};
    }
};
