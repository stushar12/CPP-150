#include <bits/stdc++.h>
using namespace std;
#define N 100200

vector<int> gr[N];

// Function to add edge
void Add_edge(int x, int y)
{
	gr[x].push_back(y);
	// gr[y].push_back(x);
}
void indegree(int n)
{	
	int ind[n];
	for(int i=0;i<n;i++)
	{
		ind[i]=0;
	}
	//indegree calculation
	for(int i=0;i<n;i++)
	{	
		for(auto y: gr[i])
		{
			ind[y]++;
		}
	}

	//bfs

	queue<int> q;

for(int i=0;i<n;i++)
{
	if(ind[i]==0)
	{
		q.push(i);
	}
}

while(!q.empty())
{
	int z=q.front();

	cout<<z<<" ";
	q.pop();

	for(auto t: gr[z])
	{
		ind[t]--;
		if(ind[t]==0)
		q.push(t);
	}
}

}


// Driver code
int main()
{
	// Number of vertices
	int n = 6;

	// Add edges
	Add_edge(0, 2);
	Add_edge(1, 2);
	Add_edge(1, 4);
	Add_edge(2, 5);
	Add_edge(2, 3);
	Add_edge(3, 5);
	Add_edge(4, 5);

	 
	 indegree(n);

	return 0;
}
