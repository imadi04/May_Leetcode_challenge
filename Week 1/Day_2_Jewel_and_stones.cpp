class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set <char>jewel;
        for(int i=0;i<J.length();i++)
            jewel.insert(J[i]);
        int c=0;
        for(int j=0;j<S.length();j++){
            if(jewel.find(S[j])!=jewel.end())
                c++;
        }
        return c;
    }
};
