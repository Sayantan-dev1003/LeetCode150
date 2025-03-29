class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2)
            return intervals;

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for (auto& interval : intervals) {
            if (!merged.empty() && merged.back()[1] >= interval[0]) {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            } else {
                merged.push_back(move(interval));
            }
        }

        return merged;
    }
};
