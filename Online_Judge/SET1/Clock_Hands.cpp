#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    double m,hora,angulo,horaAng,minutoAng;
    char dot;
    while(1){
        cin >> hora >> dot >> m;
        if(hora==0 && m==0) 
            break;
        horaAng=hora*30+(m/60)*30;
        minutoAng=m*6;
        angulo=(horaAng-minutoAng);
        if(angulo<0)
            angulo*=-1;
        if (angulo>180)
            angulo=360-angulo;
        printf("%.3f\n",angulo);
    }
    return 0;
}