/**
*121. Best Time to Buy and Sell Stock
*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
*Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


*Time complexity: O(n)
*Space complexity: O(n)
**/



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();

        if ( (0 == size) || (1 == size) )
            return 0;

        int buy_price = prices[0];
        int max_profit = 0;

        for ( int i = 1; i< size; ++i ) {
            //Stock should not be bought on last day. So check if (i<size-1)
            if ( buy_price > prices[i]){
                buy_price = prices[i];
            }
            else {
                //check for current day sale profit is greater than existing profit as of now
               if ( (prices[i]-buy_price) > max_profit)
                    max_profit = prices[i]-buy_price;
            }
        }

        return max_profit;
    }
};