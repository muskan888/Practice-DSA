class Solution {
public:
    int numRabbits(vector<int>& answers) {
       unordered_map<int,int>mp;
       int ans=0;
       for(int i=0;i<answers.size();i++){
        mp[answers[i]]++;
       }

       for(auto it:mp){
        int membersInEachGroup=it.first+1;
        int groupsNeeded=ceil((double)it.second/membersInEachGroup);
        ans=ans+(groupsNeeded*membersInEachGroup);
       }
       return ans;
    }
};