#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class DSU {
private:
	vi p, rank, set_size;
	int num_sets;
public:
	DSU(int N) {
		set_size.assign(N, 1);
		num_sets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int find_set(int i) {
		return (p[i] == i) ? i : (p[i] = find_set(p[i]));
	}
	bool is_same_set(int i, int j) {
		return find_set(i) == find_set(j);
	}
	void union_set(int i, int j) {
		if (!is_same_set(i, j)) {
			num_sets--;
			int x = find_set(i), y = find_set(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				set_size[x] += set_size[y];
			} else {
				p[x] = y;
				set_size[y] += set_size[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
	int num_disjoint_sets() {
		return num_sets;
	}
	int size_of_set(int i) {
		return set_size[find_set(i)];
	}
};

int main() {
	printf("Assume that there are 5 disjoint sets initially\n");
	DSU ds(5); // create 5 disjoint sets
	printf("%d\n", ds.num_disjoint_sets()); // 5
	ds.union_set(0, 1);
	printf("%d\n", ds.num_disjoint_sets()); // 4
	ds.union_set(2, 3);
	printf("%d\n", ds.num_disjoint_sets()); // 3
	ds.union_set(4, 3);
	printf("%d\n", ds.num_disjoint_sets()); // 2
	printf("is_same_set(0, 3) = %d\n", ds.is_same_set(0, 3)); // will return 0 (false)
	printf("is_same_set(4, 3) = %d\n", ds.is_same_set(4, 3)); // will return 1 (true)
	for (int i = 0; i < 5; i++) // find_set will return 1 for {0, 1} and 3 for {2, 3, 4}
		printf("find_set(%d) = %d, size_of_set(%d) = %d\n", i, ds.find_set(i), i,
				ds.size_of_set(i));
	ds.union_set(0, 3);
	printf("%d\n", ds.num_disjoint_sets()); // 1
	for (int i = 0; i < 5; i++) // find_set will return 3 for {0, 1, 2, 3, 4}
		printf("find_set(%d) = %d, size_of_set(%d) = %d\n", i, ds.find_set(i), i,
				ds.size_of_set(i));
	return 0;
}