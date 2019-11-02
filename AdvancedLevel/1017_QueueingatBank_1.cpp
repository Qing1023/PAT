/* 1017 Queueing at Bank
 * By Milkyway, Aug 31, 2019.
 */
 #include<cstdio>
 #include<algorithm>
 #include<vector>
 using namespace std;
 
 struct person{
	 int arrive;
	 int served;
	 bool operator<(const person& p){
		 if(arrive < p.arrive) return true;
		 else return false;
	 }
 };
 
 vector<person> Q;
 
 int W[101];
 
 int main(){
	 int n, k;
	 scanf("%d %d", &n, &k);
	 for(int i=0; i<n; i++){
		 int h, m, s, served;
		 scanf("%d:%d:%d %d", &h, &m, &s, &served);
		 int arrive = h*3600 + m*60 + s;
		 if(arrive > 61200) continue;
		 person temp = {arrive, served*60};
		 Q.push_back(temp);
	 }
	 
	 sort(Q.begin(), Q.end());
	 
	 int all_wait_time = 0;
	 fill(W, W + k, 28800);
	 for(int i=0; i<Q.size(); i++){
		 int min_served_time = W[0], index = 0;
		 for(int j=1; j<k; j++){
			 if(min_served_time > W[j]){
				 min_served_time = W[j];
				 index = j;
			 }
		 }
		 if(W[index] < Q[i].arrive){
			 W[index] = Q[i].arrive + Q[i].served;
		 }else{
			 all_wait_time += (W[index] - Q[i].arrive);
			 W[index] += Q[i].served;
		 }
	 }
	 if(Q.size()==0){
		 printf("0.0\n");
	 }else{
		 printf("%.1f\n", double(all_wait_time)/Q.size()/60);
	 }
	 return 0;
 }