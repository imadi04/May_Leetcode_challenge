class Solution {
public:
    bool compare(int *a,int *b){
        for(int i=0;i<256;i++){
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>v;
        if(p.size()>s.size())
            return v;
        int parr[256]={0};
        int sarr[256]={0};
        for(int i=0;i<p.size();i++){
            parr[p[i]]+=1;
            sarr[s[i]]+=1;
        }
        for(int i=p.size();i<s.size();i++){
            if(compare(sarr,parr))
                v.push_back(i-p.size());
            
            sarr[s[i]]++;
            sarr[s[i-p.size()]]--;
        }
        if(compare(sarr,parr))
                v.push_back(s.size()-p.size());
        return v;
    }
};

/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>v;
        int n=p.size();
        int n1=s.size();
        if(n>n1)
            return v;
        
        sort(p.begin(),p.end());
        for(int i=0;i<=n1-n;i++){
            string temp=s.substr(i,n);
            //cout<<temp<<" ";
            sort(temp.begin(),temp.end());
            if(p==temp)
                v.push_back(i);
        }
        return v;
    }
};
*/