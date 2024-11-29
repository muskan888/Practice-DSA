class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        string str="aeiou";
        int ctr=0;
        for(int i=left;i<=right;i++){
            if(str.find(words[i][0])!=string::npos && str.find(words[i][words[i].size()-1])!=string::npos){
                cout<<words[i]<< " ";
                ctr++;
            }
        }
        return ctr;
    }
};