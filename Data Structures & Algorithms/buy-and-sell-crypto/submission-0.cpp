class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> bestFuturePrice(n, 0);
        int x = 0;
        for (int i=n-1;i>=0;i--) {
            bestFuturePrice[i] = x;
            x = max(x, prices[i]);
        }
        int ans = 0;
        for (int i=0;i<n;i++) {
            ans = max(ans, bestFuturePrice[i] - prices[i]);
        }
        return ans;
    }
};
