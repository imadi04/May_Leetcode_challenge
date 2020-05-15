class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int t=nums.size()/2;
        int ans;
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
            if(mp[i]>t){
                ans=i;
                break;
            }
       
        }
        return ans;
    }
};
