#include<bits/stdc++.h>
using namespace std;
void decrypt(string x)
    {
    string text;
    for(int n=0;n<26;n++)
        {
        text = "";
        for(int i=0;i<x.length();i++)
            {
            if(isupper(x[i]))
                {
                if((x[i] - n - 65)<0)
                    text += 91 + (x[i] - n - 65);
                else
                    text += (x[i] - n - 65)%26 + 65;
                }
            else if(islower(x[i]))
                {
                if((x[i] - n - 97) < 0)
                    text += 123 + (x[i] - n - 97);
                else
                    text += (x[i] - n - 97)%26 + 97;
                }
            else
                text += x[i];
            }
        cout << "plain text for key " << n << " :- " << text << endl;
        }
    }
int main()
{
 
    string text;
    getline(cin,text);
    decrypt(text);  
    return 0;
}