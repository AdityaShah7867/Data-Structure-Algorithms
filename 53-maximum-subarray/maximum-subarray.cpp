class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //
        int currentSum=0, maxSum=INT_MIN;

        for (int value : nums){
            currentSum += value;
            maxSum = max(maxSum,currentSum);
            if (currentSum<0){
                currentSum=0;
            }
        }
        return maxSum;
    }
};