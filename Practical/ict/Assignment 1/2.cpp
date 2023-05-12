#include<bits/stdc++.h>
using namespace std;

int main()
{
 
    map<int,char>ma;
    for(int i=0;i<26;i++)
    {
        ma[i]=i+97;
    }
    string s;
    cin>>s;
    string sj;
    int j;
    cin>>j;
  
    for(int i=0;i<s.length();i++)
    {
        
        int k=j%26;
        int f=s[i]-'0'-49;
        k=f-k;
        if(k<0)
        k+=26;
        sj+=ma[k];

    }
    cout<<sj<<endl;
    
    return 0;
}