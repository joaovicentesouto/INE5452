#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <cmath>
#include <limits.h> 
#include <vector>
#include <queue>

using namespace std;

static int cities;
static int pos[10001];
static int adj[10001][10001]; 

bool isCyclicConntected(int s, vector<bool>& visited) 
{ 
    // Set parent vertex for every vertex as -1. 
    vector<int> parent(cities+1, -1); 
  
    // Create a queue for BFS 
    queue<int> q; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    q.push(s); 
  
    while (!q.empty())
    {
        int u = q.front(); 
        q.pop(); 
  
        for (int i = 0; i < pos[u]; i++)
        { 
        	int v = adj[u][i];
        	
            if (!visited[v]) { 
                visited[v] = true; 
                q.push(v); 
                parent[v] = u; 
            } 
            else if (parent[u] != v) 
                return true; 
        } 
    } 
    return false; 
} 
  
bool isCyclicDisconntected() 
{ 
    // Mark all the vertices as not visited 
    vector<bool> visited(cities+1, false); 
  
    for (int i = 1; i < cities+1; i++) 
        if (!visited[i] && isCyclicConntected(i, visited)) 
            return true; 
    return false; 
}

int main()
{
	int ways;
	int u, v;

	while (cin >> cities >> ways)
	{
		bool multiple_ways = false;

		for (int i = 1; i < cities+1; i++)
			pos[i] = 0;

		for (int i = 0; i < ways; ++i)
		{
			cin >> u >> v;
			adj[u][pos[u]++]= v; 
		    adj[v][pos[v]++]= u; 
		}

		if (multiple_ways)
			cout << "Inseguro" << endl;
		else
		{
			if (isCyclicDisconntected())
				cout << "Inseguro" << endl;
			else
				cout << "Seguro" << endl;
		}
	}

	return 0;
}