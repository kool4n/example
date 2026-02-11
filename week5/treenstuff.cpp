#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;    
    Node(int item)
    {
        key = item;
        left = NULL;
        right = NULL;
    }
};
// Insert data to node
Node* insert(Node* node, int data) 
{
    if (node == NULL) 
        return new Node(data);    
    if (node->key == data) 
        return node;
    if (node->key < data) 
        node->right = insert(node->right, data);
    else 
        node->left = insert(node->left, data);
    return node;
}

// Traverse Inorder
void traverseInOrder(Node *root) 
{
    if (root != NULL) 
    {
        traverseInOrder(root->left);
        cout << " " << root->key;
        traverseInOrder(root->right);
    }
}
// Traverse Preorder
void traversePreOrder(Node *root) 
{
    if (root != NULL) 
    {
        cout << " " << root->key;
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }
}
// Traverse Postorder
void traversePostOrder(Node *root) 
{
    if (root != NULL) 
    {
        traversePostOrder(root->right);
        traversePostOrder(root->left);
        cout << " " << root->key;
    }
}
// Driver program to test the above functions
int main() {
    Node* root = new Node(27);  
    root = insert(root, 14);
    root = insert(root, 35);
    root = insert(root, 10);
    root = insert(root, 19);
    root = insert(root, 31);
    root = insert(root, 42);

    // Print inorder traversal of the BST
    cout << "Traverse InOrder: "; 
    traverseInOrder(root);
    cout << endl;

    cout << "Traverse PreOrder: ";
    traversePreOrder(root);
    cout << endl;

    cout << "Traverse PostOrder: ";
    traversePostOrder(root);
    cout << endl;

    return 0;
}


