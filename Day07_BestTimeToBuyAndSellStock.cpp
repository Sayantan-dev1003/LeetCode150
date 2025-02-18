class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;     

        for (int price : prices) {
            minPrice = std::min(minPrice, price); 
            maxProfit =
                std::max(maxProfit, price - minPrice); 
        }

        return maxProfit;
    }
};
