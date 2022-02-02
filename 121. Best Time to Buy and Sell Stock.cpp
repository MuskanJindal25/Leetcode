class Solution {
public:
    int maxProfit(vector<int>& prices) {         // if we keeping track of buy sell index as well
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



// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {            // Time Complexity: O(n)   -- if only looking for max profit not index
//         int profit=0;
        
//         int fmin=prices[0];
//         int fmax=prices[0];
//         int sz = prices.size();
        
//         for(int i=1;i<sz;i++){
            
//             if(fmin>prices[i]){
//                 fmin = prices[i];
//                 fmax = 0;
//             }
//             else if (fmax<prices[i]){
//                 fmax = prices[i];
//             }
            
//             int x = fmax - fmin;
            
//             if(x>profit)
//                 profit = x;
            
//         }
        
//         return profit;
//     }
// };
