class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs[0].empty()){
            return "";
        }

        
        int j=0;
        bool flag=true;
        string str="";
        while(flag==true){
            if(j>=strs[0].size()){
                break;
            }
            for(int i=1;i<strs.size();i++) {
                if(j>=strs[i].size() || strs[i][j]!=strs[0][j]){
                    flag=false;
                    break;
                }
            }
                if(flag){
                    str.push_back(strs[0][j]);
                    j++;
                }
            }
        
        return str;
    }
};