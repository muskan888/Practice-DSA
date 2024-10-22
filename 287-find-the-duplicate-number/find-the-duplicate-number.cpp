class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //mark as visited
        for(int i=0;i<nums.size();i++){
            int idx=abs(nums[i]);
            if(nums[idx]<0){
                return abs(nums[i]);
                break;
            }
            nums[idx]=nums[idx]*-1;
        }
        return 0;
    }
};