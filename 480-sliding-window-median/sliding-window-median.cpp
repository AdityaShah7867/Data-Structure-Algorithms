class Solution {
    multiset<int> lo , hi;

    void add(int num){
        lo.insert(num);
        hi.insert(*lo.rbegin());
        lo.erase(prev(lo.end()));
        if(hi.size() > lo.size()){
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    }

    void remove(int num){
        auto it = lo.find(num);
        if (it != lo.end()) lo.erase(it); 
        else hi.erase(hi.find(num));     

          if (lo.size() < hi.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        } else if (lo.size() > hi.size() + 1) {
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        }
    }

    double getMedian(int k){
        if (k % 2 ==1){
            return *lo.rbegin();
        }else{
            return ((double)*lo.rbegin() + *hi.begin()) / 2.0;
        }
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> result;

        for (int i=0; i<n; i++){
            add(nums[i]);

            if (i >= k) remove (nums[i-k]);
            if (i>= k-1) result.push_back(getMedian(k));
        }
        return result;
    }
};