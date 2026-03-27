class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        
        // Sort in descending order so highest values come first
        sort(inventory.begin(), inventory.end(), greater<int>());
        
        long long ans = 0;
        int mod = 1e9 + 7;
        int n = inventory.size();

        for (int i = 0; i < n; i++) {
            
            long long curr = inventory[i]; // current highest value
            
            // next value (or 0 if last element)
            long long next;

            if (i == n - 1) {
                next = 0;
            } else {
              next = inventory[i + 1];
            }            
            
            // how many boxes have this level (0 to i)
            long long count = i + 1;

            // total balls we can sell from curr down to next+1
            long long totalBalls = count * (curr - next);

            // ✅ Case 1: we have enough orders to sell all these levels
            if (orders >= totalBalls) {
                
                // sum of numbers from curr down to (next + 1)
                // formula: (first + last) * number_of_terms / 2
                long long sum = (curr + next + 1) * (curr - next) / 2;

                // multiply by count (since multiple boxes)
                ans = (ans + count * sum) % mod;

                // reduce orders
                orders -= totalBalls;
            }
            else {
                // ✅ Case 2: we cannot sell full levels
                
                // how many full rows we can sell
                long long fullRows = orders / count;

                // remaining balls after full rows
                long long remainder = orders % count;

                // lowest value after selling fullRows
                long long low = curr - fullRows;

                // sum from curr down to (low + 1)
                long long sum = (curr + low + 1) * fullRows / 2;

                // add full rows profit
                ans = (ans + count * sum) % mod;

                // add remaining balls (all at value = low)
                ans = (ans + remainder * low) % mod;

                // all orders used
                return ans;
            }
        }

        return ans;
    }
};