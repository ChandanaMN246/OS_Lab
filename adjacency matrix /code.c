//Implement a data structure to represent an adjacency matrix (e.g. 2d array). Take graph adjacency matrix as input with number of nodes and edges. 
#include <stdio.h>
int N, M;

void createAdjMatrix(int Adj[][N + 1],int arr[][2])
{
	for (int i = 0; i < N + 1; i++) 
	{
		for (int j = 0; j < N + 1; j++) 
		{
			Adj[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++) 
	{
		int x = arr[i][0];
		int y = arr[i][1];

		Adj[x][y] = 1;
		Adj[y][x] = 1;
	}
}

void printAdjMatrix(int Adj[][N + 1])
{

	for (int i = 1; i < N + 1; i++) 
	{
		for (int j = 1; j < N + 1; j++) 
		{
			printf("%d ", Adj[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	N = 4;
	int arr[][2]= {{1,2},{1,3},{1,4},{2,1},{2,3},{3,1},{3,2},{4,1}};
	M = sizeof(arr) / sizeof(arr[0]);
	int Adj[N + 1][N + 1];
	createAdjMatrix(Adj, arr);
	printAdjMatrix(Adj);

	return 0;
}
