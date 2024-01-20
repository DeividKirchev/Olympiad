#include <iostream>
#include <limits.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define s second
#define f first
int minDistance(int dist[], bool visited[], const int& n)
{
    int mini = INT_MAX, min_index = -1;

    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] <= mini)
        {
            mini = dist[i];
            min_index = i;
        }
    return min_index;
}
int dijkstra(vector<pair<int, int>> cost[10000], vector<pair<int, int>> time[10000], const int& maxCost, const int& n)
{
    int dist[10000];

    bool visited[10000];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[0] = 0;

    for (int count = 0; count < n; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < cost[u].size(); v++) {
            auto to = cost[u][v].f;
            if (!visited[to]
                && dist[u] != INT_MAX
                && dist[u] + time[u][v].s < dist[to]
                && cost[u][v].s <= maxCost)
                dist[to] = dist[u] + time[u][v].s;
        }
    }
    return dist[n - 1];
}
int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> cost[10000];
    vector<pair<int, int>> time[10000];
    set<int> uniqueCosts;
    for (int i = 0;i < m;i++)
    {
        int from, to, cost1, time1;
        cin >> from >> to >> cost1 >> time1;
        from--;
        to--;
        cost[from].push_back(make_pair(to, cost1));
        uniqueCosts.insert(cost1);
        time[from].push_back(make_pair(to, time1));
    }
    vector<int> vc(uniqueCosts.begin(), uniqueCosts.end());
    sort(vc.begin(), vc.end());
    int left = 0, right = vc.size() - 1;
    int ans = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int maxCost = vc[mid];
        int minTime = dijkstra(cost, time, maxCost, n);
        if (minTime > k)
            left = mid + 1;
        else {
            right = mid - 1;
            ans = maxCost;
        }
        //cout << "Cost: " << maxCost << endl;
        //cout << "Time: " << minTime << endl;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0;i < t;i++)
        cout << solve() << endl;
    return 0;
}