class Solution {
public:
    bool isPalindrome(string s){
       string conversion; //bcoz A!=a 
       for(char c:s){
        if(isalnum(c)){//number and alphabet
            conversion+=tolower(c);
        }
       }

       int left=0;
       int right=conversion.length()-1;
       while(left<right){
        if(conversion[left]!=conversion[right]){
            return false;
        }
        left++;
        right--;
       }
       return true;
    }
};