class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty())
            return 0;

        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int arrows = 1;
        int lastArrow = points[0][1];

        for (const auto& balloon : points) {
            if (balloon[0] > lastArrow) {
                arrows++;
                lastArrow = balloon[1];
            }
        }

        return arrows;
    }
};
