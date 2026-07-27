class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int beforeMin = prices[0];
        int maxVal = 0;
        for (int i = 1; i < prices.size(); i++) { //i = 2 ; price = 5 ; before price =1
            beforeMin = min(prices[i - 1], beforeMin); // beforeMin = min(1, 0) = 1
            cout << "before min: " << beforeMin << endl;
            int diff = prices[i] - beforeMin; // diff = 5 - 1
            if (diff > maxVal) { // 4 > -9
                maxVal = max(maxVal, diff); // 4
            } 
        }
        return maxVal;
    }
};
