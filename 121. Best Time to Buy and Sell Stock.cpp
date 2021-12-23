class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int maxprofit = 0;
        int maxprofitsellidx = -1;
        int maxprofitbuyidx = -1;
        int buyx = -1;
        if( sz == 1 )
            return 0;
        int buyprice = prices[0];
        buyx = 0;
        for( int i=1;i<sz;i++){
            if( prices[i] > buyprice ){
                if( maxprofit < prices[i] - buyprice ){
                    maxprofitsellidx = i;
                    maxprofitbuyidx = buyx;
                    maxprofit = prices[i] - buyprice;
                }        
            }
            else{
                buyprice = prices[i];
                buyx = i;
            }
        }
        cout <<"Sell :"  <<  prices[maxprofitsellidx] << " Buy :" << prices[maxprofitbuyidx]<< endl;
        return maxprofit;
    }
    // Start se we will iterate till we fimnd an element less than the previous one
    // First thing thing that we can buy
    
    // length 1 -> 0
    // first, second -> first is big > second : buy second
    // firs, second -> first is small - buy first profit second - first => min possible profit
};
