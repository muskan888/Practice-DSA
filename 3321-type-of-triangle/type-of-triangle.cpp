class Solution {
public:
    string triangleType(vector<int>& nums) {
        //check if it can
        if(nums[0]+nums[1]<=nums[2] || nums[1]+nums[2]<=nums[0] || nums[0]+nums[2]<=nums[1]){
            return "none";
        }
  
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second==3){
                return "equilateral";
            }
            else if(it.second==2){
                return "isosceles";
            }
        }
        return "scalene";
        
    }
};