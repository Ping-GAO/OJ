/*
 * main.c
 *
 *  Created on: Dec 6, 2017
 *      Author: gary9
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printf_graph(int **,int i);
void DFS(int **matrix,int *connect,char *sourse,int index,char **array);
int main(){
	int cnt;
	while(~scanf("%d",&cnt)&&cnt){
		// printf("%d\n",cnt);
		int i;
		char ** array;
		char ** array_original;
		array = (char **)malloc(sizeof(char *)*2*cnt);
		for(i=0;i<2*cnt;i++){
			array[i] = (char *)malloc(sizeof(char)*10);
		}
		array_original = (char **)malloc(sizeof(char *)*2*cnt);
		for(i=0;i<2*cnt;i++){
			array_original[i] = (char *)malloc(sizeof(char)*10);
		}

		int j=0;
		char s1[10];
		char s2[10];
		for(i=0;i<cnt;i++){
			scanf("%s%s",s1,s2);
			//printf("%s%s\n",s1,s2);
			strcpy(array[j],s1);
			strcpy(array_original[j],s1);
			j++;
			strcpy(array[j],s2);
			strcpy(array_original[j],s2);
			j++;
		}
		// 读取完成
		// 去掉数组重复项
		// doggy bubble sort
		char temp[20];
		for(i=0; i<2*cnt; i++ ){
			for(j=0; j<2*cnt-1; j++){
				if(strcmp(array[j],array[j+1])>0){
					strcpy(temp, array[j]);
					strcpy(array[j],array[j+1]);
					strcpy(array[j+1],temp);
				}
			}
		}
		/*
		for(i=0;i<6;i++){
			printf("%s--",array[i]);
		}
		printf("\n");
		*/

		// sort in order
		// compare earlier term to get rid of duplicate
		//for(i=0;i<){

		//}
		int index = 1;
		for(i=0;i<2*cnt;i++){
			if(strcmp(array[i], array[index-1]) != 0){
				strcpy(array[index++],array[i]);
			}
		}
		/*
		for(i=0;i<index;i++){
			printf("%s--",array[i]);
		}
		printf("\n");

		for(i=0;i<6;i++){
			printf("%s--",array_original[i]);
		}
		printf("\n");
		 */
		// i don't why it work, but the length of the array become index
		int **matrix;
		matrix = (int **)malloc(sizeof(int *)*index);
		for(i=0;i<index;i++){
			matrix[i] = (int *)malloc(sizeof(int)*index);
		}
		// initialise 2d array
		for(i=0;i<index;i++){
			for(j=0;j<index;j++){
				matrix[i][j]=0;
			}
		}
		// i need the original array to make the adjecney matrix need to make a copy
		// start to make the matrix
		for(i=0; i<cnt;i++){
			// connect array_original[2*i] to array_original[2*i+1]
			// search string in processed array
			int row,column;
			for(j=0; j<index; j++){
				if(strcmp(array[j],array_original[2*i])==0){
					row = j;
					break;
				}
			}
			// printf("row is %d\n",row);
			for(j=0; j<index; j++){
				if(strcmp(array[j],array_original[2*i+1])==0){
					column = j;
					break;
				}
			}
			// printf("column is %d\n",column);
			matrix[row][column] = 1;
		}
		// print graph
		/*
		for(i=0;i<index;i++){
			for(j=0;j<index;j++){
				printf("%d",matrix[i][j]);
			}
			printf("\n");
		}
		*/
		// test is correct
		// it is time to do a dfs in my adjancy matrix
		int sum2;
		int flag = 0;
		int *connect = (int *)malloc(sizeof(int)*index);
		for(i=0; i<index; i++){
			// 对每一个点都进行bfs搜索
			sum2=0;
			memset(connect,0,sizeof(int)*index);
			DFS(matrix,connect,array[i],index,array);
			// matrix |index array| start point|array length|array
			/*
			for(j=0;j<index;j++){
				printf("%d->",connect[j]);
			}
			printf("\n\n");
			*/
			for(j=0;j<index;j++){
				if(connect[j]==1){
					sum2++;
				}
			}
			if(sum2==index-1){
				flag=1;
				break;
			}
		}
		//

		//printf_graph(matrix,index);



		if(flag==1){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}



void DFS(int **matrix,int *connect,char *sourse,int index,char **array){
	//printf("%s + \n",sourse);
	int i,j;
	for(i=0;i<index;i++){
		if(strcmp(sourse,array[i])==0){
			//printf("i is %d\n",i);
			for(j=0;j<index;j++){
				if(matrix[i][j]==0){
					continue;
				}
				connect[j]=1;
				DFS(matrix,connect,array[j],index,array);
			}
		}
	}


}
void printf_graph(int **array,int index){
	int i,j;
	for(i=0;i<index;i++){
		for(j=0;j<index;j++){
			printf("%d",array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
