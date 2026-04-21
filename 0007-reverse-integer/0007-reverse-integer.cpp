class Solution {
public:
    int reverse(int x) {
         long rev = 0;
        while(x!=0){
            int lastdig = x%10;
            rev = (rev*10)+lastdig;
            if (rev > INT_MAX || rev < INT_MIN) {
                return 0; 
            }
            x= x/10;
        }

        return rev;
        
    }
};