class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp;
        
        for(int i=0;i<arr.size();i++){
            temp.push_back(arr[i]);
        }
        unordered_map<int,int>mp;
        sort(temp.begin(),temp.end());
        int rank=1;
        for(int i=0;i<temp.size();i++){
            mp[temp[i]]=rank;
            if(i<temp.size()-1&&temp[i+1]>temp[i]){
                rank++;
            }
        }
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            ans[i]=mp[arr[i]];
        }
        
        return ans;
    }
};