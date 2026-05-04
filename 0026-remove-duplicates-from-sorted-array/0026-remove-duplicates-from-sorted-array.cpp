class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    vector<int>a;
    for(int i=0;i<nums.size();i++)
    {
        if(find(a.begin(),a.end(),nums[i])==a.end())
        {
            a.push_back(nums[i]);
        }
    }
    nums=a;
    return nums.size();
    }
};