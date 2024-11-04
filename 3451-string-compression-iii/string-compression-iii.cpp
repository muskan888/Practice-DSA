class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int ctr=1;
        char curr=word[0];
        for(int i=1;i<word.size();i++){
            if(word[i]==curr&&ctr<9){
                ctr++;
            }
            else{
                comp+=to_string(ctr);
                comp.push_back(curr);
                curr=word[i];
                ctr=1;
            }
             
        }
         comp.push_back(ctr+'0');
          comp.push_back(curr);
        return comp;
    }
};