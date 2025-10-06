class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxp = 0;
        int bb = prices[0];
        for (int x : prices){
            bb = min(bb,x);
            if (x>bb){

                maxp = max(maxp,x-bb);
            }
        }
        return maxp;

        
    }
};