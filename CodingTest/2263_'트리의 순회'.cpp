#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int N;
deque<int> inorder;
deque<int> postorder;
deque<int> tree[100001];

int DFS(int start, int end);
void preorder(int root);

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		inorder.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		postorder.push_back(input);
	}

	int root = DFS(0, inorder.size() - 1);

	preorder(root);
	cout << endl;

	return 0;
}

int DFS(int start, int end) {
	int root = postorder.back();
	postorder.pop_back();

	if (inorder.size() == 1)
		return root;

	int left_sub_start = start;
	int left_sub_end;
	int right_sub_start;
	int right_sub_end = end;

	for (int i = start; i <= end; i++) {
		if (inorder[i] == root) {
			left_sub_end = i - 1;
			right_sub_start = i + 1;
			break;
		}
	}

	if(right_sub_start <= right_sub_end) tree[root].push_front(DFS(right_sub_start, right_sub_end));
	if(left_sub_start <= left_sub_end) tree[root].push_front(DFS(left_sub_start, left_sub_end));

	return root;
}

void preorder(int root) {
	cout << root << " ";

	for (unsigned int i = 0; i < tree[root].size(); i++)
		preorder(tree[root][i]);
}