/* 1013 Battle over cities.
 * By Milkyway, June 12, 2019.
 * It runs in O(max(n,m)) in time and O(n*n) in space, which .
 * Algorithm: Union and Find set.
 */
#include<iostream>

using namespace std;

const int N = 1001;

struct edge{
    int first;
    int second;
}edgeSet[N*N/2];

int n, m, k;
int Pa[N];

void init(){
    for(int i=1; i<N; i++){
        Pa[i] = i;
    }
}

int Parent(int node){
    int temp = node;
    while(temp != Pa[temp]){
        temp = Pa[temp];
    }
    while(node != Pa[node]){
        int t = Pa[node];
        Pa[node] = temp;
        node = t;
    }
    return temp;
}

void unionSet(int node1, int node2){
    Pa[node1] = node2;
}

int numOfRepaired(int lostCity){
    init();
    for(int i=0; i<m; i++){
        if(edgeSet[i].first == lostCity || edgeSet[i].second == lostCity){
            continue;
        }
        int firPa = Parent(edgeSet[i].first);
        int secPa = Parent(edgeSet[i].second);
        if(firPa != secPa){
            unionSet(firPa, secPa);
        }
    }
    int num = 0;
    for(int i=1; i<=n; i++){
        if(Pa[i] == i && i != lostCity){
            num++;
        }
    }
    return num - 1;
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        cin>>edgeSet[i].first>>edgeSet[i].second;
    }
    while(k--){
        int lost;
        cin>>lost;
        cout<<numOfRepaired(lost)<<endl;
    }
    return 0;
}
