#if 0
Construct BST from given preorder traversal |
    Set 1 Given preorder traversal of a binary search tree,
    construct the BST.

    For example,
    if the given traversal is{10, 5, 1, 7, 40, 50},
    then the output should be root of following tree.

/* A O(n) program for construction
of BST from preorder traversal */
#include <bits/stdc++.h>
    using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
 public:
  int data;
  node* left;
  node* right;
};

// A utility function to create a node
node* newNode(int data) {
  node* temp = new node();

  temp->data = data;
  temp->left = temp->right = NULL;

  return temp;
}

// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
node* constructTreeUtil(int pre[], int* preIndex, int key, int min, int max,
                        int size) {
  // Base case
  if (*preIndex >= size) return NULL;

  node* root = NULL;

  // If current element of pre[] is in range, then
  // only it is part of current subtree
  if (key > min && key < max) {
    // Allocate memory for root of this
    // subtree and increment *preIndex
    root = newNode(key);
    *preIndex = *preIndex + 1;

    if (*preIndex < size) {
      // Construct the subtree under root
      // All nodes which are in range
      // {min .. key} will go in left
      // subtree, and first such node
      // will be root of left subtree.
      root->left =
          constructTreeUtil(pre, preIndex, pre[*preIndex], min, key, size);

      // All nodes which are in range
      // {key..max} will go in right
      // subtree, and first such node
      // will be root of right subtree.
      root->right =
          constructTreeUtil(pre, preIndex, pre[*preIndex], key, max, size);
    }
  }

  return root;
}

// The main function to construct BST
// from given preorder traversal.
// This function mainly uses constructTreeUtil()
node* constructTree(int pre[], int size) {
  int preIndex = 0;
  return constructTreeUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
}

// A utility function to print inorder
// traversal of a Binary Tree
void printInorder(node* node) {
  if (node == NULL) return;
  printInorder(node->left);
  cout << node->data << " ";
  printInorder(node->right);
}

// Driver code
int main() {
  int pre[] = {10, 5, 1, 7, 40, 50};
  int size = sizeof(pre) / sizeof(pre[0]);

  node* root = constructTree(pre, size);

  cout << "Inorder traversal of the constructed tree: \n";
  printInorder(root);

  return 0;
}

// This is code is contributed by rathbhupendra

#endif

#include <bits/stdc++.h>
using namespace std;
class BSTNode {
 public:
  int data;
  BSTNode* left;
  BSTNode* right;
  BSTNode(int x) {
    data = x;
    left = nullptr;
    right = nullptr;
  }
  BSTNode() {
    data = 0;
    left = nullptr;
    right = nullptr;
  }
};
#if 0
// Push root
push(stack, root);

int i;
Node* temp;

// Iterate through rest of the size-1 items of given preorder array
for (i = 1; i < size; ++i) {
  temp = NULL;

  /* Keep on popping while the next value is greater than
  stack's top value. */
  while (!isEmpty(stack) && pre[i] > peek(stack)->data) temp = pop(stack);

  // Make this greater value as the right child
  // and push it to the stack
  if (temp != NULL) {
    temp->right = newNode(pre[i]);
    push(stack, temp->right);
  }

  // If the next value is less than the stack's top
  // value, make this value as the left child of the
  // stack's top node. Push the new node to stack
  else {
    peek(stack)->left = newNode(pre[i]);
    push(stack, peek(stack)->left);
  }
}

return root;
}
#endif
BSTNode* IterativeCreateBSTfromPreOrder(vector<int>& preorder) {
  int n = preorder.size();
  stack<BSTNode*> myStack;
  BSTNode* root = new BSTNode(preorder[0]);
  myStack.push(root);
  BSTNode* temp = nullptr;
  for (int i = 1; i < n; ++i) {
    temp = nullptr;
    while (!(myStack.empty()) && preorder[i] > myStack.top()->data) {
      temp = myStack.top();
      myStack.pop();
    }
    if (temp != nullptr) {
      temp->right = new BSTNode(preorder[i]);
      myStack.push(temp->right);
    } else {
      myStack.top()->left = new BSTNode(preorder[i]);
      myStack.push(myStack.top()->left);
    }
  }
  return root;
}
BSTNode* RecursiveCreateBSTfromPreOrder(vector<int>& preorder,
                                        int* preorderIndex, int key,
                                        int minimum, int maximum, int size) {
  if (*preorderIndex >= size) return NULL;
  BSTNode* root = nullptr;
  if (key < maximum && key > minimum) {
    root = new BSTNode(key);
    *preorderIndex = *preorderIndex + 1;

    if (*preorderIndex < size) {
      root->left = RecursiveCreateBSTfromPreOrder(preorder, preorderIndex,
                                                  preorder[*preorderIndex],
                                                  minimum, key, size);
      root->right = RecursiveCreateBSTfromPreOrder(preorder, preorderIndex,
                                                   preorder[*preorderIndex],
                                                   key, maximum, size);
    }
  }
  return root;
}

void inorderPrint(BSTNode* root) {
  if (!root) return;
  inorderPrint(root->left);
  cout << (root->data) << " ";
  inorderPrint(root->right);
}

int main() {
  vector<int> preorder{10, 5, 1, 7, 40, 50};
  int sz = preorder.size();
  int preorderIndex = 0;
  //  BSTNode* root = RecursiveCreateBSTfromPreOrder(
  //      preorder, &preorderIndex, preorder[0], INT_MIN, INT_MAX, sz);
  //
  BSTNode* root = IterativeCreateBSTfromPreOrder(preorder);
  inorderPrint(root);
  return 0;
}
