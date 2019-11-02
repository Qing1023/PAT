/* @problem 1021-Deepest-Root
 * @author milkyway
 * @date Sep 07, 2019
 * @algorithm union-find set and dfs
 */
#include<cstdio>
#include<vector>
using namespace std;

int parent[10004];
vector<vector<int> > list(10004);
int maxDeep[10004];

void init(int n){
	for(int i=1; i<=n; i++){
		parent[i]=i;
	}
	return;
}

int findParent(int node){
	int temp = node;
	while(temp != parent[temp]){
		temp = parent[temp];
	}
	int root = temp;
	temp = node;
	while(temp != root){
		temp = parent[temp];
		parent[node] = root;
		node = temp;
	}
	return root;
}

void unionNodes(int node1, int node2){
	parent[node2] = findParent(node1);
	return;
}

bool visted[10004];
int maxLevel = 1;
void dfs(int par, int level){
	visted[par] = true;
	maxLevel = max(maxLevel, level);
	maxDeep[par] = max(maxDeep[par], level);
	for(int i=0; i<list[par].size(); i++){
		if(!visted[list[par][i]]){
			dfs(list[par][i], level+1);
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int numofcom = 1;
	init(n);
	for(int i=1; i<n; i++){
		int start, end;
		scanf("%d %d", &start, &end);
		list[start].push_back(end);
		list[end].push_back(start);
		if(findParent(start) != findParent(end)){
			unionNodes(start, end);
		}else{
			numofcom++;
		}
	}
	if(numofcom != 1){
		printf("Error: %d components\n", numofcom);
	}else{
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				visted[j] = false;
			}
			dfs(i, 1);
		}
		for(int i=1; i<=n; i++){
			if(maxDeep[i] == maxLevel){
				printf("%d\n", i);
			}
		}
	}
	return 0;
}