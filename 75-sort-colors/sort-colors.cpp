class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ctr0=0;
        int ctr1=0;
        int ctr2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ctr0++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ctr1++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2){
                ctr2++;
            }
        }
        int i=0;
        for(int j=0;j<ctr0;j++){
            nums[i]=0;
            i++;
        }
        for(int j=0;j<ctr1;j++){
            nums[i]=1;
            i++;
        }
         for(int j=0;j<ctr2;j++){
            nums[i]=2;
            i++;
        }
    }
};