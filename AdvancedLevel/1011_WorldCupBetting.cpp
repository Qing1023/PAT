// 1011 World Cup Betting
// By Milkyway, 2019/6/5
#include<iostream>
#include<iomanip>

using namespace std;
char results[3];
char WTL[3] = {'W','T','L'};

double maxValue(int num){
    double maxV=0.0;
    double temp;
    for(int i=0; i<3; i++){
        cin>>temp;
        if(maxV < temp){
            results[num] = WTL[i];
        }
        maxV = max(maxV, temp);
    }
    return maxV;
}

void calMaxProfit(){
    double maxProfit=1.0;
    for(int i=0; i<3; i++){
        maxProfit *= maxValue(i);
    }
    for(int i=0; i<3; i++){
        cout<<results[i]<<" ";
    }
    cout<<fixed<<setprecision(2)<<(maxProfit*0.65 - 1)*2;
}

int main(){
    calMaxProfit();
    return 0;
}
