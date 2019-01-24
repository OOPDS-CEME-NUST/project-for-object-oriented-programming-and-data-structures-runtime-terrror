#include <iostream>
using namespace std;

int linear (int [], int);

int main ()
{
	int arr[10]={1,2,3,4,45,6563,643,31,1,2};
	int index=0;
	index=linear(arr,1);
	if (index!=false)
		cout << index;
}

int linear (int arr[], int key )
{
	static int i=0;
	if (arr[i]==key)
		return true;
	else if (i==9)
		return false;
	else
	{
		i++;
		return linear (arr,key);
	}
}

/*
#include <iostream>
#include <string.h>
using namespace std;

int main ()
{
	char num[100]="Alv mnm bnmnb                      ghhhhhhhhhhhhhh";
	char num1[122]="c Ali & Wasadadasaqar is A gO   Od boy";
//	cout << strlen (num)<<endl;
//	cout << strupr (num)<<endl;
//	cout << strncpy (num,num1,35)<<endl;
//	cout << num1<< endl;
//	cout << strncpy (num1,num, 10)<<endl;
//	cout << num1<< endl;
	cout << strchr (num1, 'O');
//	cout << strncmp (num, num1, 10)<<endl;
 
	cout << strlen(num);

}*/