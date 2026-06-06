class Solution {
public:
    int reverse(int x) {
         long long rev=0;
         while(x!=0){
            int digit=x%10;//last digit
            rev=rev*10+digit; //put thatlast digit into rev
            if(rev>INT_MAX || rev<INT_MIN){
                return 0;                
            }
            x=x/10;
         }  
         return rev;   
    }   
};