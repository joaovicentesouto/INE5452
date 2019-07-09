// C++ program for implementation of Ford Fulkerson algorithm 
#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
using namespace std; 
  
// Number of vertices in given graph
#define MIN_SIZE 110
#define V (MIN_SIZE + MIN_SIZE)
#define SRC (0)
#define SINK (V-1)
#define HORSE(x) (MIN_SIZE + x)
#define HORSEMAN(x) (x)

int pos[V];
int adj[V][V];
int cost[V][V];
  a
/* Returns true if there is a path from source 's' to sink 't' in 
  residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V][V], int s, int t, int parent[]) 
{ 
    // Create a visited array and mark all vertices as not visited 
    bool visited[V]; 
    memset(visited, 0, sizeof(visited)); 
  
    // Create a queue, enqueue source vertex and mark source vertex 
    // as visited 
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1;
  
    // Standard BFS Loop 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int i=0; i<pos[u]; i++) 
        { 
        	int v = adj[u][i];

            if (!visited[v] && rGraph[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
  
    // If we reached sink in BFS starting from source, then return 
    // true, else false 
    return (visited[t] == true); 
} 
  
// Returns the maximum flow from s to t in the given graph 
int fordFulkerson(int s, int t) 
{ 
    int u, v; 
  
    // Create a residual graph and fill the residual graph with 
    // given capacities in the original graph as residual capacities 
    // in residual graph 
    int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates  
                     // residual capacity of edge from i to j (if there 
                     // is an edge. If rGraph[i][j] is 0, then there is not)   
    for (u = 0; u < V; u++) 
        for (v = 0; v < V; v++) 
             rGraph[u][v] = cost[u][v]; 
  
    int parent[V];  // This array is filled by BFS and to store path 
  
    int max_flow = 0;  // There is no flow initially 
  
    // Augment the flow while tere is path from source to sink 
    while (bfs(rGraph, s, t, parent)) 
    { 
        // Find minimum residual capacity of the edges along the 
        // path filled by BFS. Or we can say find the maximum flow 
        // through the path found. 
        int path_flow = INT_MAX; 
        for (v=t; v!=s; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
  
        // update residual capacities of the edges and reverse edges 
        // along the path 
        for (v=t; v != s; v=parent[v]) 
        { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
  
        // Add path flow to overall flow 
        max_flow += path_flow; 
    } 
  
    // Return the overall flow 
    return max_flow; 
} 
  
// Driver program to test above functions 
int main() 
{
	int n, m, k, cap, u, v, cases = 1;

    while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{
	    for (int i = 0; i < V; ++i)
	    	pos[i] = 0;

		for (int i = HORSE(1); i < HORSE(1) + n; ++i)
		{
			scanf("%d ", &cap);
			// printf("C: %d = %d\n", i, cap);

			adj[i][pos[i]++] = SINK;
			cost[i][SINK] = cap;
		}

		for (int i = 1; i <= k; ++i)
		{
			scanf("%d %d ", &v, &u);

			adj[HORSEMAN(SRC)][pos[HORSEMAN(SRC)]++] = HORSEMAN(u);
			cost[HORSEMAN(SRC)][HORSEMAN(u)] = 1;

			adj[HORSEMAN(u)][pos[HORSEMAN(u)]++] = HORSE(v);

			cost[HORSEMAN(u)][HORSE(v)] = 1;
		}

	    printf("Instancia %d\n%d\n\n", cases++, fordFulkerson(SRC, SINK));
	}
  
    return 0; 
} 