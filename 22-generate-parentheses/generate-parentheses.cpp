class Solution {
public:
    void push_generated_ans(int n, int open, int close, string output, vector<string>&ans){
        //base case
        if(open==0 && close==0){
            ans.push_back(output);
            return;
        }
        //inclde open bracket
        if(open>0){
            output.push_back('(');
            push_generated_ans(n,open-1, close,output,ans);
            //backtrack
            output.pop_back();
            }

        //include closing bracket
        if(close>open){
            output.push_back(')');
            push_generated_ans(n,open,close-1,output,ans);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
      string output;
      vector<string>ans;
      int open=n;
      int close=n;
      push_generated_ans(n,open,close,output,ans);
      return ans;

    }

};