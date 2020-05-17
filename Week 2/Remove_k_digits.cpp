class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==0)
            return num;
        if(k>=num.size())
            return "0";
        stack<char>s;
        s.push(num[0]);
        string n="";
        for(int i=1;i<num.size();i++){
            char t=s.top();
            if(t<=num[i])
                s.push(num[i]);
            else{
               //char temp=s.top();
                while( !s.empty() && num[i]<s.top() && k){
                    s.pop();
                    //temp=s.top();
                    k--;
                   // char temp=s.top();
                }
                s.push(num[i]);
            }
            
        }
        while(k && !s.empty()){
           // char t=s.top();
            s.pop();
            k--;
           // n=t+n;
        }
        while(!s.empty()){
             char t=s.top();
            s.pop();
           n=t+n;
        }
        cout<<"hi";
         while(n[0]=='0' && n.size()>1)
            n=n.substr(1);
       return n; 
    }
};
/*
 if(k==num.size())
            return "0";
        if(k==0)
            return num;
        char t=num[0];
        string small=removeKdigits(num.substr(1),k-1);
        char s=small[0];
        if(small[0]>=t){
             small[0]=t;
        }
        else{
            if(t<small[num.size()-1]){
                
            }
        }
           
        while(small[0]=='0' && small.size()>1)
            small=small.substr(1);
        
        return small;
*/