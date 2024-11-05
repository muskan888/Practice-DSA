class Solution {
public:
    int minChanges(string s) {
        int ctr=0;
        for(int i=0;i<s.size();i=i+2){
            if(s[i]!=s[i+1]) ctr++;

        }
        return ctr;
    }
};