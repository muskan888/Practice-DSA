class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st;
        for(int i=0;i<banned.size();i++){
           if(banned[i]<=n){
             st.insert(banned[i]);
           }
        }
        int ctr=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)!=st.end()){
                continue;
            }
            if(sum+i>maxSum){
                break;
            }
             sum=sum+i;
            ctr++;
           
        }
        return ctr;

    }
};