class Solution {
public:
    int missingNumber(vector<int>& nums) {
       map<int, bool>mp;
      for(int n:nums){
        mp[n]=true;
      }
      int i;
      for( i=0; i<nums.size()+1;i++){
        if(!mp[i]){
            return i;
        }
      } return i;
    }
   
};