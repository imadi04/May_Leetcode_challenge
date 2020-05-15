class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m(26);
        for(char s:magazine)
            m[s]++;
        for(char t:ransomNote){
            if(--m[t]<0)
                return false;
        }
        return true;
    }
};
