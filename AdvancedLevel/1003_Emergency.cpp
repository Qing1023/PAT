// 1003 Emergency, PAT
// By Milkyway, 2019/5/21.
#include<iostream>
#include<string>
#include<vector>
#define INF 0xfffffff
using namespace std;

const int N = 500+3;
int Map[N][N]; // adjMatrix
bool visted[N]; // The city that have visted
int teamNum[N];
int dsp=0, maxT=0;

int dijkstra(int num, int src, int tar){
    int len[N];
    // initiation
    for(int i=0; i<num; i++){
        len[i]=Map[src][i];
    }
    visted[src]=true;
    len[src]=0;
    int next;
    for(int i=1; i<num; i++){
        int minL=INF;
        for(int j=0; j<num; j++){
            if(visted[j]) continue;
            if(minL > len[j]){
                minL=len[j];
                next=j;
            }
        }
        visted[next]=true;
        for(int j=0; j<num; j++){
            if(len[j] > Map[j][next] + len[next]){
                len[j] = Map[j][next] + len[next];
            }
        }
    }
    return len[tar];
}

void dfs(int n, int len, int src, int tar, int numTeam){
    if(len==0 && src==tar){
        dsp++;
        maxT=max(numTeam, maxT);
        return;
    }
    if(len==0) return;
    if(src==tar) return;
    for(int i=0; i<n; i++){
        if(src != i && !visted[i] &&Map[src][i] != INF){
            visted[i]=true;
            len -= Map[src][i];
            numTeam += teamNum[i];
            dfs(n, len, i, tar, numTeam);
            len += Map[src][i];
            numTeam -= teamNum[i];
            visted[i]=false;
        }
    }
}

int main(){
    int n, m, src, tar;
    cin>>n>>m>>src>>tar;
    for(int i = 0; i < n; i++){
        cin>>teamNum[i];
        visted[i]=false;
    }
    fill(Map[0], Map[0] + N*N, INF);
    for(int i = 0; i < m; i++){
        int c1, c2, len;
        scanf("%d %d %d", &c1, &c2, &len); // if this, no TLE
        //cin>>c1>>c2>>len;
        Map[c1][c2]=len;
        Map[c2][c1]=len;
    }
    int lsp=dijkstra(n, src, tar);
    fill(visted, visted + N, false);
    dfs(n, lsp, src, tar, teamNum[src]);
    cout<<dsp<<" "<<maxT<<endl;
    return 0;
}
