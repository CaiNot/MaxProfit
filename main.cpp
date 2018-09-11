#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxValue = 0, minPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                if (maxValue < prices[i] - minPrice) {
                    maxValue = prices[i] - minPrice;
                }
            }
        }
        return maxValue;
    }

    int maxProfit2(vector<int> &prices) {// 可多次交易
        if (prices.size() < 1)
            return 0;
        int maxValue = 0, minPrice = prices[0];
        bool isFirst = true;
        int i = 1, lastValue = minPrice;
        for (; i < prices.size(); i++) {
            if (lastValue > prices[i]) {
                maxValue += lastValue - minPrice;
                minPrice=prices[i];
            }
            lastValue = prices[i];
        }
        if (prices[i - 1] > minPrice) {
            maxValue += prices[i - 1] - minPrice;
        }
        return maxValue;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> prices = {77,6,4,3,1};
    Solution s;
    cout << s.maxProfit2(prices) << endl;
    return 0;
}