class Solution {
public:
    int solveUsingRecursion(vector<int>&prices, int i, int buy, int limit,  vector<vector<vector<int>>>&dp ){
        if(i==prices.size()){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        if(dp[i][buy][limit]!=-1){
            return dp[i][buy][limit];
        }
        int profit=0;
        //buy
        if(buy)
        {
            int buyProfit=-prices[i]+solveUsingRecursion(prices,i+1,0,limit,dp);
            int dontbuy=0+solveUsingRecursion(prices,i+1,1,limit,dp);
            profit=max(buyProfit,dontbuy);
        }
        //sell
        else{
            int sellProfit=prices[i]+solveUsingRecursion(prices,i+1,1,limit-1,dp);
            int dontsell=0+solveUsingRecursion(prices,i+1,0,limit,dp);
            profit=max(sellProfit,dontsell);
        }
        dp[i][buy][limit]=profit;
        return dp[i][buy][limit];
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp (prices.size(),(vector<vector<int>>(2,vector<int>(k+1,-1))));
        return solveUsingRecursion(prices,0,1,k,dp);

    }
};