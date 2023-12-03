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
    string str1, str2;
    int i, freq1=0, freq2=0;
    char ch;

    cout<<"\nEnter first string: ";
    getline(cin, str1);
    cout<<"\nEnter second string: ";
    getline(cin, str2);

    for(ch='0'; ch<='Z'; ch++)
    {
        if(!isalnum(ch))
            continue;
        freq1= freqOfChar(str1, ch);
        freq2= freqOfChar(str2, ch);
        if(freq1 != freq2)
            break;
    }

    if(ch > 'Z')
        cout<<"\n\nAnagram strings!"<<endl<<endl;
    else
        cout<<"\n\nNOT Anagram strings!"<<endl<<endl;
}
//Eleven plus two, Twelve plus one
