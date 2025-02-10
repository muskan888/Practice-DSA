class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto i:s){
            if(isdigit(i)){
                st.pop();
            }
            else{
                st.push(i);
            
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};