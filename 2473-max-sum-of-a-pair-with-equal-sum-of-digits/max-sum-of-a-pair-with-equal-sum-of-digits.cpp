class Solution {
public:
    int digitSums(int num){
        int sum=0;
        while(num>0){
            sum=sum+num%10;
            num=num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++){
            int digitSum=digitSums(nums[i]);
            mp[digitSum].push_back(nums[i]);
        }
        int sum=-1;
        for(auto&it:mp){
            sort(it.second.begin(),it.second.end());
             if(it.second.size()>1){
                sum=max(sum,it.second[it.second.size()-1]+it.second[it.second.size()-2]);
             }
        }
        return sum;
    }
};