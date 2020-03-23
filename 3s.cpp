#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main(){
	int n;
	cin>>n;	
	int a[n][n];	
	for(int i0=0;i0<n-1;i0++){
		for(int j0=i0+1;j0<n;j0++){
			a[i0][j0] = 0;
		}
	} 	
	for(int i=0;i<n;i++){		
		a[i][i] = 1;
		a[i][0] = 1;		
	}	
	for(int k = 2;k<n;k++){		
		for(int m = 1; m<k; m++){			
			a[k][m] = a[k][m-1] + a[k-1][m];
		}
	}
	for(int si=0;si<n;si++){		
		for(int sj=0;sj<n;sj++)		
			cout<<setw(5)<<a[si][sj]<<" ";	
		cout<<endl;
	}		
	return 0;
} 
