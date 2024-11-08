class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int maxi=1;
        for(auto it:st){
            if(st.find(it-1)!=st.end()){
                continue;
            }
            else{
                 int len=1;
                int ele=it+1;
               if(st.find(it+1)!=st.end()){
                while(st.find(ele)!=st.end()){
                    len++;

                    ele++;
                }
                maxi=max(maxi,len);
               }

            }
        }
        return maxi;
    }
};