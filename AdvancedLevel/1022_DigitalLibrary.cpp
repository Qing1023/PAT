/*1022-Digital-Library
 *by milkyway  
 *Sep 07, 2019
 *STL practice, now state: failed
 */
#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;

multimap<string, int> title;
multimap<string, int> author;
multimap<string, int> keyword;
multimap<string, int> publisher;
vector<priority_queue<int, vector<int>, greater<int> > > year(2003);

void inputData(int n){
	for(int i=0; i<n; i++){
		int id, year_t;
		string title_t, author_t, keyword_t, publisher_t;
		scanf("%d", &id);
		getchar(); // read '\n' from the tail of the first line.
		getline(cin, title_t);
		getline(cin, author_t);
		getline(cin, keyword_t);
		getline(cin, publisher_t);
		scanf("%d", &year_t);
		title.insert(make_pair(title_t, id));
		author.insert(make_pair(author_t, id));
		stringstream check(keyword_t);
		string temp;
		while(getline(check, temp, ' ')){
			keyword.insert(make_pair(temp, id));
		}
		publisher.insert(make_pair(publisher_t, id));
		year[year_t - 1000].push(id);
	}
	return;
}

void bystring(string str, multimap<string, int>& library) {
	string temp = str.substr(3, str.size()-3);
	pair<multimap<string, int>::iterator, multimap<string, int>::iterator> ret;
	ret = library.equal_range(temp);
	priority_queue<int, vector<int>, greater<int> > t_q;
	for(multimap<string, int>::iterator it=ret.first; it != ret.second; it++){
		t_q.push(it->second);
	}
	cout<<str<<endl;
	if(t_q.empty()) cout<<"Not Found"<<endl;
	while(!t_q.empty()){
		printf("%.7d\n", t_q.top());
		t_q.pop();
	}
	return;
}

void byyear(string str){
	stringstream geek(str.substr(3, str.size()-3));
	int temp = 0;
	geek >> temp;
	priority_queue<int, vector<int>, greater<int> > t_q = year[temp - 1000];
	cout<<str<<endl;
	if(t_q.empty()) cout<<"Not Found"<<endl;
	while(!t_q.empty()){
		printf("%.7d\n", t_q.top());
		t_q.pop();
	}
	return;
}

int main(){
	int n, m;
	scanf("%d", &n);
	inputData(n);
	scanf("%d", &m);
	getchar();
	string temp;
	while(m--){
		getline(cin, temp);
		int num = temp[0] - '0';
		switch(num){
			case 1:bystring(temp, title);break;
			case 2:bystring(temp, author);break;
			case 3:bystring(temp, keyword);break;
			case 4:bystring(temp, publisher);break;
			default:byyear(temp);break;
		}
	}
	return 0;
}