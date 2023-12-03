#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
using namespace std;

//The below function checks whether the string word is a pure numeric string or not
float getnumber(string word) 
{
	string numstr= "";
	int dotcnt= 0;
	for(char ch: word)
	{
		if(isalpha(ch) || (ch=='.' && dotcnt>1))
			return -999;
		else if(isdigit(ch) || ch=='.')
			numstr+= ch;
	}
	return stof(numstr);
}

//The below function calculates the result of the operation with n1 and n2 and returns the result
float getresult(float n1, float n2, char opr)
{
	switch(opr)
	{
		case '+': return n1+n2;
		case '-': return n1-n2;
		case '*': return n1*n2;
		case '/': return n1/n2;
	}
	return -999;
}

int main()
{
	string word, sent;
	char opr;
	float result, num;
	int cnt= 0;

	cout<<"Sentence:"<<endl;
	getline(cin, sent);
	cout<<"\nOperator: ";
	cin>>opr;
    
    if(ispunct(sent.back()))
    	sent.erase(sent.length()-1, 1); //removing the sentence-ending punctuation

    stringstream ss(sent); 
    while(ss >> word) 
    {
    	num = getnumber(word);
    	if(num != -999)
    		result= ++cnt==1 ? num : getresult(result, num, opr);
    }
    cout<<"\nResult: $"<<result<<endl<<endl;
	return 1;
}
//John bought a pen for $13.50, ice cream for $17, and a pair of shoes for $116.95.