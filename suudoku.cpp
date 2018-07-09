#include <bits/stdc++.h>
using namespace std;

int s[9][9];
int flag[9][9];

bool h(int a, int b){
	int x;
	int y;
	if(0 <= a && a  <= 2){
		x = 0;
	}else if(3 <= a && a <= 5){
		x = 3;
	}else{
		x = 6;
	}
	if(0 <= b && b <= 2){
		y = 0;
	}else if(3 <= b && b <= 5){
		y = 3;
	}else{
		y = 6;
	}/*
	for(int i = 0; i < 9; i++){
		if(s[a][i] == s[a][b] && i != b)return false;
		if(s[i][b] == s[a][b] && i != a)return false;
	}*/
	for(int i = 0 + x; i <= 2 + x; i++){
		for(int j = 0 + y; j <= 2 + y; j++){
			if(s[i][j] == s[a][b] && i != a && j != b)return false;
		}
	}
	return true;
}

int dfs(int a, int b){
	cout << endl;
	int k;
	cin >> k;
	if(k == 1){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cout << s[i][j];
			}
			cout << endl;
		}
		cout << endl << flag[a][b] << endl;
	}


	if(flag[a][b] == 1){
		if(a == 8 && b == 8)return 0;
		if(b == 8){
			return dfs(a + 1, 0);
		}else{
			return dfs(a, b+1);
		}
	}else if(flag[a][b] == 0){
		if(s[a][b] == 0)s[a][b] = 1;
		
		if(h(a, b) == true){
			if(a == 8 && b == 8)return 0;
			if(b == 8){
				return dfs(a + 1, 0);
			}else{
				return dfs(a, b+1);
			}
		}else{
			if(b = 0 && s[a][b] >= 9){
				int x = 1, y = 8;
				while(flag[a - x][y]){
					if(y != 0){
						y--;
					}else{
						y = 8;
						x++;
					}
				}
				s[a][b] = 0;
				return dfs(a - x, y);
			}else if(s[a][b] >= 9 && b != 0){
				int x = 0, y = 0;
				while(flag[a - x][b - y]){
					if(b - y != 0){
						y++;
					}else{
						y = 8 - b;
						a++;
					}
				}
				s[a][b] = 0;
				return dfs(a - x, b - x);
			}else{
				s[a][b]++;
				return dfs(a, b);
			}
		}
	}
	return 0;
}

int main(){
	for(int i = 0; i < 9; i++){
		//cin >> s[i];
		for(int j = 0; j < 9; j++){
			cin >> s[i][j];	
			if(s[i][j] != 0){
				flag[i][j] = 1;
			}else{
				flag[i][j] = 0;
			}
		}
	}
	cout << endl;
	int x = 0, y = 0;
	dfs(x, y);

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
