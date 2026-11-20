class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN, sold = 0, rest = 0;
        
        for (int p : prices) {
            int prev_sold = sold;
            sold = hold + p;
            hold = max(hold, rest - p);
            rest = max(rest, prev_sold);
        }
        
        return max(sold, rest);
    }
};