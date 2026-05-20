class Solution {
public:
    bool isHappy(int n) {
        vector<int> arr;
        while(find(arr.begin(), arr.end(), n) == arr.end()){
            arr.push_back(n);
            n = sum(n);
            if(n==1){
                return true;
            }
        }
        return false;
        
    }

    int sum(int n){
        int s=0;
        while(n>0){
            int digit=n%10;
            s=s+digit*digit;
            n= n/10;
        }
        return s;
    }
};