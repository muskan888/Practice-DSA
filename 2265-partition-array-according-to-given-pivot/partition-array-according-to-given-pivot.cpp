class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>nums1;
        vector<int>nums2;
        int pivotCtr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                nums1.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                pivotCtr++;
            }
            else{
                nums2.push_back(nums[i]);
            }
        }
        for(int i=0;i<pivotCtr;i++){
            nums1.push_back(pivot);
        }
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        return nums1;
    }
};