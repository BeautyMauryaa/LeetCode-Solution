class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double windowsum=0;
        for(int i=0;i<k;i++){
            windowsum+=nums[i];
        }
        double maxavg=windowsum;
        for(int i=k;i<n;i++){
            windowsum=windowsum-nums[i-k]+nums[i];
            maxavg=max(maxavg,windowsum);
        }
      return maxavg/k;
    }
};