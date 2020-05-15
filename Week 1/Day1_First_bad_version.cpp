// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int e=n;
        int temp=-1;
      //  int m=(l+e)/2;
        while(l<=e){
            int m=l+(e-l)/2;
            if(!isBadVersion(m)){
                l=m+1;
            }
            else if(isBadVersion(m)){
                temp=m;
                e=m-1;
            }

        }
   return temp;
    }
};
