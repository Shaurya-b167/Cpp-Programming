#include <iostream>
using namespace std;

bool isprime(int n)
{
    if(n<2)
        return false;
    for(int i=2; i<=n/2; i++)
        if(n%i==0)
            return false;
    return true;
}

int main()
{
    int n, i;
    cout<<"Enter a number to display its goldbach conjecture pairs: ";
    cin>>n;
    if(n<2 || n%2!=0)
        cout<<"\nThere are no Goldbach conjecture pairs for the number!";
    else
    {
       printf("\n\nGoldbach Prime Pairs for %d are: ", n);
       for(i=3; i<=n/2; i++)
          if(isprime(i) && isprime(n-i))
            cout<<"\n"<<n<<" = "<<i<<" + "<<n-i;
    }
    cout<<endl<<endl;
}
