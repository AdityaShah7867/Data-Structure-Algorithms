class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxsum = 0;
        double currsum = 0;

        for (int i=0;i<k;i++){
            currsum = currsum + nums[i];
        }

        maxsum = currsum;

        for (int i=k; i<nums.size();i++){
            currsum = currsum + nums[i];
            currsum = currsum - nums[i-k];
            maxsum = max(maxsum,currsum);
        }

        return maxsum/k;
    }
};