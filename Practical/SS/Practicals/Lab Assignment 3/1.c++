#include<bits/stdc++.h>

using namespace std;
void jaiishriram(string s)
{
  map<char,int>m;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
         m[s[i]]++;
    }
    if(m['a']==n)
    {
        cout<<"String Recognized and it is a*"<<endl;
        return;
    }
    else if(m.size()<=2)
    {
        string k=s;
        sort(k.begin(),k.end());
        if(k==s)
        {
           cout<<"String Recognized and it is a*b+"<<endl; 
           return;
        }
    }
    cout<<"String not Recognized"<<endl; 
}
int main()
{
    string s;
    cin>>s;
    jaiishriram(s);
    
    return 0;
}