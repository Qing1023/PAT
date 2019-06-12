// 1002 A+B for Polynomials, PAT
// By Milkyway, 2019/2/12
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
	int k;
	float N[1005];
	cin>>k;
	int ni;
	float ai;
	fill(N, N+1005, 0.0);
	for(int i=0; i<k; i++){
		cin>>ni>>ai;
		N[ni]=ai;
	}
	cin>>k;
	for(int i=0; i<k; i++){
		cin>>ni>>ai;
		N[ni] += ai;
	}
	int K=0;
	for(int i=0; i<1005; i++){
		if(N[i] != 0){
			K++;
		}
	}
	cout<<K;
	for(int i=1000; i>=0; i--){
		if(N[i] != 0){
			cout<<fixed<<setprecision(1)<<" "<<i<<" "<<N[i];
		}
	}
	cout<<endl;
	return 0;
}
