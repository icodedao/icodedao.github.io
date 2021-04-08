#include<iostream>
using namespace std;
int main()
{
	int Arr[] = {6,5,0,8,10,4};
	// Arr 0 = 6 ... Arr 5 = 4
	int *p;
	p = &Arr[1]; // Phan tu 1 cua Arr[1] = 5
	cout<<*p<<endl;// 5
	
	p = p - 1 ;  // Phan tu 0 cua Arr[0] = 6
	cout<<*p<<endl; //6
	
	p = &Arr[2]; // Phan tu 2 cua Arr[2] = 0
	cout<<*p<<endl;
	
	*p = *p + *(p-1) - *(p+3);  // Phan tu 0 cua Arr[0] = 20
	// *p = 0
	// p - 1 lùi ve 1 -> Arr[2-1] = 5
	// p + 3 tien len 3 ->  Arr[2+3] = 4
	// 0 + 5 - 4 = 1 
	
	cout<<*p<<endl; // 1
	return 0;
}
