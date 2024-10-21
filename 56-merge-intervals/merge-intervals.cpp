class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
    
        int prev=intervals[0][0];
        int curr=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(curr>=intervals[i][0]){
                if(curr<intervals[i][1]){
                    curr=intervals[i][1];
                }
            }
        
            else{
                vector<int>temp;
                temp.push_back(prev);
                temp.push_back(curr);
                ans.push_back(temp);
                prev=intervals[i][0];
                curr=intervals[i][1];
              
            }
        }
        vector<int>temp;
        temp.push_back(prev);
        temp.push_back(curr);
        ans.push_back(temp);
        return ans;
    }
};