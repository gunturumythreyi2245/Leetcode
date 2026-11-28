class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxFactor = 0;
        int minPrice = INT_MAX;
        
        for (const auto& item : items) {
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, item[1]);
        }
        
        vector<int> freq(maxFactor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }
        
        vector<int> multCount(maxFactor + 1, 0);
        for (int i = 1; i <= maxFactor; ++i) {
            if (freq[i] > 0) {
                for (int j = i; j <= maxFactor; j += i) {
                    multCount[i] += freq[j];
                }
            }
        }
        
        map<int, long long> priceMap;
        for (const auto& item : items) {
            int factor = item[0];
            int price = item[1];
            if (price < minPrice * 2) {
                int validFree = multCount[factor] - 1;
                if (validFree > 0) {
                    priceMap[price] += validFree;
                }
            }
        }
        
        long long ans = 0;
        long long remBudget = budget;
        for (const auto& [price, count] : priceMap) {
            if (remBudget < price) {
                break;
            }
            long long buy = min(count, remBudget / price);
            remBudget -= buy * price;
            ans += buy * 2;
        }
        
        ans += remBudget / minPrice;
        return static_cast<int>(ans);
    }
};
