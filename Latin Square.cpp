#include <iostream>
using namespace std;

int *getcolumn(int square[][10], int n, int c)
{
	int i, *column= new int[10];
	for(i=0; i<n; i++)
		column[i]= square[i][c];
	return column;
}

bool hasallvalues(int arr1[], int n1, int arr2[], int n2)
{
	int i=0, j=0;
	for(i=0; i<n1; i++)
	{
		for(j=0; j<n2; j++)
			if(arr1[i]==arr2[j])
				break;
	    if(j==n2)
	    	break;
	}
	return i<n1? false : true;
}

bool hasduplicates(int arr[], int n)
{
	int i=0, j=0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<i; j++)
			if(arr[i]==arr[j])
				break;
		if(j<i)
			break;
	}
	return i<n? true : false;
}

bool isLatinsquare(int square[][10], int n)
{
	int *col;
	for(int i=0; i<n; i++)
	{
		if(i==0)
		    if(hasduplicates(square[i], n))
		    	return false;
        col= getcolumn(square, n, i);
		if(i!=0)
	        if(!hasallvalues(square[0], n, square[i], n) || 
			      !hasallvalues(square[0], n, col, n))
			    return false;
	}
	return true;
}

int main()
{
	int square[10][10], n, i, j;
	cout<<"Enter the dimension (n x n) of the square array: ";
	cin>>n;

	cout<<"\nEnter the elements for the square array:\n";
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			cout<<"Enter element #("<<(i+1)<<", "<<(j+1)<<"): ";
			cin>>square[i][j];
		}

	cout<<"\n\nThe elements of the 2-D array as entered:\n";
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			cout<<square[i][j]<<"\t";
		cout<<endl;
	}

	cout<<"\nThe given 2-D array is "<<(isLatinsquare(square, n)? "" : "NOT ")<< "a Latin Square!"<<endl<<endl;
	return 1;
}