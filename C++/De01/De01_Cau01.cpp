#include<iostream>
using namespace std;
int main()
{
	int Arr[] = {20,10,1,0,5,4}; // Khai bao 1 mang
	//  a 0 = 20 ; a 1 = 10 ... a 5 = 4
	
	int *p;
	p = &Arr[0]; // Phan tu 0 cua Arr[0] = 20 -- so voi mang Arr
	// gia tri cua p duoc gan cho gia tri cua Arr[0] = 20
	cout<<*p<<endl;//20
	
	p = &Arr[3];  // Phan tu 0 cua Arr[3] = 0 - so voi mang Arr
	// gia tri cua p duoc gan cho gia tri cua Arr[3] = 0
	cout<<*p<<endl; // 0
	
	*p = *p + *(p-1) + *(p+2);  // Phan tu 0 cua Arr[0] = 20
	// Vi tri cua p hien tai la 3
	// p - 1 lui` lai 1 cai Arr[2] = 1
	// p + 2 tang them 2 Arr[5] = 4
	// Ket qua = 5
	
	cout<<*p<<endl; // 5
	return 0;
}
