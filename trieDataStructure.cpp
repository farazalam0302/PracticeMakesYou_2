/**
 *
 *
 * links : https://www.geeksforgeeks.org/trie-insert-and-search/
 * https://medium.com/basecs/trying-to-understand-tries-3ec6bede0014
 *
 *
 *
 *
 *  */
#include <bits/stdc++.h>
#define ALPHABETS 256
using namespace std;
class TrieNode {
public:
  TrieNode *kids[ALPHABETS]; // 26 characters only lowercase letters
  bool wordEnd;
  TrieNode() {
    wordEnd = false;
    for (int i = 0; i < ALPHABETS; i++) {
      this->kids[i] = NULL;
    }
  }
  // TrieNode()
};

void insert(TrieNode *R, string key) {
  TrieNode *spider = R;
  for (int i = 0; i < key.length(); i++) {
    int index = key[i]; //- 'a';
    if (!(spider->kids[index])) {
      spider->kids[index] = new TrieNode();
    }
    spider = spider->kids[index];
  }
  spider->wordEnd = true;
}

bool search(TrieNode *R, string key) {
  TrieNode *spider = R;

  for (int i = 0; i < key.length(); i++) {
    int index = key[i]; //- 'a';
    if (!(spider->kids[index])) {
      return false;
    }
    spider = spider->kids[index];
  }
  return (spider != NULL && spider->wordEnd);
}

int main() {

  vector<string> keys{"the", "a",  "there", "answer",
                      "any", "by", "bye",   "their"};
  TrieNode *Root = new TrieNode();
  for (int i = 0; i < keys.size(); i++) {
    insert(Root, keys[i]);
  }
  bool ret = search(Root, "the");
  ret ? cout << "YES" << endl : cout << "NO" << endl;
  search(Root, "ALAM") ? cout << "YES" << endl : cout << "NO" << endl;
  search(Root, "a") ? cout << "YES" << endl : cout << "NO" << endl;
  search(Root, "by") ? cout << "YES" << endl : cout << "NO" << endl;
  search(Root, "b") ? cout << "YES" << endl : cout << "NO" << endl;

  return 0;
}
/*
// C++ program for a Trie based O(n) solution to find max
// subarray XOR
#include<bits/stdc++.h>
using namespace std;

// Assumed int size
#define INT_SIZE 32

// A Trie Node
struct TrieNode
{
        int value; // Only used in leaf nodes
        TrieNode *arr[2];
};

// Utility function tp create a Trie node
TrieNode *newNode()
{
        TrieNode *temp = new TrieNode;
        temp->value = 0;
        temp->arr[0] = temp->arr[1] = NULL;
        return temp;
}

// Inserts pre_xor to trie with given root
void insert(TrieNode *root, int pre_xor)
{
        TrieNode *temp = root;

        // Start from the msb, insert all bits of
        // pre_xor into Trie
        for (int i=INT_SIZE-1; i>=0; i--)
        {
                // Find current bit in given prefix
                bool val = pre_xor & (1<<i);

                // Create a new node if needed
                if (temp->arr[val] == NULL)
                        temp->arr[val] = newNode();

                temp = temp->arr[val];
        }

        // Store value at leaf node
        temp->value = pre_xor;
}

// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
int query(TrieNode *root, int pre_xor)
{
        TrieNode *temp = root;
        for (int i=INT_SIZE-1; i>=0; i--)
        {
                // Find current bit in given prefix
                bool val = pre_xor & (1<<i);

                // Traverse Trie, first look for a
                // prefix that has opposite bit
                if (temp->arr[1-val]!=NULL)
                        temp = temp->arr[1-val];

                // If there is no prefix with opposite
                // bit, then look for same bit.
                else if (temp->arr[val] != NULL)
                        temp = temp->arr[val];
        }
        return pre_xor^(temp->value);
}

// Returns maximum XOR value of a subarray in arr[0..n-1]
int maxSubarrayXOR(int arr[], int n)
{
        // Create a Trie and insert 0 into it
        TrieNode *root = newNode();
        insert(root, 0);

        // Initialize answer and xor of current prefix
        int result = INT_MIN, pre_xor =0;

        // Traverse all input array element
        for (int i=0; i<n; i++)
        {
                // update current prefix xor and insert it into Trie
                pre_xor = pre_xor^arr[i];
                insert(root, pre_xor);

                // Query for current prefix xor in Trie and update
                // result if required
                result = max(result, query(root, pre_xor));
        }
        return result;
}

// Driver program to test above functions
int main()
{
        int arr[] = {8, 1, 2, 12};
        int n = sizeof(arr)/sizeof(arr[0]);
        cout << "Max subarray XOR is " << maxSubarrayXOR(arr, n);
        return 0;
}


*/