#include <iostream>
#include <math.h>

using namespace std;



int main(){
	int n, i, j, k;
	cout << "Number of lines and columns: ";
		cin >> n ;
		
	float a[10][10];
	float S;
		
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n + 1; j++){
				cin >> a[i][j];
			}
		}
		cout << "Matrix x = " << endl;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n + 1; j++){
				cout << " " << a[i][j];
			}
			cout << endl ;
		}
	
	for(k = 1; k <= n-1; k++){
		
		if(a[k][k] != 0){
			for(i = k + 1; i <= n; i++){
				a[i][k] = a[i][k] / a[k][k];
					
					for(j = k + 1; j <= n + 1; j++){
						a[i][j] = a[i][j] - a[i][k] * a[k][j];
					}
			}
		}
		
		else{
			cout << "STOP"<< endl;
			break;
		}
	}
	
	if(a[n][n] == 0){
		cout << "Sistemul nu are sol unica!" << endl;
	}
	
	else{
		a[n][n + 1] = a[n][n + 1] / a[n][n];
	}
	
	for(i = n - 1; i >= 1; i--){
		S = 0;
			
			for( j = i + 1; j <= n; j++){
				S = S + a[i][j] * a[j][n + 1];
			}
			
			a[i][n + 1] = (a[i][n + 1] - S) / a[i][i];
	}
	
	for(i = 1; i <= n; i++){
		cout << " Solutia x" << i << "=" << a[i][n+1];
		cout << endl;
	}
	return 0;
}
