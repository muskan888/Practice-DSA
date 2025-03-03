class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int li=0, gi=ans.size()-1; //pointers on the ans vector

        for(int i=0,j=nums.size()-1;i<nums.size(),j>=0;i++,j--){
            if(nums[i]<pivot){
                ans[li]=nums[i];
                li++;
            }
            if(nums[j]>pivot){
                ans[gi]=nums[j];
                gi--;
            }

        }
        while(li<=gi){
            ans[li]=pivot;
            li++;
            
        }
        return ans;

    }
};