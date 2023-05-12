#include<bits/stdc++.h>

using namespace std;

int main()
{

    string text;
    getline(cin,text);
    map<char,int>m;
    for(int i=0;i<text.length();i++)
    {
        if(text[i]!=' ')
        m[text[i]]++;
    }
    int maxi=0;
    char c;
    for(auto x:m)
    {
        if(x.second>maxi)
        {
            maxi=x.second;
            c=x.first;

        }
    }
    // cout<<c<<endl;
    
    int key=abs((int)(101-c));
    cout<<key<<endl;
    return 0;
}