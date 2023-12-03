#include <iostream>
using namespace std;

int main()
{
    int n, cn, cnt;
    cout<<"Enter an integer for prime factorization: ";
    cin>>n;
    cn=n;

    cout<<"\nPrime factorization for "<<n<<":\n"<<n<<" = ";
    for(cn=n, cnt=2; cn>1; cnt++)
        if(cn%cnt==0)
        {
            cn/=cnt;
            cn<=1? cout<<cnt : cout<<cnt<<" x ";
            cnt--;
        }
        cout<<endl<<endl;
}
