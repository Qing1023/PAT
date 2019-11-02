/* 1016 Phone Bills
 * By Milkyway, Aug 24, 2019.
 */
#include<iostream>
#include<utility>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;

int toll[24];
string record[1005];

pair<int, double> cal(string str1, string str2){
	int day1 = (str1[0]-'0')*10 + str1[1]-'0';
	int day2 = (str2[0]-'0')*10 + str2[1]-'0';
	int hour1 = (str1[3]-'0')*10 + str1[4]-'0';
	int hour2 = (str2[3]-'0')*10 + str2[4]-'0';
	int min1 = (str1[6]-'0')*10 + str1[7]-'0';
	int min2 = (str2[6]-'0')*10 + str2[7]-'0';
	int total_min = (day2 - day1)*24*60 + hour2*60 + min2 - hour1*60 - min1;
	// cal day
	double temp = 0;
	for(int i=0; i<24; i++){
		temp += (toll[i]*60);
	}
	double cost = (day2 - day1)*temp;
	// cal first day
	for(int i=0; i<hour1; i++){
		cost -= (toll[i]*60);
	}
	cost -= (toll[hour1]*min1);
	// cal last day
	for(int i=0; i<hour2; i++){
		cost += (toll[i]*60);
	}
	cost += (toll[hour2]*min2);
	cost /= 100.0;
	return make_pair(total_min, cost);
}

int main(){
	// input data
	for(int i=0; i<24; i++){
		cin>>toll[i];
	}
	int n;
	cin>>n;
	string read_enter;
	getline(cin, read_enter);
	for(int i=0; i<n; i++){
		getline(cin, record[i]);
	} // input data end
	
	sort(record, record + n);

	double total = 0;
	for(int i=1; i<n; i++){
		string temp = record[i].substr(0, record[i].find(':'));
		// output customer's name and total amount
		if(temp != record[i-1].substr(0, record[i-1].find(':'))){
			if(total != 0){
				cout<<"Total amount: $"<<fixed<<setprecision(2)<<total<<endl;
				total = 0;
			}
			continue;
		} // end
		// output the time(in minute) and cost of every long-distance call
		int pos = record[i].find('-') - 1;
		if(record[i][pos] == 'f'){
			if(record[i-1][pos-1] == 'n'){
				string substr1 = record[i-1].substr(record[i-1].find(':')+1, 8);
				string substr2 = record[i].substr(record[i].find(':')+1, 8);
				pair<int, double> min_cost = cal(substr1, substr2);
				if(total == 0.0 && min_cost.second != 0.0){
					cout<<temp<<endl;
				}
				total += min_cost.second;
				cout<<substr1<<" "<<substr2<<" "<<min_cost.first<<" "<<"$"<<fixed<<setprecision(2)<<min_cost.second<<endl;
			}
		}// end
	}
	if(total != 0.0)
		cout<<"Total amount: $"<<fixed<<setprecision(2)<<total<<endl;
	return 0;
}
