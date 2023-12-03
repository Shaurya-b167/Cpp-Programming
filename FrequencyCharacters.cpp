#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int freqOfChar(string str, char ch)
{
    int freq=0, i, len= str.length();
    for(i=0; i<len; i++)
        if(toupper(str[i]) == toupper(ch))
            freq++;
    return freq;
}

int main()
{
    string str, sstr;
    int len, i, freq;
    char ch;

    cout<<"Enter the string to find the frequency of its characters:"<<endl;
    getline(cin, str);
    len= str.length();

    cout<<"\nCHARACTER\t\tFREQUENCY"<<endl;
    for(i=20; i>=1; i--)
        for(ch=0; ch<='Z'; ch++)
        {
            freq= freqOfChar(str, ch);
            if(freq > 0 && i==freq)
            {
                sstr= ch==' '? "<space>" : string(1, ch)+"\t";
                cout<<sstr<<"\t\t\t"<<freq<<endl;
            }
        }

    cout<<endl<<endl;
    return 1;
}
