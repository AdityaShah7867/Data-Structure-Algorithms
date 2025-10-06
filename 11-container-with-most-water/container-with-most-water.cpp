class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxvalue =0;
        int n = height.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            int width = right -left ;
            int he = min(height[left],height[right]);
            int currw = width * he;
            maxvalue = max(maxvalue,currw);

            if(height[left]>height[right]){
                right--;
            }else{
                left++;
            }
        }
    return maxvalue;
    }
};