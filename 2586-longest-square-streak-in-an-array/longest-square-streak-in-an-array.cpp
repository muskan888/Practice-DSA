class Solution {
public:
 
    int longestSquareStreak(vector<int>& nums) {
        set<long long>myset;
        for(int i=0;i<nums.size();i++){
            myset.insert(nums[i]);
        }
        int maxi=INT_MIN;
        for(long long num:myset){
            int ctr=0;
            long long curr=num;
            while(myset.find(curr)!=myset.end()){
                ctr++;
                curr=curr*curr;
            }
            if(ctr>1){
                maxi=max(maxi,ctr);
            }
        }
        if(maxi>1){
            return maxi;
        }
        return -1;
    }
};