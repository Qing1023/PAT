// 1005 Spell it Right
// By Milkyway, 2019/5/31.
#include<iostream>

using namespace std;

string str[10];

void init(){
    // initialize the string array.
    str[0]="zero";
    str[1]="one";
    str[2]="two";
    str[3]="three";
    str[4]="four";
    str[5]="five";
    str[6]="six";
    str[7]="seven";
    str[8]="eight";
    str[9]="nine";
}

int sumStr(string s){
    int sum=0;
    for(int i = 0; i < s.length(); i++){
        sum += (s[i] - '0');
    }
    return sum;
}

void output(int sum){
    int temp[5];
    int i = 0;
    if(sum == 0){ // notice: here needs to thinking the situation of sum=0.
        temp[i++] = 0;
    }
    while(sum>0){
        temp[i++] = sum%10;
        sum /= 10;
    }
    cout<<str[temp[--i]];
    while(i--){
        cout<<" "<<str[temp[i]];
    }
}

int main(){
    init();
    string N;
    cin>>N;
    int sum = sumStr(N);
    output(sum);
    return 0;
}
