class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minCapital;

        priority_queue<int> maxProfit;

        for (int i = 0; i < n; ++i) {
            minCapital.emplace(capital[i], profits[i]);
        }

        while (k--) {
            while (!minCapital.empty() && minCapital.top().first <= w) {
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }

            if (maxProfit.empty())
                break;

            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};
