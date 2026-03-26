class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> ans(nums.size(),0);

        if (nums.size() < 2){
            return nums[0];
        }
        

        ans[0]=nums[0];
        ans[1]= max(nums[0],nums[1]);

        for (int i=2; i<nums.size();i++){
            ans[i] = max( ans[i-1], ans[i-2]+nums[i] );
        }
        return ans[nums.size()-1];

    }
};