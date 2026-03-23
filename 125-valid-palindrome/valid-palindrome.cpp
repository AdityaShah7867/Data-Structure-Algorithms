class Solution {
public:
    bool isAplhaNum (char ch){
        if ( (ch >='0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }else{
            return false;
        }
    }

    bool isPalindrome(string s) {
    int  st = 0 , end = s.length()-1;

    while (st < end){
        if(!isAplhaNum(s[st])){
            st++; continue;
        } 
        if(!isAplhaNum(s[end])){
            end--; continue;
        }
        if( tolower(s[st]) != tolower(s[end])){
            return false;
        }
        st++;
        end--;
    }
    return true ; 
        
    }
};