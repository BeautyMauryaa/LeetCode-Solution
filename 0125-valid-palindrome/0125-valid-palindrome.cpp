class Solution {
public:
    bool isPalindrome(string s){
        string newstr = "";
        for(char c : s){
            if(isalnum(c)){
                newstr+=tolower(c);
            }
        }
        int start=0;
        int end = newstr.length()-1;

        while(start <= end){
            if(newstr[start] != newstr[end]){
                return false;
            }
            start++;
            end--;
        }
    return true;
    }

};