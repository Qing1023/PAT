/* 1014 Waiting in Line
 * By Milkyway, July 21, 2019.
 * It runs in O() in time and O() in space.
 * Algorithm: 
 */
 #include<iostream>
 #include<iomanip>
 #include<vector>
 #include<ctime>
 
 using namespace std;
 
 clock_t starttime, endtime;
 
 const int INF = 0x7fffffff;
 const int MAX_W = 25;
 const int MAX_K = 1005;
 const int MAX_Q = 1005;
 
 int n, m, k, q;
 vector<pair<int, int> > W[MAX_W]; 
 int cus_pro_time[MAX_K]; // customer's served time.
 int end_time[MAX_K];
 int que[MAX_Q]; // the number of queries.
 
 void input_data(){
	 cin>>n>>m>>k>>q;
	 for(int i=1; i<=k; i++){
		 cin>>cus_pro_time[i];
	 }
	 for(int i=1; i<=q; i++){
		 cin>>que[i];
	 }
	 starttime = clock();
 }
 
 void find_time(){
	 // initialize n windows with k(k>nm?) customers
	 int count=1; // the 
	 for(int i=0; i<m; i++){
		 for(int j=0; j<n; j++){
			 // when only count <= k, then...
			 if(count <= k){
				W[j].push_back(make_pair(count, cus_pro_time[count]));
				count++;
			 }
		 }
	 }	
	 
	 int timer=0; // loop variable, if timer > 540 loop ends.
	 while(true){
		 int min_time = INF;
		 // take the next people will finished transcation from n windows.
		 for(int i=0; i<n; i++){
			 if(!W[i].empty())
				min_time = min(W[i].front().second, min_time);
		 }
		 timer += min_time;
		 if(timer > 540) break;
		 // calculate the time people spend for transcation.
		 for(int i=0; i<n; i++){
			 if(W[i].empty()) continue;
			 if(W[i].front().second == min_time){
				 end_time[W[i].front().first] = timer;
				 W[i].erase(W[i].begin());
				 if(count <= k)
				 {
					 W[i].push_back(make_pair(count, cus_pro_time[count]));
					 count++;
				 }
			 }
			 else{
				 W[i].front() = make_pair(W[i].front().first, W[i].front().second - min_time);
			 }
		 }
	 }
 }
 
 void output(){
	 for(int i=1; i<=q; i++){
		 if(end_time[que[i]] != 0){
			 int hour = end_time[que[i]]/60 + 8;
			 int minute = end_time[que[i]]%60;
			 cout<<setfill('0')<<setw(2)<<hour<<":"<<setfill('0')<<setw(2)<<minute;
		 }
		 else{
			 cout<<"Sorry";
		 }
		 cout<<endl;
	 }
 }
 
 int main(){
	 input_data();
	 find_time();
	 output();
	 endtime = clock();
	 //cout<<"\nRunning time: "<<endtime-starttime<<"ms."<<endl;
	 return 0;
 }