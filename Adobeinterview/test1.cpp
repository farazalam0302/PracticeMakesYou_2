class BST {
  /*
   * left, right, data Node
   */
 public:
  vector<Node*> inordered;
  vector<Node*> : iterator crawler;
  Node* root;
  Node* inorder(Node* root, vector<Node*>& in) {
    if (!root) return nullptr;
    inorder(root->left);
    in.push_back(root);
    inorder(root->right);
  }

  BST(Node* bstroot) {
    inorder(bstroot, inordered);
    crawler = inordered.begin();
  }

  int getCurrentData() {
    if (!crawler) return crawler->data;
  }

  void next() {
    if (!crawler) return;  // null check

    crawler++;
    return crawler->data;
  };
