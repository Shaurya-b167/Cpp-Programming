#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string topiglatin(string word)
{
    string newWrd="", prevwrd="";
    char ch, chr;
    int i, len= word.length(), cnt=0;

    for(i=0; i<len; i++)
    {
        ch= word.at(i);
        chr= ch>='A' && ch<='Z'? ch : (char)(ch-32);
        if(chr=='A' || chr=='E' || chr=='O' || chr=='U' || chr=='I' || cnt>0)
        {
            cnt++;
            newWrd+= ch;
        }
        else
            prevwrd+= ch;
    }
    return (newWrd+prevwrd+"ay");
}

string getconverted(string sent)
{
    string wrd, newStr;
    char ch;
    int i, len= sent.length(), cnt=0;

    for(i=0; i<len; i++)
    {
        ch= sent.at(i);
        if(isalnum(ch))
            wrd+=ch;
        else if(wrd!="")
        {
            newStr+= topiglatin(wrd)+ch;
            wrd="";
        }
        else
            newStr+=ch;
    }
    return newStr;
}

int main()
{
    string str, newStr;
    cout<<"\nEnter a sentence to convert to pig latin:"<<endl;
    getline(cin, str);
    newStr= getconverted(str);

    cout<<"\n\nOUTPUT:\n"<<newStr<<endl<<endl;
}
