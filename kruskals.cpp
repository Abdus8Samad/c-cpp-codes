/* KRUSKEL'S ALGORITHM */
// 11 6
// 0 1 1
// 0 2 5
// 2 3 10
// 0 3 4
// 1 3 3
// 1 2 6
// 3 4 7
// 2 4 8
// 4 5 2
// 2 5 9
// 3 5 6

//0, 1, 1
//1, 3, 3
//0, 2, 5
//3, 4, 7
//4, 5, 2

//11 6
//1 3 1
//0 1 2
//0 3 3
//0 2 4
//4 5 5
//2 3 6
//3 5 7
//2 1 8
//2 4 9
//2 5 10
//3 4 11

//1 3 1
//0 1 2
//0 2 4
//4 5 5 
//3 5 7
#include <iostream>
#include <algorithm>

using namespace std;

class edge {
public:
	int s, e, w;
	edge() {
		s = e = w = 0;
	}
	edge(int s, int e, int w) {
		this->s = s;
		this->e = e;
		this->w = w;
	}
	bool operator > (const edge& e1) {
		return w > e1.w;
	}
	bool operator < (const edge& e1) {
		return w < e1.w;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int e, v;
	cin >> e >> v;
	edge* input = new edge[e];
	edge* output = new edge[v-1];
	for (int i = 0; i < e; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		edge temp(s, e, w);
		input[i] = temp;
	}
	sort(input, input + v);
	int cnt = 0, i = 0;
	int* parents = new int[v];
	for (int i = 0; i < v; i++) parents[i] = i;
	while (i < v - 1) {
		edge toInsert = input[cnt];
		int p1 = toInsert.s, p2 = toInsert.e;
		while (p1 != parents[p1]) {
			p1 = parents[p1];
		}
		while (p2 != parents[p2]) {
			p2 = parents[p2];
		}
		if (p1 != p2) {
			output[i] = toInsert;
			parents[p1] = p2;
			i++;
		}
		cnt++;
	}
	for (int j = 0; j < i; j++) {
		cout << output[j].s << ", " << output[j].e << ", " << output[j].w << "\n";
	}
	return 0;
}