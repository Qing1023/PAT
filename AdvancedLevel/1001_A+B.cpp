// 1001 A+B Format, PAT
// By Milkyway, 2019/2/11
#include<iostream>
#include<cstdlib>
using namespace std;

void add_format(int a, int b){
	int sum = a+b;
	// output the sign of the number.
	if(sum < 0 ){
		cout<<"-";
		sum= -sum;
	}else if(sum == 0){
		cout<<0<<endl;
		return;
	}
	int k=0, j=0;
	char output[15];
	while(sum > 0){
		output[k++] = '0'+sum%10;
		sum /= 10;
		j++;
		if(j%3 == 0){
			output[k++]=',';
			j=0;
		}
	}
	for(int i=k-1; i>=0; i--){
		if(i == k-1 && output[i] == ','){
			continue;
		}
		cout<<output[i];
	}
	cout<<endl;
}

int main(){
	int a, b;
	cin>>a>>b;
	add_format(a, b);
	return 0;
}
