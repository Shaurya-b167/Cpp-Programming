#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int frequency(string srchword, string sent)
{
    string wrd;
    int i, len= sent.length(), freq=0;
    char ch;
    transform(srchword.begin(), srchword.end(), srchword.begin(),
                     [](unsigned char c){ return tolower(c);});
    for(i=0; i<len; i++)
    {
        ch= sent[i];
        if(isalnum(ch))
           wrd+= ch;
        else if(wrd!="")
        {
            transform(wrd.begin(), wrd.end(), wrd.begin(),
                     [](unsigned char c){ return tolower(c);});
            if(wrd==srchword)
                freq++;
            wrd="";
        }
    }
    return freq;
}

string getremoved(string delword, string sent)
{
    string wrd, newStr, chkwrd;
    int i, len= sent.length();
    char ch;
    transform(delword.begin(), delword.end(), delword.begin(),
                     [](unsigned char c){ return tolower(c);});
    for(i=0; i<len; i++)
    {
        ch= sent[i];
        if(isalnum(ch))
           wrd+= ch;
        else if(wrd!="")
        {
            chkwrd= wrd;
            transform(chkwrd.begin(), chkwrd.end(), chkwrd.begin(),
                     [](unsigned char c){ return tolower(c);});
            newStr+= chkwrd==delword? "" : wrd;
            newStr+= ch;
            if(ch!=' ')
                newStr+=" ";
            wrd="";
        }
    }
    return newStr;
}

string getreplaced(string srchword, string repword, string sent)
{
    string wrd, newStr, chkwrd;
    int i, len= sent.length();
    char ch;
    transform(srchword.begin(), srchword.end(), srchword.begin(),
                     [](unsigned char c){ return tolower(c);});
    for(i=0; i<len; i++)
    {
        ch= sent[i];
        if(isalnum(ch))
           wrd+= ch;
        else if(wrd!="")
        {
            chkwrd= wrd;
            transform(chkwrd.begin(), chkwrd.end(), chkwrd.begin(),
                     [](unsigned char c){ return tolower(c);});
            newStr+= chkwrd==srchword? repword+ch : wrd+ch;
            if(ch!=' ')
                newStr+=" ";
            wrd="";
        }
    }
    return newStr;
}

int main()
{
    string str, removed, replaced, srchwrd, delwrd, repwrd;
    cout<<"\nEnter a sentence to perform word operations:"<<endl;
    getline(cin, str);
    cout<<"\nWord to search for: ";
    getline(cin, srchwrd);
    cout<<"Word to remove: ";
    getline(cin, delwrd);
    cout<<"Word to replace with: ";
    getline(cin, repwrd);

    int freq= frequency(srchwrd,str);
    removed= getremoved(delwrd, str);
    replaced= getreplaced(srchwrd, repwrd, str);

    cout<<"\n\nOUTPUT:\nFrequency of '"<<srchwrd<<"': "<<freq
        <<"\n\nSentence after removing all occurrences of '"<<srchwrd<<"':"<<endl<<removed
        <<"\n\nSentence after replacing all occurrences of '"<<srchwrd<<"' with '"<<repwrd<<"'"
        <<endl<<replaced<<endl<<endl;
}
//Mary had a Little lamb, which had a LITTLE tail, having Little, liTTLE nodes on it.