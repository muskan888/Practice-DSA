class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        string ans="";

        for(int i=0;i<=pattern.size();i++){
            st.push(i+1);
            if(i==pattern.size() || pattern[i]=='I'){
              //  pop all the elements from stack since prev elements should be smaller than next one
                while(!st.empty()){
                    //since its int stack, we need to convert it to char to append to string
                    ans.push_back(st.top()+'0');
                    st.pop();
                }

            }
        }
        return ans;
    }
};