/* 1019 General Palindromic Number 
 * By Milkyway, Sep 01, 2019
 */
 
 #include<cstdio>
 
 int main(){
	 int n, b;
	 scanf("%d %d", &n, &b);
	 int temp_array[40];
	 int temp = n, i = 0;
	 while(temp > 0){
		 temp_array[i] = temp%b;
		 temp /= b;
		 i++;
	 }
	 bool is_palin = true;
	 for(int j=0; j<(i/2); j++){
		 if(temp_array[j] != temp_array[i-j-1]){
			 is_palin = false;
			 break;
		 }
	 }
	 if(is_palin){
		 printf("Yes\n");
		 
	 }else{
		 printf("No\n");
	 }
	 printf("%d", temp_array[i-1]);
	 for(int j=i-2; j>=0; j--){
		printf(" %d", temp_array[j]);
	 }
	 return 0;
 }