class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        //find the left and right sum
        for(int i=0;i<n;i++){
            int leftsum;
            if(i==0){
                leftsum=0;
            }else{
                leftsum=prefix[i-1];
            }

            int rightsum=prefix[n-1]-prefix[i];
            if(leftsum==rightsum){
                return i;
            }
        }
        return -1;
    }
};