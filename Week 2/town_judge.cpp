class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int>v(N+1,0);
        for(auto x:trust){
            v[x[0]]--;
            v[x[1]]++;
        }
        for(int i=1;i<=N;i++)
            if(v[i]==N-1)
                return i;
        return -1;
    }
};