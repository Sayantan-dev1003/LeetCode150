class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0)
            return result;

        auto cmp = [&](const tuple<int, int, int>& a,
                       const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b);
        };

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       decltype(cmp)>
            minHeap(cmp);

        for (int i = 0; i < nums1.size() && i < k; ++i) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return result;
    }
};
