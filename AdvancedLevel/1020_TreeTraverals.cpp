/* 1020 Tree Traversals
 * By Milkyway, Sep 01, 2019
 */
 
#include<cstdio>

int postorder[35];
int inorder[35];
int bi_tree[10000]; // data is weak, easily pass

void build_bi_tree(int p_left, int p_right, int i_left, int i_right, int count){
	if(p_left > p_right) {return;}
	int head = postorder[p_right];
	bi_tree[count] = head;
	int index = 0;
	for(int i=i_left; i<=i_right; i++){
		if(inorder[i] == head){
			index = i;
			break;
		}
	}
	build_bi_tree(p_left, p_left + index - i_left - 1, i_left, index-1, count*2);
	build_bi_tree(p_left + index - i_left, p_right - 1, index+1, i_right, count*2 + 1);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &postorder[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%d", &inorder[i]);
	}
	build_bi_tree(1, n, 1, n, 1);
	printf("%d", bi_tree[1]);
	int k = 2, i=1;
	while(k <= n){
		if(bi_tree[++i] == 0) continue;
		printf(" %d", bi_tree[i]);
		k++;
	}
	return 0;
}