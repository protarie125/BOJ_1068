#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

using vi = vector<int>;
using Adj = map<int, vi>;
using si = stack<int>;

Adj adj;

int solve(int root, int del) {
	auto ans = int{ 0 };

	auto st = si{};
	st.push(root);

	while (!st.empty()) {
		auto t = st.top();
		st.pop();

		auto added = int{ 0 };
		for (const auto& a : adj[t]) {
			if (a != del) {
				st.push(a);
				added += 1;
			}
		}

		if (0 == added) {
			ans += 1;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		adj.insert({ i, vi{} });
	}

	auto root = int{ 0 };
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		if (-1 < x) {
			adj[x].push_back(i);
		}
		else {
			root = i;
		}
	}

	int del;
	cin >> del;

	if (root == del) {
		cout << 0;
	}
	else {
		cout << solve(root, del);
	}

	return 0;
}