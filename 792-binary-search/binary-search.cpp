class Solution {
    
private:

    int recursion(vector<int> arr,int target, int start, int end){

        if (start <= end){
            int mid = start + (end-start)/2;
            if(target > arr[mid]){
                return recursion(arr,target,mid+1,end);
            }else if(target < arr[mid]){
                return recursion(arr,target,start,mid-1);
            }else{
                return mid;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
       
        int n = nums.size();
        int start = 0 , end=n-1;

        return recursion(nums,target,start,end);
        
    }
};