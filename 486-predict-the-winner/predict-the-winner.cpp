class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int left, int right,vector<vector<int>>&dp){
        if(left==right){
            return nums[left];
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
       int scoreByPickingStart=nums[left]-solveUsingRecursion(nums,left+1,right,dp);
       int scoreByPickingEnd=nums[right]-solveUsingRecursion(nums,left,right-1,dp);

       dp[left][right]= max(scoreByPickingStart,scoreByPickingEnd);
       return dp[left][right];
        
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return solveUsingRecursion(nums,0,nums.size()-1,dp)>=0;
    }
};