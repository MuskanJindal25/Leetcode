#include <bits/stdc++.h>

void reverse(vector<int> &p, int index){
    
    int front = index +1;
    int back = p.size() - 1;
    
    while(back>front){
        swap(p[front],p[back]);
        front++;
        back--;
    }
    
}

vector<int> nextPermutation(vector<int> &p, int n)
{
    if(n==1)
        return p;
    
    int temp = 0;
    int index;
    
    for(int i=n-1;i>0;i--){
        
        if(p[i-1]<p[i] && temp == 0){
            temp = p[i-1];
            index = i-1;
            i=n-1;
        }
        
        if(temp!=0 && p[i]>temp){
            swap(p[index],p[i]);
            reverse(p,index);
            return p;
        }
        
        if(temp == 0 && i==1){
            reverse(p,-1);
            return p;
        }

    }
    
    return p;
}
