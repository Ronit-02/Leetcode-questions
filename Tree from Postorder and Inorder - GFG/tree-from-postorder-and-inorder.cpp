// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
Node *solve(int in[], int post[], int inStart, int inEnd, int postEnd){
    
    // base case
    if(inStart > inEnd || postEnd < 0)
        return NULL;
        
    Node *root = new Node(post[postEnd]);
    
    // calculating root index in inorder
    int inRoot = 0;
    for(int i = inStart; i <= inEnd; i++){
        if(root -> data == in[i])
            inRoot = i;
    }
    
    int numsRight = inEnd - inRoot;
    
    // left subtree
    root -> left = solve(in, post, inStart, inRoot-1, postEnd-numsRight-1);
    // right subtree
    root -> right = solve(in, post, inRoot+1, inEnd, postEnd-1);
    
    return root;
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    
    return solve(in, post, 0, n-1, n-1);
}
