class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return n;

        int maxPointsOnLine = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slopeMap;
            int duplicates = 1;
            int vertical = 0;
            int localMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                } else if (dx == 0) {
                    vertical++;
                } else {
                    int gcd = __gcd(dx, dy);
                    dx /= gcd;
                    dy /= gcd;

                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }

                    string slopeKey = to_string(dy) + "/" + to_string(dx);
                    slopeMap[slopeKey]++;
                    localMax = max(localMax, slopeMap[slopeKey]);
                }

                localMax = max(localMax, vertical);
            }

            maxPointsOnLine = max(maxPointsOnLine, localMax + duplicates);
        }

        return maxPointsOnLine;
    }
};
