class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int exp=n*(n+1)/2;
        int actual=0;
        for(int i=0;i<nums.size();i++){
            actual+=nums[i];
        }
        return exp-actual;

    }
};