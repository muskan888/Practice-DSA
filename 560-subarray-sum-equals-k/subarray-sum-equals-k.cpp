class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int ctr=0;
        //for each new sum value, we check if there’s a previous point in the array where the sum was sum - k. Why? Because if we’ve seen sum - k before, it means the elements between that point and our current point add up to exactly k.
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int val=sum-k;
            if(mp.find(val)!=mp.end()){
                ctr+=mp[val];
            }

            mp[sum]++;
        }
        return ctr;
    }
};