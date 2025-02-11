class Solution {
public:
    string removeOccurrences(string s, string part) {
      string res="";
      int m=part.size();


        for(int i=0;i<s.size();i++){
            res=res+s[i];
            if(res.size()>=m && res.substr(res.size()-m)==part){
                res.erase(res.size()-m);
            }
        }
        return res;
    }
};