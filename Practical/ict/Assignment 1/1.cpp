#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char,char>m;
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
    for(int i=0;i<26;i++)
    {
         char c=ma[i];
         int k=(i+j)%26;
         char ck=ma[k];
         m[c]=ck;       
    }
    
    for(int i=0;i<s.length();i++)
    {
        
        sj+=m[s[i]];
    }
    cout<<sj<<endl;
    
    return 0;
}