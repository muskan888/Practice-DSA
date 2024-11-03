class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>set;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
      
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long newTarget=(long long)target-(long long)nums[i]-(long long)nums[j];
                int low=j+1;
                int high=n-1;
                while(low<high){
                    if(nums[low]+nums[high]<newTarget){
                    low++;
                }
                else if(nums[low]+nums[high]>newTarget){
                    high--;
                }
                else{
                    //target found
                    set.insert({nums[i],nums[j],nums[low],nums[high]});
                    low++;
                    high--;
                }
                }

            }

        }
        for(auto it:set){
            ans.push_back(it);
        }
        return ans;
    }
};