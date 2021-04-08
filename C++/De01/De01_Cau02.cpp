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

int giatrilonnhat(int a[], int n)
{
	int max = a[0]; // Gan cho max = gia tri ban dau
	
	for(int i = 1; i < n; i ++) // Duyet mang tu dau` den cuoi cung`
	{
		if(a[i] > max) // Neu thang nao lon hon max
		{
			max = a[i]; // Thi gan max = chinh no
		}
	}
	return max; // Return max -- max la so lon nhat mang
}
int giatrilonthu2(int a[],int n, int max)
{
	
	int max2 = -INT_MAX; // Gan la so nho nhat trong int - ( am ) vo cung`
	for(int i = 0; i < n ; i++) // Duyet mang tu dau den cuoi mang
	{
		if(a[i] > max2 && a[i] != max) // Neu gap thang nao lon hon no
		// Và nho hon max ( thang lon nhat mang ) 
		// Thi no la thang lon thu 2 mang
		{
			max2 = a[i]; // Gan cho no la so lon thu 2 cua mang
		}
	}
	return max2; // Return max2 ( So lon thu 2 cua mang)
}
int kiemtra_nt(int x) // Ham kiem tra nguyen to
{
	if(x < 2) return 0; // Nho hon 2 thi chac chan khong phai nguyen to
	for(int i = 2; i <= x/2; i++) // i = 2 dem x/2
	{
		if(x % i == 0) // Neu chia het thi khong phai nguyen to
		{
			return 0; // Quy uoc 0 la khong phai nguyen to
		}
	}
	return 1; // Quy uoc 1 là nguyen to
}
int snt_lonhonmang(int max)
// Cau nay la nguoi ta keu tim so nguyen to > tat ca cac phan tu trong mang
// Thi` minh may so lon nhat trong mang ra
// Kiem tra no phai so nguyen to hay khong
// Khong phai thi tang no len
// Chung nao no la nguyen to thì thoi
{
	for(int i = max + 1; i < MAX_INT ; i++) // i = thang lon nhat mang
	// i nho hon + vo cung`
	{
		if(kiemtra_nt(i) == 1) // Ham kiem tra nguyen to tren
		{
			return i; // Neu la nguyen to thi return no ngay
		}
	}
}
int soluong_snt(int a[],int n)
{
	int dem = 0; //Ban dau em cho sluong = 0
	for(int i = 0; i < n; i++) // Duyet mang
	{
		if(kiemtra_nt(a[i]) == 1) // Neu ham kiem tra nguyen to dung
		{
			dem++; // Tuc la so do la nguyen to
			// dem + them 1 don vi
		}
	}
	return dem; // Return tong sluong nguyen to
}
void ghifile(int a[],int n)
{
	FILE *fp=fopen(fo,"wt");
	// Ham nay em cu ghi y chung cho den day
	
	int max = giatrilonnhat(a,n); 
	// Khai bao 1 bien max de nhan ve gia tri cua ham giatrilonnhat
	
	int max2 = giatrilonthu2(a,n,max);
	// Khai bao 1 bien max2 de nhan ve gia tri cua ham giatrilonthu2
	
	int snt_max = snt_lonhonmang(max);
	// Khai bao bien snt_max de nhan ve gia tri cua ham snt_lonhonmang
	
	int sl_snt = soluong_snt(a,n);
	// Khai bao bien sl_snt de nhan ve gia tri ham soluong_snt
	
	// fprintf(fp,"%d\t",max); 
	// Em cu ghi y chang nhu vay a'
	// Neu la int thi %d, float %f, char %c, string thi %s
	// con` (max) thi` em de bien em can ghi vao`
	fprintf(fp,"%d\t",max); 
	fprintf(fp,"%d\n",max2);
	fprintf(fp,"%d\n",snt_max);
	fprintf(fp,"%d\n",sl_snt);
	
	fclose(fp); // Dong file
	cout<<"Ghi file thanh cong!"<<endl;
}
int main()
{
	int a[100],n; // Khai bao
	docfile(a,n); // Goi tung ham ra thoi
	ghifile(a,n);
	
}

