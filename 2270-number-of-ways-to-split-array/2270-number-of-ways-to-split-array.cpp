class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        int count=0;
        for(int i=0;i<n-1;i++){
            long long  leftsum=prefix[i];
            long long  rightsum=prefix[n-1]-prefix[i];
            if(leftsum>=rightsum){
                count++;
            }
        }
        return count;
        
    }
};