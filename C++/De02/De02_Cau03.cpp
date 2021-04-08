#include<iostream>
using namespace std;
void nhapmang(int **&a, int &d, int &c) //
{
	cout<<"Nhap vao so dong: ";
	cin>>d;
	cout<<"Nhap vao so cot: ";
	cin>>c;
	
	a = new int *[d]; // Cap phat dong cho mang co d dong`
	for(int i = 0; i < d; i++)
	{
		a[i] = new int [c]; // trong d dong` co c cot
		
		for(int j = 0; j < c; j++)
		{
			printf("Nhap vao phan tu thu a[%d][%d]: ",i,j);
			cin>>a[i][j];
		}
	}
}
void xuatmang(int **a, int d, int c)
{
	for(int i = 0; i < d; i++) // Duyet mang theo dong
	{
		for(int j = 0; j < c; j++) // Duyet mang theo cot
		{
			cout<<a[i][j]<<"\t"; // Xuat tung phan tu ra 
		}
		cout<<"\n";
	}
}
void dem_sole(int **a, int d, int c) // Ham dem so le trong mang
{
	int dem = 0; // Tao bien dem so luong = 0
	for(int i = 0; i < d; i++) // Duyet mang theo dòng
	{
		for(int j = 0; j < c; j++) // Duyet mang theo cot
		{
			if(a[i][j]% 2 != 0) // Khong chia het cho 2 la so le
			{
				dem++; // Neu no khong chia het thi tang bien dem len 1 don vi
			}
		}
	}
	cout<<"Co "<<dem<<" so le trong mang!"; // xuat ra ket qua co bao nhieu so le trong mang
}
void min_dong(int **a, int d, int c) // Tim gia tri nho nhat trong  dong
{
	for(int i = 0; i < d; i++) // Duyet mang theo dong
	{
		int mind = a[i][0]; // Gan  thang dau tien trong dong` ma nho nhat ( min min )
		for(int j = 0; j < c; j++) // Duyet theo cot
		{
			if(a[i][j] < mind) // Thay thang nao nho hon no nua thi`
			{
				mind = a[i][j]; // Gan bien mind = thang nho hon
			}
		}
		cout<<mind<<endl; // xuat so nho nhat tung dong ra man hinh
	}
}
int main()
{
	int **a, d, c;
	nhapmang(a,d,c);
	xuatmang(a,d,c);
	dem_sole(a,d,c);
	min_dong(a,d,c);
	delete(a);
	
}
