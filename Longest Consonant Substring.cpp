#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string longestConsSub(string str)
{
	string wrd, maxCons;
	char ch, chr;
	int i, len= sent.length(), cnt=0, max=0;

	for(i=0; i<len; i++)
	{
		ch= str.at(i);
		if(isalpha(ch))
		{
			chr= tolower(ch);
			if(chr!='a' && chr!='e' && chr!='i' && chr!='o' && chr!='u')
			{
				cnt++;
			    wrd+=ch;
			}
			else if(wrd!="")
		    {
			    if(cnt>max)
			    {
				   maxCons= wrd;
				   max= cnt;
			    }
			    cnt=0;
			    wrd="";
		    }
		}
	}
	return maxCons;
}

int main()
{
	string str, maxCons;

	cout<<"Enter the string to generate the longest consonant substring:"<<endl;
	getline(cin, str);

    maxCons= longestConsSub(str);

    cout<<"\nThe longest consonant substring: "<<maxCons<<endl<<endl;
    return 1;
}
