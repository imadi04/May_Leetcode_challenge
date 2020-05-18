class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        bool flag=false;
        for(auto i:A){
            if(i>0){
                flag=true;
                break;
            }
        }
        if(!flag)
            return *max_element(A.begin(),A.end());
        int local_max=0;
        int global_max=INT_MIN;
        int sum=0;
        int local_min=0;
        int global_min=INT_MAX;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            local_max=max(local_max+A[i],A[i]);
            if(local_max>global_max){
                global_max=local_max;
               }
            local_min=min(local_min+A[i],A[i]);
            if(local_min<global_min){
                global_min=local_min;
               }
        }
        cout<<global_min;
        return max(sum-global_min,global_max);
    }
}; 