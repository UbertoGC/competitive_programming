#include <iostream>
using namespace std;
char tablero[8][8];
int ataque[8][8];
int main(){
    string datos;
    while(cin>>datos){
        int f=0,c=0;
        for (int i = 0; i < datos.size(); i++){
            if(datos[i]=='/'){
                for (; c < 8; c++) {
					tablero[f][c] = '-';
                    ataque[f][c]=0;
				}
				f++;
                c=0;
            }
            else if(isdigit(datos[i])){
                for (int l=0; l < datos[i]-'0'; l++){
                    tablero[f][c]='-';
                    ataque[f][c]=0;
                    c++;
                }
            }
            else if(isalpha(datos[i])){
                tablero[f][c]=datos[i];
                ataque[f][c]=1;
                c++;
            }
        }
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if(tablero[i][j]!='-'){
                    if(tablero[i][j]=='P'){
                        if(i>0){
                            if(j>0){
                                if(tablero[i-1][j-1]=='-')
                                    ataque[i-1][j-1]++;
                            }
                            if(j<7){
                                if(tablero[i-1][j+1]=='-')
                                    ataque[i-1][j+1]++;
                            }
                        }
                    }
                    if(tablero[i][j]=='p'){
                        if(i<7){
                            if(j>0){
                                if(tablero[i+1][j-1]=='-')
                                    ataque[i+1][j-1]++;
                            }
                            if(j<7){
                                if(tablero[i+1][j+1]=='-')
                                    ataque[i+1][j+1]++;
                            }
                        }
                    }
                    if(tablero[i][j]=='K'||tablero[i][j]=='k'){
                        if (i + 1 < 8) {
                            ataque[i + 1][j]++;
                            if (j + 1 < 8)
                                ataque[i + 1][j + 1]++;
                            if (j - 1 >= 0)
                                ataque[i + 1][j - 1]++;
                        }
                        if (j + 1 < 8)
                            ataque[i][j + 1]++;
                        if (j - 1 >= 0)
                            ataque[i][j - 1]++;
                        if (i - 1 >= 0) {
                            if (j + 1 < 8)
                                ataque[i - 1][j + 1]++;
                            ataque[i - 1][j]++;
                            if (j - 1 >= 0)
                                ataque[i - 1][j - 1]++;
                        }
                    }
                    if(tablero[i][j]=='R'||tablero[i][j]=='r'||tablero[i][j]=='Q'||tablero[i][j]=='q'){
                        int k=i-1;
                        while(k>=0){
                            if(tablero[k][j]=='-')
                                ataque[k][j]++;
                            else
                                break;
                            k--;
                        }
                        int l=j-1;
                        while(l>=0){
                            if(tablero[i][l]=='-')
                                ataque[i][l]++;
                            else
                                break;
                            l--;
                        }
                        k=i+1;
                        while(k<8){
                            if(tablero[k][j]=='-')
                                ataque[k][j]++;
                            else
                                break;
                            k++;
                        }
                        l=j+1;
                        while(l<8){
                            if(tablero[i][l]=='-')
                                ataque[i][l]++;
                            else
                                break;
                            l++;
                        }
                    }
                    if(tablero[i][j]=='Q'||tablero[i][j]=='q'||tablero[i][j]=='B'||tablero[i][j]=='b'){
                        int k=i-1,l=j-1;
                        while (k>=0&&l>=0){
                            if(tablero[k][l]=='-')
                                ataque[k][l]++;
                            else
                                break;
                            k--;
                            l--;
                        }
                        k=i-1;
                        l=j+1;
                        while (k>=0&&l<8){
                            if(tablero[k][l]=='-')
                                ataque[k][l]++;
                            else
                                break;
                            k--;
                            l++;
                        }
                        k=i+1;
                        l=j-1;
                        while (k<8&&l>=0){
                            if(tablero[k][l]=='-')
                                ataque[k][l]++;
                            else
                                break;
                            k++;
                            l--;
                        }
                        k=i+1;
                        l=j+1;
                        while (k<8&&l<8){
                            if(tablero[k][l]=='-')
                                ataque[k][l]++;
                            else
                                break;
                            k++;
                            l++;
                        }
                    }
                    if(tablero[i][j]=='N'||tablero[i][j]=='n'){
                        int k_1=i+2,k_2=i-2,k_3=i+1,k_4=i-1;
                        int l_1=j+1,l_2=j-1,l_3=j+2,l_4=j-2;
                        if(k_1<8){
                            if(l_1<8)
                                if(tablero[k_1][l_1]=='-')
                                    ataque[k_1][l_1]++;
                            if(l_2>=0)
                                if(tablero[k_1][l_2]=='-')
                                    ataque[k_1][l_2]++;
                        }
                        if(k_2>=0){
                            if(l_1<8)
                                if(tablero[k_2][l_1]=='-')
                                    ataque[k_2][l_1]++;
                            if(l_2>=0)
                                if(tablero[k_2][l_2]=='-')
                                    ataque[k_2][l_2]++;
                        }
                        if(k_3<8){
                            if(l_3<8)
                                if(tablero[k_3][l_3]=='-')
                                    ataque[k_3][l_3]++;
                            if(l_4>=0)
                                if(tablero[k_3][l_4]=='-')
                                    ataque[k_3][l_4]++;
                        }
                        if(k_4>=0){
                            if(l_3<8)
                                if(tablero[k_4][l_3]=='-')
                                    ataque[k_4][l_3]++;
                            if(l_4>=0)
                                if(tablero[k_4][l_4]=='-')
                                    ataque[k_4][l_4]++;
                        }
                    }
                }
            }
        }
        int resultado=0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if(ataque[i][j]==0)
                    resultado++;
        cout<<resultado<<endl;
    }
    return 0;
}