// 내가 생각한 방식; 마지막에 check 

#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <limits.h>

#define MAX 100


int Queue[MAX];
//wp is the write pointer rp is the read pointer
int Wp=0;
int Rp=0;


int enqueue(int d){
	if (Wp==MAX){return 0;}
	Queue[Wp++]=d;
	return 1;
}

//return sp if stack empty return  -1 
int dequeue(int *p){
	if (Rp==Wp){return 0;}
	*p=Queue[Rp++];
	return 1;
}

struct Graph{
	int* s;
	int* e;
};

int check_sum(int * check, int node_num){
	int sum=0;
	for (int i=1;i<=node_num;i++){
		sum+=check[i];
	}
	if (sum==node_num){return 1;}
	else{return 0;}
}

int main(void){
	int result;
	int data;
	int nghbr;
	//graph정의
	struct Graph g;

	//for first input 
	int node_edge[2];

	//input node and edge number 
	for(int i=0;i<2;i++){
		scanf("%d",&node_edge[i]);
	}

	//allocate g.s g.e
	g.s= malloc(node_edge[1]*sizeof(int));
	g.e= malloc(node_edge[1]*sizeof(int));

	//input edge path
	for(int i=0;i<node_edge[1];i++){
		scanf("%d",&(g.s[i]));
		getchar();
		scanf("%d",&(g.e[i]));
		getchar();
	}

	// set check it starts from index 1
	int* check=malloc((node_edge[0]+1)*sizeof(int));


	

	result=enqueue(1);
	while(!check_sum(check,node_edge[0])){
		result=dequeue(&data);
		if(check[data]==0){
			//check the dequeue data
			check[data]=1;
			//print 
			printf("%d\n",data);
		}


		//get neigbor and enqueue it 
		for(int i=0;i<node_edge[1];i++){
			if(g.s[i] == data){
				nghbr=g.e[i]; //neighbor node
				
				if(check[nghbr]==0){ 
					enqueue(nghbr);
					printf("nghbr %d\n",nghbr);
					continue;
				}
				
			}
			if(g.e[i] == data){
				nghbr=g.s[i]; //negibor node
				
				if(check[nghbr]==0){ 
					enqueue(nghbr);
					printf("nghbr %d\n",nghbr);
					continue;
				}
				
			}
		}
	
	}
	
	free(g.s);
	free(g.e);
	free(check);


	return 0;
}