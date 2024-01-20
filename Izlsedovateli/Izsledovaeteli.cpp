#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int findMin(const int dist[], const bool visited[], const int& n)
{
	int index = 0, mini = INT_MAX;
	for (int i = 0;i < n;i++)
		if (!visited[i] && mini > dist[i])
		{
			index = i;
			mini = dist[i];
		}
	return index;
}
int dijkstra(const vector<pair<int, int>> graph[100], const int& n)
{
	bool visited[100];
	int dist[100];
	for (int i = 0;i < n;i++)
	{
		dist[i] = INT_MAX;
		visited[i] = false;
	}
	dist[0] = 0;
	for (int i = 0;i < n - 1;i++)
	{
		int u = findMin(dist, visited, n);
		visited[u] = true;
		for (int j = 0;j < graph[u].size();j++)
		{
			if (!visited[graph[u][j].first]
				&& graph[u][j].second + dist[u] < dist[graph[u][j].first])
				dist[graph[u][j].first] = graph[u][j].second + dist[u];
		}
	}
	return dist[n - 1];
}
int solve()
{
	vector<pair<int,int>> graph[100];
	int n, m, x, y, d;
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		cin >> x >> y >> d;
		x--;
		y--;
		graph[x].push_back(make_pair(y, d));
		graph[y].push_back(make_pair(x, d));
	}
	return dijkstra(graph, n);
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0;i < t;i++)
		cout << solve() << endl;
	return 0;
}