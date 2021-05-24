#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<string.h>

#define fi "input.txt" // Mac dinh ten file doc
#define fo "output.txt" // Mac dinh ten file xuat
using namespace std;

// Ham nay là viet y chang là ok
void docfile(int a[100][100], int &m, int &n)
{
	FILE *fp=fopen(fi,"rt");
	fscanf(fp,"%d",&m);
	fscanf(fp,"%d",&n);
	for(int i=0;i<m;i++)
	{
		for(int j = 0; j < n; j++)
		{
			fscanf(fp,"%d",&a[i][j]);
		}
	}
	fclose(fp);
	cout<<"Doc file thanh cong!"<<endl;
}
int tong_pt(int a[100][100],int m, int n)
{
	
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j <n; j++)
		{
			sum += a[i][j];
		}
	}
	return sum;
}
int ktra_snt(int x)
{
	if(x < 2 ) return 0;
	else
	for(int i = 2; i <= x/2 ; i++ )
	{
		if(x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int dem_sluong_snt(int a[100][100],int m, int n)
{
	int dem_snt = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j =0 ; j < n; j++)
		{
			if(ktra_snt(a[i][j]) == 1)
			{
				dem_snt++;	
			}
		}
	}
	return dem_snt;
}

void ghifile(int a[100][100],int m, int n)
{
	FILE *fp=fopen(fo,"wt");
	// Ham nay em cu ghi y chung cho den day
	
	int tongmang = tong_pt(a,m,n);
	int sl_snt = dem_sluong_snt(a,m,n);
	
	fprintf(fp,"%d\n",tongmang); 
	fprintf(fp,"%d\n",sl_snt);
	
	for(int i = 0; i < n; i++)
	{
		int maxc = a[0][i];
		for(int j =0 ; j < m; j++)
		{
			if(a[j][i] > maxc)
			{
				maxc = a[j][i];
			}
		}
		fprintf(fp,"%d\t",maxc);
	}
	
	
	
	fclose(fp); // Dong file
	cout<<"Ghi file thanh cong!"<<endl;
}
int main()
{
	int a[100][100],m,n; // Khai bao
	docfile(a,m,n); // Goi tung ham ra thoi
	ghifile(a,m,n);
	
}

