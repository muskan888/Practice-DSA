class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ctr=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
               
                ctr++;
            }
            else{
              
                ctr=0;
            }
             maxi=max(maxi,ctr);
        }
        return maxi;
    }
};