#include<iostream>
using namespace std;
void nhapmang(int *&a, int &n)
{
	cout<<"Nhap so luong pt: ";
	cin>>n;
	a = new int [n];
	for(int i = 0 ; i < n; i++)
	{
		cout<<"Nhap pt: ";
		cin>>a[i];
	}
}
void xuatmang(int *a, int n )
{
	cout<<"Xuat mang \n";
	for(int i = 0 ; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
}
void hoanvi(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void sapxeptang(int *a, int n)
{
	for(int i = 0; i < n -1 ; i++)
	{
		for(int j = i+1 ; j < n; j++)
		{
			if(a[j] < a[i])
			{
				hoanvi(a[j],a[i]);
			}
		}
	}
	cout<<"\nMang sau khi sap xep\n";
	xuatmang(a,n);
}
void xoapt(int a[], int &n, int vitri)
{
	for(int i = vitri ; i < n - 1; i++){
        a[i] = a[i+1];
    }
    n--;
}
void xoa_pty(int *a, int &n, int y)
{
	cout<<"\nNhap vao y: ";
	cin>>y;
	
	for(int i = 0 ; i < n; i++)
	{
		if(a[i] == y)
		{
			xoapt(a,n,i);
			return;
		}
	}
	
}
int main()
{
	int *a,n,y;
	nhapmang(a,n);
	xuatmang(a,n);
	sapxeptang(a,n);
	xoa_pty(a,n,y);
	xuatmang(a,n);
	return 0;
}
