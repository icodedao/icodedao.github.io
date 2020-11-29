#include<iostream>
using namespace std;
int main () {
	int h;
	cout << "Enter H = ";
	cin >> h;
	for ( int i=1 ; i<=h ; i++) {
		for ( int j=1 ; j<= 2*h ; j++) {
			if ( j >= i && j<= h ) {
				cout <<"* ";
			}
			else if (j > 2*h-i ) {
				cout <<"* ";
			}
			else {
				cout <<"  ";
			}
		}
	cout <<"\n";
		
	}
	for ( int i=1 ; i<=h ; i++) {
		for ( int j=1 ; j<= 2*h ; j++) {
			if ( j<= h-i+1) {
				cout <<"* ";
			}
			else if ( j>h && j <= 2*h-(h-i) ) {
				cout <<"* ";
			}
			else {
				cout <<"  ";
			}
	
		}
	cout <<"\n";
	}
	
}
