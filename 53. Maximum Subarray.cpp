class Solution {
public:
    int maxSubArray(vector<int>& nums) {            //Kadane's Algorithm - O(n)
        
        int sum = 0;
        int fsum = nums[0];
        
        int sz = nums.size();
        int st=0,ed=0;
        
        for(int i =0; i<sz;i++){
            
            sum = sum + nums[i];
            
            if(sum>fsum){
            fsum = max(sum,fsum);   
            ed=i;                   // index of end is correct using this
            }
            
            if(sum<0){
                sum = 0;
                st = i;              // index of start is wrong using this
            }
        }
        
        cout<<st<<" "<<ed;
        
        return fsum;
    }
};

// int maxSubArray(vector<int>& nums) {      *****Approach 1 - O(n^2)********
        
//         int sz = nums.size();
        
//         vector<int> prefixsum;
//         // vector<int> A[sz];
//         int sum = 0;
//         int fsum = INT_MIN;
        
//         prefixsum.push_back(nums[0]);
        
//         for(int i=1;i<sz;i++){
//             prefixsum.push_back(prefixsum[i-1] + nums[i]);
//         }
        
//         for(int i=0;i<sz;i++){
           
//             for(int j=i;j<sz;j++){
//                 sum = 0;
//                 sum = prefixsum[j] - prefixsum[i] + nums[i];
//                 fsum = max(fsum,sum);
//             }
//         }
        
//         return fsum;
//     }
