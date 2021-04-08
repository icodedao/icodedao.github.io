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
void giatrilonnhat(int **a,int d, int c) // Gia tri lon nhat
{
	int max = a[0][0]; // Luon cho thang dau tien =  max
	for(int i = 0; i < d ; i++) // Duyet mang theo dong
	{
		for(int j = 0; j < c; j++) // Duyet mang theo cot
		{
			if(a[i][j] > max) // Neu thay thang nao lon hon max
			{
				max = a[i][j]; // Gan max = no'
			}
		}
	}
	cout<<"Gia tri lon nhat mang : "<<max<<endl; // In ra so lon nhat mang
}
/* // Ham nay chua lam xong kip
void tongpt_trencot(int **a, int d, int c) 
{
	
	for(int i = 0; i < c; i++)
	{
		int sum = 0;
		for(int j = 0; j < d; j++)
		{
			sum += a[i][j];
		}
		cout<<sum<<endl;
	}
}*/
int main()
{
	int **a, d, c;
	nhapmang(a,d,c);
	xuatmang(a,d,c);
	giatrilonnhat(a,d,c);
//	tongpt_trencot(a,d,c);
	delete(a);
	
}
