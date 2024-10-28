class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){ //if we find the element and cursor doesn't reach end of map
                return {mp[target-nums[i]],i};
            }
            //storing the index in map
            mp[nums[i]]=i;
        }
        return {};
    }
};