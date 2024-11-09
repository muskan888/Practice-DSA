class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;

        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=0;
        }

        stack<int>st;
        st.push(INT_MAX);
        for(int i=nums2.size()-1;i>=0;i--){
            while(st.top()<=nums2[i]){
                st.pop();
                mp[nums2[i]]=st.top();
            }
            if(st.top()>nums2[i]){
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]==INT_MAX){
                ans.push_back(-1);
            }
            else{
                ans.push_back(mp[nums1[i]]);
            }
        }
        return ans;
    }
};