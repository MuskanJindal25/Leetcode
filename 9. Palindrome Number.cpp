class Solution {
public:
    bool isPalindrome(int x) {
        
        /* Approach 2 */
        
        int len=0;
        vector<int> num;
        int temp;
        
        if(x<0)
            return false;
        
        while(x > 0){
            temp = x%10;
            x = x/10;
            num.push_back(temp);
            len++;
        }
        
        // for(int i=0; i<len;i++)
        // {
        //     cout<<num[i];
        // } 
        // cout<<endl<<len;
        
        
        for(int i=0; i<len/2;i++)
        {
            if(num[i]!=num[len-i-1])
                return false;
        }      
        
        return true;
        
        /* Approach 1 */
//         string s = to_string(x);
//         int len = s.size();
        
//         for(int i=0;i<len/2;i++)
//         {
//             if(s[i]!=s[len-1-i])
//                 return false;
//         }
       
//         return true;
          
    }
};
