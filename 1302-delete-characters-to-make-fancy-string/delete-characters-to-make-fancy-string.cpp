class Solution {
public:
    string makeFancyString(string s) {
        string str="";
        str.push_back(s[0]);
        int ctr=1; //this ctr will track each alphabet

        for(int i=1;i<s.size();i++){
            if(s[i]==str.back()){
                ctr++;
            }
            else{
                ctr=1;
            }
            if(ctr<3){
                str.push_back(s[i]);
            }
        }

        return str;
    }
};