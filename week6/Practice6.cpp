#include <iostream>
using namespace std;

// Node structure for a Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};
// Function to create a new Node
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data; 
    newNode->left = newNode->right = nullptr;
    return newNode;
}
// Function to insert a node in the BST
Node* insertNode(Node* root, int data)
{
    // If the tree is empty, return a new node
    if (root == nullptr) { 
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    // return the (unchanged) node pointer
    return root;
}
// Function to do inorder traversal of BST
void inorderTraversal(Node* root)
{
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
// Function to search a given key in a given BST
Node* searchNode(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < key) {
        return searchNode(root->right, key);
    }

    // Key is smaller than root's key
    return searchNode(root->left, key);
}

void cheekSearch(Node* root, int key)
{
    
    // Search a key in BST
    Node* found = searchNode(root, key);

    // check if the key is found or not
    if (found != nullptr) {
        cout << "Node " << key <<" is found in the BST." << endl;
    }
    else {
        cout << "Node " << key <<" is NOT found in the BST." << endl;
    }
}

// Function to find the inorder successor
Node* minValueNode(Node* node)
{
    Node* current = node;
    // loop down to find the leftmost leaf
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node
Node* deleteNode(Node* root, int x)
{
    if (root == nullptr)
    {
        return root;    
    }

    // If the data to be deleted is smaller than the root's
    // data, then it lies in the left subtree
    else if (x < root->data)
    {
        root->left = deleteNode(root->left, x);
    }

    // If the data to be deleted is greater than the root's
    // data, then it lies in the right subtree
    else if (x > root->data)
    {
        root->right = deleteNode(root->right, x);
    }
    
    // Found then get ready to deleted
    else 
    {
        // case 1: No child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // case 2: One child
        else if(root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else
        {
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
    Node* root = nullptr;
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 10);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 14);
    root = insertNode(root, 4);
    root = insertNode(root, 13);

    cout << "Inorder traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    // case 1: no child
    root = deleteNode(root, 1);
    cout << "After deletion of 1: ";
    inorderTraversal(root);
    cout << endl;

    // case 2: one child
    root = deleteNode(root, 14);
    cout << "After deletion of 14: ";
    inorderTraversal(root);
    cout << endl;

    // case 3: 2 child
    root = deleteNode(root, 6);
    cout << "After deletion of 14: ";
    inorderTraversal(root);
    cout << endl;

    cheekSearch(root, 7);

    return 0;
}