class Solution {
public:
    
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        unordered_map<int,int> frequencies;
        long long goodPairs=0;

        for(int i=0;i<n;i++){
            int val=nums[i]-i;
            //we check if goodPair already exists, then in order to calc all the good pairs we add the frequency
            goodPairs+=frequencies[val];
            frequencies[val]++;
        }
        return (n*(n-1)/2)-goodPairs;

    }   
};