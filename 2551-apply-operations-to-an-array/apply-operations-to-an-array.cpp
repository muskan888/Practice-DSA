class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
            }
        }
        while(ans.size()<nums.size()){
            ans.push_back(0);
        }
        return ans;
    }
};