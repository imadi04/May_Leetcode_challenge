class Solution {
public:
    int firstUniqChar(string s) {
      int ans[26]={0};
      for(int i=0;i<s.size();i++)
          ans[s[i]-'a']++;
      for(int i=0;i<s.size();i++){
          if(ans[s[i]-'a']==1)
              return i;
      }
        return -1;
    }
    
    
     /*
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
           
            if(mp[s[i]].first==0)
                mp[s[i]].second=i;
             mp[s[i]].first+=1;
        }
        int m=INT_MAX;
        for(int i=0;i<s.size();i++){
           // cout<<s[i]<<":"<<mp[s[i]].first<<" "<<mp[s[i]].second<<endl;
            if(mp[s[i]].first==1){
                if(m>mp[s[i]].second)
                    m=mp[s[i]].second;
            }
        }
        
        
        return m==INT_MAX?-1:m;*/
};
