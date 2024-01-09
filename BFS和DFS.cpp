typedef struct{
	Vertex *vertices[MAX_SIZE];
	int front,rear,size;
}Queue;
Queue *newQueue(){
	Queue *q=(Queue*)malloc(sizeof(Queue));
	q->front=q->rear=q->size=0;
	return q;
}
int isEmpty(Queue *q){
	return q->size==0;
}
void enqueue(Queue *q,Vertex *vet){
	q->vertices[q->rear]=vet;
	q-rear=(q->rear+1)%MAX_SIZE
	q->size++;
}
Vertex *dequeue(Queue *q){
	Vertex *vet=q->vertices[q->front];
	q->front=(q->front+1)%MAX_SIZE
	q->size--;
	return vet;
}
int isVisited(Vertex **visited,int size,Vertex *vet){
	for(int i=0;i<size;i++){
		if(visited[i]==vet){
			return 1;
		}
	}
	return 0;
}
void graphBFS(GraphAdjList *graph,Vertex*startVet,Vertex **res,int *resSize,Vertex**visited,int *visitedSize){
	Queue *queue=newQueue();
	enqueue(queue,startVet);
	visited[(*visitedSize)++]=startVet;
	while(!isEmpty(queue)){
		Vertex *vet=dequeue(queue);
		res[(*resSize)++]=vet;
		AdjListNode *node=findNode(graph,vet);
		while(node!=NULL){
			if(!isVisited(visited,*visitedSize,node->vertex)){
				enqueue(queue,node->vertex);
				visited[(*visitedSize)++]=node->vertex;
			}
			node=node->next;
		}
	}
	free(queue);
}
int isVisited(Vertex **res,int size,Vertex *vet){
	for(int i=0; i<size; i++){
		if(res[i]==vet){
			return 1;
		}
	}
	return 0;	
}
void dfs(GraphAdjList *graph,Vertex **res,int *resSize,Vertex *vet){
	res[(*resSize)++]=vet;
	AdjListNode *node=findNode(graph,vet);
	while(node!=NULL){
		if(!isVisited(res,*resSize,node->vertex)){
			dfs(graph,res,resSize,node->vertex);
		}
		node=node->next;
	}
}
void graphDFS(GraphAdjList *graph,Vertex *startVet,Vertex **res,int *resSize){
	dfs(graph,res,resSize,startVet);
}
