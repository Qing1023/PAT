/* 1017 Queueing at Bank
 * By Milkyway, Aug 31, 2019.
 */
 
 #include<iostream>
 #include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 const int N = 10003;
 
 struct person{
	 int arrive;
	 int served;
	 bool operator<(const person p){
		 if(arrive < p.arrive) return true;
		 else return false;
	 }
	 void operator=(const person p){
		 arrive = p.arrive;
		 served = p.served;
	 }
 }Q[N], W[103];
 int n, k;
 
int main(){
	 scanf("%d %d", &n, &k);
	 int count=0;
	 for(int i=0; i<n; i++){
		 int h, m, s, served;
		 scanf("%d:%d:%d %d", &h, &m, &s, &served);
		 int time = h*60*60 + m*60 + s;
		 if(time > 61200) continue; // filtering the people that arrive at late 17:00
		 Q[count].arrive = time;
		 Q[count].served = served * 60;
		 count++;
	 }
	 
	 int all = count;
	 if(all == 0){
		 printf("0.0\n");
		 return 0;
	 }
	 sort(Q, Q + all);

	 int now_time = 8*3600;
	 int wait_time = 0;
	 for(int i=0; i<min(all, k); i++){
		 W[i] = Q[i];
		 wait_time += max(0, now_time - W[i].arrive);
	 }
	 count = min(all, k);
	 while(count < all){
		 int min_served = W[0].served;
		 for(int i=1; i<k; i++){
			 min_served = min(min_served, W[i].served);
		 }
		 now_time += min_served;
		 for(int i=0; i<k; i++){
			 W[i].served -= min_served;
			 if(W[i].served == 0){
				 W[i] = Q[count];
				 count++;
				 wait_time += max(0, now_time - W[i].arrive);
			 }
		 }
	 }
	 double avg_time = double(wait_time)/all/60;
	 printf("%.1f\n", avg_time);
	 return 0;
 }