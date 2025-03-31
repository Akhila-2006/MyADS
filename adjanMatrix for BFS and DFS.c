#include <stdio.h>
#include <stdlib.h>
#define MAX  20 
int adjMatrix[MAX][MAX];  
int visited[MAX];         
int queue[MAX];           
int front = 0, rear = 0; 
int top=0;
int stack[20],i;
void enqueue(int vertex) {
    if (rear == MAX ) {
        printf("Queue Overflow\n");
    } else {
        if (front == 0) front = 1; 
        rear++;
        queue[rear] = vertex;
    }
}
int dequeue() {
    int vertex;
    if (front == 0 || front > rear) {
        printf("Queue Underflow\n");
        return 0;
    } else {
        vertex = queue[front];
        front++;
        return vertex;
    }
}
void push(int vertex) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = vertex;  
    }
}
int pop() {
    if (top == 0) {
        return 0;
    } else {
        return stack[top--];
    }
}
void bfs(int startVertex, int n) {
    int i;
    enqueue(startVertex);
    visited[startVertex] = 1;
    
    printf("BFS Traversal: ");
    
    while (front <= rear) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
        for (i = 1; i <=n; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;  
            }
        }
    }
    printf("\n");
}
void dfs(int sv, int n) {
    push(sv);
    visited[sv]=1;
    printf("DFS Traversal : ");
    printf("%d ",sv);
    while(top!=0){
    	for(i=1;i<=n;i++){
    		if(adjMatrix[stack[top]][i]==1&&visited[i]==0){
    			push(i);
    			visited[i]=1;
    			printf("%d ",i);
    			break;
			}
			if(i==n)
			pop();
		}
	}
	printf("\n");
}
int main() {
    int n, i, j, sv;
    int ch;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i<=n; i++) {
        for (j = 1; j<=n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    while(1){
    	printf("**Using Adjacency Matrix**\n");
    	printf("1.BFS Traversal \n 2.DFS Traversal \n 3.Exit\n");
    	printf("Enter your choice : ");
    	scanf("%d",&ch);
    	switch(ch){
		case 1:
    printf("Enter the starting vertex for bfs: ");
    scanf("%d", &sv);
    for (i = 1; i <=n; i++) {
        visited[i] = 0;
    }
    bfs(sv,n);
    break;
    case 2:
    	 printf("Enter the starting vertex for dfs: ");
    scanf("%d", &sv);
    for (i = 1; i <=n; i++) {
        visited[i] = 0;
    }
    dfs(sv, n);
    break;
    case 3:
    	exit(0);
    	break;
    	default:
    		printf("Invalid choice\n");
    	}
    }
    		
}

