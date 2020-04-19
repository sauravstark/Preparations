#include <iostream>
#include <vector>
#include <tuple>
#define pair std::tuple<int, Node*>

struct Node {
	int data;
	Node* lt, * rt;
	Node(int data) {
		this->data = data;
		lt = nullptr;
		rt = nullptr;
	}
};

void func(Node* root, int sum, std::vector<pair> &prev_subs, int total = 0) {
	total += root->data;
	int req = total - sum;

	std::vector<unsigned int> indices;

	for (int i = 0; i < prev_subs.size(); ++i) {
		if (std::get<0>(prev_subs[i]) == req) {
			indices.push_back(i);
		}
	}

	for(int index: indices) {
		for (int i = index; i < prev_subs.size(); ++i) {
			std::cout << std::get<1>(prev_subs[i])->data << " ";
		}
		std::cout << std::endl;
	}

	if (root->lt != nullptr) {
		prev_subs.push_back(std::make_tuple(total, root->lt));
		func(root->lt, sum, prev_subs, total);
		prev_subs.pop_back();
	}
	if (root->rt != nullptr) {
		prev_subs.push_back(std::make_tuple(total, root->rt));
		func(root->rt, sum, prev_subs, total);
		prev_subs.pop_back();
	}
}

int main()
{
	Node* root = new Node(1);
	root->lt = new Node(3);
	root->lt->lt = new Node(2);
	root->lt->rt = new Node(1);
	root->lt->rt->lt = new Node(1);
	root->rt = new Node(-1);
	root->rt->lt = new Node(4);
	root->rt->lt->lt = new Node(1);
	root->rt->lt->rt = new Node(2);
	root->rt->rt = new Node(5);
	root->rt->rt->rt = new Node(6);

	std::vector<pair> prev_subsets;
	prev_subsets.push_back(std::make_tuple(0, root));
	func(root, 5, prev_subsets);

	return 0;
}