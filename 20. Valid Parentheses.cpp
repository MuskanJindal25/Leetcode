class Solution {
public:
    bool isValid(string s) {
        bool ot = 0;
        
        map<char, char> mp;  //({'{','}'},{'[',']'},{'(',')'})
        
        mp.insert({'{','}'});
        mp.insert({'[',']'});
        mp.insert({'(',')'});
        
        int sz = s.size();
        
        stack <char> sta;
        
        //cout<<sz;
        
        for(int i=0; i<sz ; i++){
            if(s[i] == '{' | s[i] =='[' | s[i] =='('){
                sta.push(s[i]);
            }
            else{
                if(!sta.empty()){
                    char top = sta.top();
                    sta.pop();
                    if(s[i]!=mp[top])
                        return 0;
                    else
                        ot = 1;
                }
                else
                    return 0; 
            }
        }
        
        if(!sta.empty())
            return 0;
         
        return ot;
    }
};
