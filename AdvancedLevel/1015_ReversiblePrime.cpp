/* 1015 Reversible Prime
 * By Milkyway, Aug 23, 2019.
 */
#include<iostream>
#include<cmath>

using namespace std;

bool is_prime(int n){
	if(n == 1 || n == 0) return false;
	for(int i=2; i < int(sqrt(n))+1; i++){
		if(n%i == 0) return false;
	}
	return true;
}

void is_reversible_prime(int n, int r){
	if(!is_prime(n)) {
		cout<<"No"<<endl;
		return;
	}
	int rev_num_withr=0;
	while( n > 0 ){
		int mod = n%r;
		rev_num_withr = rev_num_withr*r + mod;
		n = n/r;
	}
	if(is_prime(rev_num_withr)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return;
}

int main(){
	while(true){
		int n, radix;
		cin>>n;
		if(n < 0 ) break;
		cin>>radix;
		is_reversible_prime(n, radix);
	}
	return 0;
}