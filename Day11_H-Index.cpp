class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (int i = 0; i < citations.size(); i++, h++) {
            if (citations[i] <= h)
                break;
        }
        return h;
    }
};
