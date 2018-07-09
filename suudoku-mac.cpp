#include <bits/stdc++.h>

using namespace std;
//9*9の二次元配列　sが数独の盤面データ、flagが元から数字が入っていたかの判定用
int s[9][9];
int flag[9][9];



//s[a][b]が数字として適しているかの判定
bool h(int a, int b){
    return true;
}



//深さ優先探索
int dfs(int a, int b){
    //s[a][b]が元からあった数字なら
    if(flag[a][b] != 1){
        //s[8][8]の場合
        if(b == 8 && a == 8){
            //処理を終了
            return 0;
        //s[a][8] && a < 8の場合
        }else if(b == 8 && a < 8){
            //再帰、次の段の最初のマスに移る
            return dfs(a + 1, 0);
        //s[a][b] a < 8 && b < 8の場合
        }else{
            //再帰、次のマスに移る
            return dfs(a, b + 1);
        }
    //s[a][b]にもともと数字が入っていなかったら
    }else{
        //もしますになにも数字が入っていない(この場合ゼロ)だったら
        if(s[a][b] == 0){
            //s[a][b]に1を代入
            s[a][b] = 1;
        }
        //もしs[a][b]の値が数独のルールに適していたら
        if(h(a, b)){
            //もしbが8かつaが8なら
            if(a == 8 && b == 8){
                return 0;
            //もしaが８未満かつbが8だったら
            }else if(b == 8 && a < 8){
                return dfs(a + 1, 0);
            //それbが8未満なら
            }else if(b < 8){
                return dfs(a, b + 1);
            //それ以外はエラーとみなす
            }else{
                cout << "errror" << endl;
                return 0;
            }
        //違反していたら(数が重なってたりしたら)
        }else{
            //もしs[a][b]が9だった場合
            if(s[a][b] == 9){
                s[a][b] = 0;
                //もしbが0だったら
                if(b == 0){
                    //変数x, yを宣言
                    int x = 0, y = 8;
                    //最初から入っていた数じゃ無くなるまで繰り返す
                    while(flag[a - x][y] == 0){
                        if(y == 0){
                            x++;
                            y = 8;
                        }else{
                            y--;
                        }
                    }
                    return dfs(a - x, y);
                //もしbが0じゃなかったら
                }else{
                    int x = 0; y = 0;
                    while(flag[a- x][b - y] == 0){
                        if(b - y == 0){
                            x++;
                            y = b - 8;
                        }else{
                            y++;
                        }
                    }
                    return dfs[a - x][b - y];
                }
                
            }else{
                s[a][b]++;
                return dfs(a, b);
            }
        }
    }
    return 0;
}


int main(){
    //配列の初期化
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            s[i][j] = 0;
            flag[i][j] = 0;
        }
    }
    //配列に入力をぶち込む
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> s[i][j];
            if(s[i][j] == 0){
                flag[i][j] = 1;
            }
        }
    }
    //深さ優先探索開始
    dfs(0, 0);
    //結果を出力
    for(int i = 0; i < 9; i++){
        for(int j = 0; j  < 9; j++){
            cout << s[i][j];
        }
        cout << endl;
    }
    
    
    
    
    
}
