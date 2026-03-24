class Solution {
public:
    int findMin(vector<int>& nums) {
        int st=0;
        int end = nums.size()-1;
        int smallest = INT_MAX;

        while(st<= end){

            int mid = st+ (end-st)/2;

            if (nums[st] <= nums[mid]){
                smallest = min(nums[st],smallest);
                st = mid+1;

            } else{
                smallest = min(nums[mid],smallest);
                end = mid-1;
            }
        }
        return smallest;
    }
};