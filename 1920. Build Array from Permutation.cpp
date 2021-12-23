class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> temp;
        
        for(int i=0; i<nums.size(); i++){
            temp.push_back(nums[i]);
        }
        
        for(int n=0; n<nums.size();n++){
            int x = temp[n];
            ans.push_back(nums[x]);
        }
        
        return ans;    
    }
};
