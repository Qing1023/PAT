// 1009 Product of Polynomials
// By Milkyway, 2019/6/2.
// It runs in O(N11*N22) in time and O(1)=4e3 in space.
#include<iostream>
#include<iomanip>

using namespace std;

const int N = 1e3+3;

double A[N], B[N];
double pro[2*N];

int product(int num1, int num2){
    for(int i=num1; i>=0; i--){
        for(int j=num2; j>=0; j--){
            pro[i+j] += (A[i]*B[j]);
        }
    }
    int num=0;
    for(int i=0; i<=num1+num2; i++){
        if(pro[i] != 0.0){
            num++;
        }
    }
    return num;
}

int main(){
    int n, m;
    int maxExp1, maxExp2;
    cin>>n;
    cin>>maxExp1;
    cin>>A[maxExp1];
    n--;
    while(n--){
        int exp;
        cin>>exp;
        cin>>A[exp];
    }
    cin>>m;
    cin>>maxExp2;
    cin>>B[maxExp2];
    m--;
    while(m--){
        int exp;
        cin>>exp;
        cin>>B[exp];
    }
    int num = product(maxExp1, maxExp2);
    cout<<num<<" ";
    int i=maxExp1+maxExp2;
    cout<<i<<" "<<fixed<<setprecision(1)<<pro[i];
    for(i--; i>=0; i--){
        if(pro[i] != 0.0)
            cout<<" "<<i<<" "<<fixed<<setprecision(1)<<pro[i];
    }
    return 0;
}
