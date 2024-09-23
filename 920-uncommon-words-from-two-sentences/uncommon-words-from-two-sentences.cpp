class Solution {
public:
   vector<string> v1;
   vector<string>v2;
    void fillVector(string s){
        int i=0;
        while(i<s.size()){
            string word;
            while(s[i]!=' '){
                word.push_back(s[i]);
                i++;
            }
            v1.push_back(word);
            i++;
        }

    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v1;
        vector<string>v2;
        int i=0;
        string word;
        while(i<=s1.size()){
            if(s1[i]==' ' || i==s1.size()){
                v1.push_back(word);
                word="";
            }
            else{
                word.push_back(s1[i]);
            }
            i++;
            
        }
         i=0;
        while(i<=s2.size()){
            if(s2[i]==' ' || i==s2.size()){
                v2.push_back(word);
                word="";
            }
            else{
                word.push_back(s2[i]);
            }
            i++;
            
        }
       unordered_map<string,int> mp;

       for(int i=0;i<v1.size();i++){
        mp[v1[i]]++;
       }
       for(int i=0;i<v2.size();i++){
        mp[v2[i]]++;
       }
       vector<string> ans;
        for(auto it:mp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
    return ans;
    }

};