/* 1023 Have Fun with Numbers
 * By Qyu, Oct 20, 2019.
 * Description: Easy Problem.
 * Submit State: Pass in second submit. Why? -> Attention to the description of the problem.
 */
#include<iostream>
#include<string>
using namespace std;

void printAns(string str1){
	// initiate
	int a1[25];
	int a2[25];
	int count1[10];
	int count2[10];
	fill(a1, a1+25, 0);
	fill(a2, a2+25, 0);
	fill(count1, count1+10, 0);
	fill(count2, count2+10, 0);
	// transform string to number
	int i = 0;
	for(; i<str1.length(); i++){
		int temp = str1[i] - '0';
		a1[i] = temp;
		
		count1[temp]++;
	}
	// double the number above
	int c = 0;
	for(int j = i-1; j>=0; j--){
		int temp = a1[j]*2 + c;
		if(temp > 9){
			a2[j] = temp%10;
			c = 1;
		}else{
			a2[j] = temp;
			c = 0;
		}
		
		count2[a2[j]]++;
	}
	// check if equal
	bool equal = true;
	// Here is the problem
	/*if(count1[0] > 0 || count2[0] > 0){
		equal = false;
	}*/
	for(int k=0; k<10; k++){
		if(count1[k] != count2[k]){
			equal = false;
			break;
		}
	}
	// output the result
	if(equal && c == 0){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	
	if(c == 1){
		cout<<c;
	}
	for(int k=0; k<i; k++){
		cout<<a2[k];
	}
	cout<<endl;
	
	return;
}

int main(){
	string str1;
	cin>>str1;
	printAns(str1);
	return 0;
}