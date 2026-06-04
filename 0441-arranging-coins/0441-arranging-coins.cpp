class Solution {
public:
    int arrangeCoins(int n) {
        int k=1;
        while(n>=k){
            n-=k;
            k++;
        }
        return k-1;
    }
};