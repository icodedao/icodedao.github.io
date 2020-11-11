#include<iostream>
using namespace std;
int d, m, y, dem = 0;
bool kiemtra(int d, int m, int y){
if(d < 0 || d > 31)
	return false;
else if(m < 0 || m > 12)
	return false;
else if(y < 100 || y > 3000)
	return false;
else return true;
}
int main(){
	
	// 1/1/2004 là ngày thu 5.
	/* --  7 ngày
	
	8/1 => thu 5 --> 8%7 = 1
	9/1 => thu 6 --> 9%7 = 2
	10/1 => thu 7 --> 10%7 = 3
	11/1 => CN --> 11%7 = 4
	12/1 => thu 2 --> 12%7 = 5
	13/1 => thu 3 --> 13%7 = 6
	14/1 => thu 4 --> 14%7 = 0
	
	*/
	
	cout << "ENTER DAY : ";
	cin >> d;
	cout << "ENTER MONTH : ";
	cin >> m;
	cout << "ENTER YEAR : ";
	cin >> y;
	if(kiemtra(d,m,y))
	{
		for(int i = 2004 ; i < y; i++)
		{
			if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
			{
				dem = dem + 366;
			}else dem = dem + 365;
		}
		for(int i = 1; i < m; i++){
			switch(m){
				case 1:
    			case 3:
    			case 5:
    			case 7:
    			case 8:
    			case 10:
    			case 12:
        			{
        				dem = dem + 31;
        				break;
					}
        	case 4:
    		case 6:
    		case 9:
    		case 11:
    			{
    				dem = dem + 30;
					break;
				}
        	 case 2:
        			{
        				if ((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)))
            				dem = dem + 29;
        				else
            				dem+=28;
					}
			}
		}
		dem = dem + d;
		int mod = dem%7;
		switch(mod){
			case 5:
				cout <<" THIS DAY IS MONDAY";
				break;
			case 6:
				cout <<" THIS DAY IS TUESDAY";
				break;
			case 0:
				cout <<" THIS DAY IS WEDNESDAY";
				break;
			case 1:
				cout <<" THIS DAY IS THURSDDAY";
				break;
			case 2:
				cout <<" THIS DAY IS FRIDAY";
				break;
			case 3:
				cout <<" THIS DAY IS SATUDAY";
				break;
			case 4:
				cout <<" THIS DAY IS SUNDAY";
				break;
			default:
				cout<<"Sai roi!";
				break;
		}
	}
	else cout<<"ERROR";
return 0;
}

