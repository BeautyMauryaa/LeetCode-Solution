class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> prefix(n+1);
        prefix[0]=0;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+gain[i-1];
        }

        //max:
        int max=prefix[0];
        for(int i=1;i<=n;i++){
        if(prefix[i]>max){
            max=prefix[i];
        }
        }
        return max;
        
    }
};