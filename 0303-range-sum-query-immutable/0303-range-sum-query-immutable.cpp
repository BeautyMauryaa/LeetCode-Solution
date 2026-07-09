class NumArray {
public:
vector<int> Prefix;
    NumArray(vector<int>& nums) {
        int n=nums.size();
         Prefix.resize(n);
        Prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            Prefix[i]=Prefix[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return Prefix[right];
        }
        else{
            return Prefix[right]-Prefix[left-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */