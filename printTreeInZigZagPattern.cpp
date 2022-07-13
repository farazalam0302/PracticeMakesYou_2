/*
 *           4
 *      3         9
 *   1    6     8     7
 *  0 2, 5 10,11 12,13 14
 */

/*
 * 4 3 9 6 1
 *
 */

//queue
//3, 9, null
#include "Tree/BinaryTree.h"

void recursiveUtilityZigzagTraversal(Node *R, int level, bool direction) {
	if (R == NULL || level <= 0)
		return;
	if (level == 1)
		cout << R->data << " ";
	if (direction) {
		recursiveUtilityZigzagTraversal(R->left, level - 1, direction);
		recursiveUtilityZigzagTraversal(R->right, level - 1, direction);
	} else {
		recursiveUtilityZigzagTraversal(R->right, level - 1, direction);
		recursiveUtilityZigzagTraversal(R->left, level - 1, direction);
	}
}

void printZigZagTree(Node *R) {
	if (R == NULL)
		return;
	int depth = height_depth(R);
	bool direction;
	for (int level = 1; level <= depth; ++level) {
		recursiveUtilityZigzagTraversal(R, level, direction);
		direction = !direction;

	}

}

void printZigZagTree_Iterative(Node *R) {
	if (!R)
		return;
	stack<Node*> LeftToRight;
	stack<Node*> RightToLeft;
	LeftToRight.push(R);
	Node *tmp;
	while (LeftToRight.empty() == false || RightToLeft.empty() == false) {
		while (!LeftToRight.empty()) {
			tmp = LeftToRight.top();
			LeftToRight.pop();
			cout << tmp->data << " ";
			if (tmp->right)
				RightToLeft.push(tmp->right);
			if (tmp->left)
				RightToLeft.push(tmp->left);

		}

		while (!RightToLeft.empty()) {
			tmp = RightToLeft.top();
			RightToLeft.pop();
			cout << tmp->data << " ";
			if (tmp->left)
				LeftToRight.push(tmp->left);
			if (tmp->right)
				LeftToRight.push(tmp->right);

		}

	}

}

int main(int argc, char **argv) {
	Node *root;
	makeR6(&root);
	postorder(root);
	cout << "\n";

	printZigZagTree_Iterative(root);
	cout << "\n";

	return 0;
}

