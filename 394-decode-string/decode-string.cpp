class Solution {
public:
    string decodeString(string s) {
        stack<char> St;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string tempString="";
                while(!St.empty() && St.top()!='[' ){
                tempString+=St.top();
                St.pop();
                }
                //pop the '['
                St.pop();
                
                    string digit="";
                while(!St.empty() && isdigit(St.top())){
                    digit+=St.top();
                    St.pop();
                }
                reverse(digit.begin(),digit.end());
                int num=stoi(digit);
                reverse(tempString.begin(),tempString.end());
               string decoded="";
                 for(int i=0;i<num;i++){
                    decoded+=tempString;
                }
                for(char ch: decoded)
                {
                    St.push(ch);
                }
                
                
            }
            else{
                St.push(s[i]);
            }
        }
        string res="";
        while(!St.empty()){
            //prepend the characters 
            res=St.top()+res;
            St.pop();
        }
        return res;
    }
};