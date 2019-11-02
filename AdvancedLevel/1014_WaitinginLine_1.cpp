/* 1014 Waiting in Line
 * By Milkyway, July 21, 2019.
 * It runs in O() in time and O() in space.
 * Algorithm: 
 */
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

struct window{
	int poptime, endtime;
	queue<int> q;
};

int main(){
	int n, m, k, q, index=1;
	// input data
	scanf("%d%d%d%d", &n, &m, &k, &q);
	vector<int> svd_time(k + 1), time(k + 1);
	vector<bool> Sorry(k + 1, false);
	for(int i=1; i<=k; i++){
		scanf("%d", &svd_time[i]);
	}
	// calculate...
	vector<window> W(n + 1);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(index <= k){
				W[j].q.push(svd_time[index]);
				if(i==0){
					W[j].poptime = W[j].endtime = svd_time[index];
				}
				else{
					if(W[j].endtime >= 540){
						Sorry[index] = true;
					}
					W[j].endtime += svd_time[index];
				}
				time[index] = W[j].endtime;
				index++;
			}
		}
	}
	while(index <= k){
		int min_time = 100000;
		for(int i=0; i<n; i++){
			min_time = min(min_time, W[i].q.front());
		}
		for(int i=0; i<n; i++){
			if(min_time == W[i].q.front() && index <= k){
				W[i].q.pop();
				W[i].q.push(svd_time[index]);
				W[i].poptime += W[i].q.front();
				if(W[i].endtime >= 540){
					Sorry[index] = true;
				}
				W[i].endtime += svd_time[index];
				time[index] = W[i].endtime;
				index++;
			}
		}
	}
	// output result
	for(int i=0; i<q; i++){
		int que;
		scanf("%d", &que);
		if(Sorry[que]){
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n", (time[que] + 480)/60, (time[que] + 480)%60);
		}
	}
	// end
	return 0;
}