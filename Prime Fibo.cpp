#include <iostream>
using namespace std;

int main()
{
    char *primeFibos="";
    int lim1, lim2, i, j, a=0, b=1, c;
    cout<<"Enter the lower limit: ";
    cin>>lim1;
    cout<<"Enter the upper limit: ";
    cin>>lim2;

    cout<<"\nThe Prime Fibonacci numbers between "<<lim1<<" and "<<lim2<<
                " are:\n";
    for(a=0, b=1; c<=lim2; c=a+b)
    {
        a=b;
        b=c;
        if(c<lim1)
            continue;
        for(j=2; j<=c/2; j++)
            if(c%j==0)
               break;
        if(j>c/2 && c>1)
            cout<<c<<", ";
    }
    cout<<endl<<endl;
}
