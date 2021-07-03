#ifndef Dijkstra_H
#define Dijkstra_H

int minDistance(int dist[], bool sptSet[]) 
{
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < NodeSayisi; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
}

void printSolution(int dist[]) 
{
    printf("Dugum \t\t Kaynaga Uzaklik\n");
    for (int i = 0; i < NodeSayisi; i++)
        printf("%d \t\t %d\n", i, dist[i]);
} 

int* Dijkstra(int graph[NodeSayisi][NodeSayisi], int src,int* gezilenNode) 
{
	for(int i=0;i<NodeSayisi;i++){
		gezilenNode[i]=0;
	}
    int* dist=new int[NodeSayisi];
    bool sptSet[NodeSayisi];
    for (int i = 0; i < NodeSayisi; i++){
    	dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	
    dist[src] = 0;
    
    for (int count = 0; count < NodeSayisi - 1; count++){
    	
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        gezilenNode[count]=u;
        for (int v = 0; v < NodeSayisi; v++){
        	if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
			}
		}
    }
    
    printSolution(dist);
    return dist;
}

#endif
