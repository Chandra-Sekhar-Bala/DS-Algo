#include <iostream>
using namespace std;
class BST
{
public:
    int info;
    BST *left;
    BST *right;

    BST()
    {
        left = NULL;
        right = NULL;
    }
};

void insert(BST *&root, int x)
{
    BST *n = new BST;
    n->info = x;
    if (!root)
    {
        root = n;
        return;
    }

    BST *temp = root;
    while (temp)
    {
        if (x < temp->info)
        {
            if (temp->left)
            {
                temp = temp->left;
            }
            else
            {
                temp->left = n;
                return;
            }
        }
        else if (x > temp->info)
        {
            if (temp->right)
            {
                temp = temp->right;
            }
            else
            {
                temp->right = n;
                return;
            }
        }
        else
        {
            cout << "Exist " << endl;
            return;
        }
    }
}
void preorder(BST *root)
{
    if (!root)
        return;
    cout << root->info << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(BST *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->info << " ";
    inorder(root->right);
}
void postoder(BST *root)
{
    if (!root)
        return;
    postoder(root->left);
    postoder(root->right);
    cout << root->info << " ";
}

BST *FindMAX(BST *root)
{
    while (root->right)
    {
        root = root->right;
    }
    cout << "MAX found " << root->info << endl;
    return root;
}
/*
BST* Delete(BST * root, int n)
{
    // cout << root << endl;
    if (!root)
        return NULL;

    if (n < root->info)
        root->left =Delete(root->left, n);

    else if (n > root->info)
        root->right =Delete(root->right, n);

    else
    {
        if (root->left && root->right)
        {
            // Found that node, with 2 or more childream
            BST *temp = FindMAX(root->left);
            root->info = temp->info;
            // cout << "TEMP: "<< root->info << endl;
            root->left = Delete(root->left, root->info);
        }
        else
        {
            // Only one child
            // cout << "Element  " << root->info <<endl;

            BST *temp = root;
            if (!root->left)
                root = root->right;
            if (!root->right)
                root = root->left;

            // root->right = root->left = NULL;
            free(temp);
        }
    }
    return (root);
}*/

BST* Delete(BST * root, int n)
{
    // cout << root << endl;
    if (!root)
        return NULL;

    if (n < root->info)
        root->left =Delete(root->left, n);

    else if (n > root->info)
        root->right =Delete(root->right, n);

    else
    {
        if (root->left && root->right)
        {
            // Found that node, with 2 or more childream
            BST *temp = FindMAX(root->left);
            root->info = temp->info;
            // cout << "TEMP: "<< root->info << endl;
            root->left = Delete(root->left, root->info);
        }
        else
        {
            // Only one child
            // cout << "Element  " << root->info <<endl;

            BST *temp = root;
            if (!root->left)
                root = root->right;
            if (!root->right)
                root = root->left;

            // root->right = root->left = NULL;
            free(temp);
        }
    }
    return (root);
}

int main()
{
    BST *root = NULL;
    cout << "ROOT " << root << endl;
    int ch;
    insert(root, 4);
    insert(root, 8);
    insert(root, 3);
    insert(root, 9);
    insert(root, 5);
    insert(root, 7);
    insert(root, 6);
    cout << endl
         << "Preorder: " << endl;
    preorder(root);
    cout << endl
         << "Inoder: " << endl;
    inorder(root);
    cout << endl
         << "Postorder: " << endl;
    postoder(root);
    cout << endl
         << "" << endl;
    Delete(root, 8);
    cout << endl
         << "Preorder again: " << endl;
    preorder(root);

    return 0;
}