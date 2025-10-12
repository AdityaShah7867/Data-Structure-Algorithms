class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int x : bills) {
            if (x == 5) {
                five++;
            } 
            else if (x == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }

            } else {
                if (ten && five) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five = five - 3;
                } else
                    return false;
            }
        }
        return true;
    }
};