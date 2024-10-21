class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int s=0;
        int e=1;
        while(e<prices.size()){
            if(prices[s]<prices[e]){
                maxi=max(maxi,prices[e]-prices[s]);
                e++;
            }
            else{
                s=e;
                e=s+1;
            }
        }
        return maxi;
    }
};