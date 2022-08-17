#include <bits/stdc++.h>

void reverse(vector<int> &p, int index){     //Function to reverse vector from given index to last of array
    
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
        
        if(p[i-1]<p[i] && temp == 0){    //To find the breaking point - meaning where an ele just less than prev one is present
            temp = p[i-1];
            index = i-1;
            i=n-1;  // to reset the for loop
        }
        
        if(temp!=0 && p[i]>temp){
            swap(p[index],p[i]);       //swap the ele found with the ele just larger than it (present on right side)
            reverse(p,index);
            return p;
        }
        
        if(temp == 0 && i==1){      //in case of descending order vector - when no next larger permutation is present
            reverse(p,-1);
            return p;
        }

    }
    
    return p;
}
