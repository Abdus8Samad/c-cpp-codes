/* ---------- BFS & DFS ---------- */
// 6 6 0 1 0 2 1 3 2 3 3 5 2 4
// 8 8 0 1 0 2 1 3 2 3 4 5 4 6 6 7 5 7
#include <bits/stdc++.h>

using namespace std;

void printDFS(int** edges, int n, int st, bool* visited) {
	cout << st << " ";
	visited[st] = true;
	for (int i = 0; i < n; i++) {
		if (st == i) continue;
		if (edges[st][i] == 1) {
			if (visited[i]) continue;
			printDFS(edges, n, i, visited);
		}
	}
}

void DFS(int** edges, int n) {
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) printDFS(edges, n, i, visited);
	}
	delete[] visited;
}

void printBFS(int** edges, int n, int st, bool* visited) {
	queue<int> q;
	q.push(st);
	visited[st] = true;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		cout << t << " ";
		for (int i = 0; i < n; i++) {
			if (t == i) continue;
			if (edges[t][i] == 1) {
				if (visited[i]) continue;
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

void BFS(int** edges, int n) {
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) printBFS(edges, n, i, visited);
	}
	delete[] visited;
}

bool hasPathDFS(int** edges, int n, int s, int e, int* visited) {
	visited[s] = true;
	if (edges[s][e]) return true;
	for (int i = 0; i < n; i++) {
		if (s == i) continue;
		if (edges[s][i] == 1) {
			if (visited[i]) continue;
			return hasPathDFS(edges, n, i, e, visited);
		}
	}
	return false;
}

bool hasPath(int** edges, int n, int s, int e) {
	int* visited = new int[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			bool ret = hasPathDFS(edges, n, s, e, visited);
			if (ret) return ret;
		}
	}
	delete[] visited;
	return false;
}

vector<int>* getPathDFS(int** edges, int n, int s, int e, int* visited) {
	visited[s] = true;
	if (s == e) {

		vector<int>* ret = new vector<int>(0);
		ret->push_back(e);
		return ret;
	}
	for (int i = 0; i < n; i++) {
		if (s == i) continue;
		if (edges[s][i] == 1) {
			if (visited[i]) continue;
			vector<int>* ret = getPathDFS(edges, n, i, e, visited);
			if (ret) {
				ret->push_back(s);
				return ret;
			}
		}
	}
	return NULL;
}

vector<int>* getPathBFS(int** edges, int n, int s, int e, int* visited) {
	queue<int> q;
	map<int, int> m;
	q.push(s);
	visited[s] = true;
	while (!q.empty() && q.front() != e) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (t == i) continue;
			if (edges[t][i] == 1) {
				if (visited[i]) continue;
				visited[i] = true;
				m.insert(pair<int, int>(i, t));
				q.push(i);
			}
		}
	}
	if (q.empty()) return NULL;
	vector<int>* ret = new vector<int>(0);
	int t = e;
	while (t != s) {
		ret->push_back(t);
		t = m[t];
	}
	ret->push_back(s);
	return ret;
}

vector<int>* getDPath(int** edges, int n, int s, int e) {
	int* visited = new int[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			vector<int>* ret = getPathDFS(edges, n, s, e, visited);
			if (ret) return ret;
		}
	}
	return NULL;
}

vector<int>* getBPath(int** edges, int n, int s, int e) {
	int* visited = new int[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			vector<int>* ret = getPathBFS(edges, n, s, e, visited);
			if (ret) return ret;
		}
	}
	return NULL;
}

void isConnectedDFS(int** edges, int n, int st, int* visited) {
	visited[st] = true;
	for (int i = 0; i < n; i++) {
		if (st == i) continue;
		if (edges[st][i] == 1) {
			if (visited[i]) continue;
			isConnectedDFS(edges, n, i, visited);
		}
	}
}

bool isConnected(int** edges, int n) {
	int* visited = new int[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	isConnectedDFS(edges, n, 0, visited);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) return false;
	}
	return true;
}

void connectedCompDFS(int** edges, int st, int n, int* visited, vector<int>* arr) {
	visited[st] = true;
	arr->push_back(st);
	for (int i = 0; i < n; i++) {
		if (st == i) continue;
		if (edges[st][i] == 1) {
			if (visited[i]) continue;
			connectedCompDFS(edges, i, n, visited, arr);
		}
	}
}

vector<vector<int>*> connectedComp(int** edges, int n) {
	int* visited = new int[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	vector<vector<int>*> ret;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			vector<int>* temp = new vector<int>(0);
			connectedCompDFS(edges, i, n, visited, temp);
			ret.push_back(temp);
		}
	}
	delete[] visited;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int v, e;
	cin >> v >> e;
	int** edges = new int* [v];
	for (int i = 0; i < v; i++) {
		edges[i] = new int[v];
		for (int j = 0; j < v; j++) {
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++) {
		int l, r;
		cin >> l >> r;
		edges[l][r] = 1;
		edges[r][l] = 1;
	}
	DFS(edges, v);
	cout << "\n";
	BFS(edges, v);
	cout << "\n";
	vector<int>* getpDFS = getDPath(edges, v, 7, 4);
	vector<int>* getpBFS = getBPath(edges, v, 7, 4);
	cout << "DFS PATH:";
	if (getpDFS) for (int i = getpDFS->size() - 1; i >= 0; i--) cout << getpDFS->at(i) << ", ";
	cout << "\n";
	cout << "BFS PATH:";
	if (getpBFS) for (int i = getpBFS->size() - 1; i >= 0; i--) cout << getpBFS->at(i) << ", ";
	cout << "\n";
	cout << isConnected(edges, v) << "\n";
	vector<vector<int>*> connComp = connectedComp(edges, v);
	for (int i = 0; i < connComp.size(); i++) {
		vector<int>* temp = connComp[i];
		for (int j = 0; j < temp->size(); j++) cout << temp->at(j) << ", ";
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < v; i++) delete[] edges[i];
	delete[] edges;
	return 0;
}