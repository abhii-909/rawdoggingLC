class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConst = false;
        for(char c : word){
            if(!isalnum(c)) return false; // check alphanumeric
            if(isalpha(c)){
                char lower = tolower(c);
                if(lower == 'a' || lower =='e' || lower =='i' || lower =='o' || lower =='u'){
                    hasVowel = true;
                }else{
                    hasConst = true;
                }
            }
            if(hasVowel && hasConst) continue;
        }
        return hasVowel && hasConst;
    }
};