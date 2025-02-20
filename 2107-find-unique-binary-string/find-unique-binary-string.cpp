class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        for(int i=0;i<nums.size();i++){
            if(nums[i][i]=='1'){
                res.push_back('0');
            }
            else{
                res.push_back('1');
            }
            
        }
        return res;
    }
};