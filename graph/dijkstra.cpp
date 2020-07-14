#include <iostream>
#include <queue>
#include <vector>

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int start) {
	auto comp = [](pair<int, int> a, pair<int, int> b) {return a.first > b.first; };
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> store(comp);
	int len = graph.size();
	vector<int> parent(len, 0), dist(len, INT_MAX);
	dist[start] = 0;
	store.push({ 0,start });
	vector<bool> visited(len, false);
	visited[start] = true;
	while (!store.empty()) {
		pair<int, int> cur = store.top();
		store.pop();
		visited[cur.second] = true;
		for (auto w : graph[cur.second]) {
			if (visited[w.second]) continue;
			if (w.first + cur.first < dist[w.second]) {
				parent[w.second] = cur.second;
				dist[w.second] = w.first + cur.first;
				store.push({ dist[w.second],w.second });
			}
		}
	}
	return dist;
}

void run_dijkstra() {
	vector<vector<int>> g = { {0,1,5},{ 0,2,1 },{ 1,2,2 },{ 1,3,1 },{ 2,3,4 },{ 3,4,3 },{ 2,4,8 },{ 3,5,6 } };
	vector<vector<pair<int, int>>> graph(6,vector<pair<int,int>>());
	for (int i = 0; i < g.size(); i++) {
		vector<int> edge = g[i];
		graph[edge[0]].push_back({edge[2],edge[1]});
		graph[edge[1]].push_back({ edge[2],edge[0] });
	}	
	vector<int> ans = dijkstra(graph, 0);
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
}

void main()
{
	run_dijkstra();
	system("pause");
}
