#include <cstdio>
#include <algorithm>

#define MAX_MONEY 100001
#define MAX_VAL 101
using namespace std;
int val_count, total_money;
int val[MAX_VAL], dp[MAX_MONEY][MAX_VAL];

int coin(int money,int v_idx){
	if(v_idx==0){
		if(money%val[v_idx]==0){return 1;}
		else return 0;
	}	

	
	if(dp[money][v_idx]!=-1){return dp[money][v_idx];}


	int count=0;
	int t= money/val[v_idx];

	for(int i=0; i<=t; i++){
		count+=coin(money-i*val[v_idx],v_idx-1);
	}

	dp[money][v_idx]=count;

	return count;
}

int main(){
	scanf("%d %d",&val_count, &total_money);

	for(int i=0; i<val_count; i++){
		scanf("%d",&val[i]);
	}

	for(int i=0 ; i<= total_money; i++){
		for(int j=0; j<val_count;j++) dp[i][j]=-1;
	}
	
	printf("%d",coin(total_money,val_count-1));
}