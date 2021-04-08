#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<string.h>

#define fi "input.txt" // Mac dinh ten file doc
#define fo "output.txt" // Mac dinh ten file xuat
using namespace std;

// Ham nay là viet y chang là ok
void docfile(int a[], int &n)
{
	FILE *fp=fopen(fi,"rt");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++)
	{
		fscanf(fp,"%d",&a[i]);
	}
	fclose(fp);
	cout<<"Doc file thanh cong!"<<endl;
}
// End

int soluong_ptchan(int a[],int n) // Dem so luong phan tu chan
{
	int dem = 0; // Ban dau no bien dem  = 0
	for(int i = 0; i < n; i++) // Duyet mang
	{
		if(a[i] % 2 == 0) // So chan la so chia het cho 2
		{
			dem++; // tang dem len
		}
	}
	return dem; // Return bien dem
}
int tong_ptchan(int a[],int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			sum += a[i]; // Y chang ham tren . Cong cac so chan lai
		}
	}
	return sum; // Return tong cac so chan
}
void xoaphantu(int a[], int &n, int vitrixoa)
{
	for(int i = vitrixoa ; i < n - 1; i++){ // Ham xoa phan tu vi tri k 
		// Hoc thuoc la ok ha`
		// Hoc thuoc ham xoa voi ham them phan tu trong mang 1 chieu viet lai thoi ha
		// Chi khac dieu kien thoi
		// Tai sao xoa no -- Them o dau hay xoa o dau thoi ha
        a[i] = a[i+1];
    }
    n--;
}
void xoaphantuchan(int a[], int &n)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] % 2 == 0)
		{
			xoaphantu(a,n,i);
		}
	}
}
void ghifile(int a[],int n)
{
	FILE *fp=fopen(fo,"wt");
	// Ham nay em cu ghi y chung cho den day
	
	int sluong = soluong_ptchan(a,n);
	int tong = tong_ptchan(a,n);
	xoaphantuchan(a,n);
	
	fprintf(fp,"%d\n",sluong); 
	fprintf(fp,"%d\n",tong);
	for(int i = 0; i < n; i++)
	{
		fprintf(fp,"%d\t",a[i]);
	}
	
	fclose(fp); // Dong file
	cout<<"Ghi file thanh cong!"<<endl;
}
int main()
{
	int a[100],n; // Khai bao
	docfile(a,n); // Goi tung ham ra thoi
	ghifile(a,n);
	
}

