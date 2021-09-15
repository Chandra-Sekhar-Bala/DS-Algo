#include <iostream>
#include <queue>
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
    // cout << "MAX found " << root->info << endl;
    return root;
}


void DeleteTree(BST *root)
{
    if (!root)
        return;

    DeleteTree(root->left);
    DeleteTree(root->right);
    root->left = NULL;
    root->right = NULL;
    delete root;
}

BST *Delete(BST *root, int n)
{
    if (!root)
        return NULL;

    if (n < root->info)
        root->left = Delete(root->left, n);

    else if (n > root->info)
        root->right = Delete(root->right, n);

    else
    {
        if(root->left == NULL)
        {
            BST * temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            BST* temp = root->left;
            delete root;
            return temp;
        }
        else{
            BST * temp = FindMAX(root->left);
            root->info = temp->info;
            root->left = Delete(root->left,root->info);
        }
       
    }
    return (root);
}


void DeleteRef(BST *& root, int n)
{
    if (!root)
        return;

    if (n < root->info)
     DeleteRef(root->left, n);

    else if (n > root->info)
         DeleteRef(root->right, n);

    else
    {
        if(root->left!=NULL && root->right!=NULL){
            
            BST * temp = FindMAX(root->left);
            root->info = temp->info;
            Delete(root->left,root->info);
        }
        else{
        BST* temp = root;
        
        if(!root->left)
        root= root->right;
        else if(!root->right)
        root = root->left;

        delete temp;
        }
    }
    return ;
}

BST *find(BST *root, int n)
{
    if (!root)
        return NULL;

    if (n < root->info)
        return find(root->left, n);
    if (n > root->info)
        return find(root->right, n);

    return root;
}
int Height(BST *root)
{
    if (!root)
        return 0;

    int Lheight = Height(root->left);
    int Rheight = Height(root->right);

    if (Lheight > Rheight)
        return Lheight + 1;
    return Rheight + 1;
}
void PrintLevel(BST* root,int n){
    if(!root)
    return;
    else if(n==0)
    cout << root->info <<" ";
    else{
        PrintLevel(root->left,n-1);
        PrintLevel(root->right,n-1);
    }

}
void LevelOrder(BST* root){
    int height = Height(root);
    for(int i=0; i<height; i++){
        PrintLevel(root,i);
    }


}
void levelOrder(BST *root)
{
    if (!root)
        return;
    queue<BST *> q;
    BST *temp;
    q.push(root);

    while (q.empty() == false)
    {
        temp = q.front();
        cout << temp->info << " ";
        q.pop();

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}
void Print2D(BST* root,int space){
    if(!root)
    return;
    space+=5;
    Print2D(root->right,space);
    cout << endl;
    for(int i=5;i<space; i++)
    cout << " ";
    cout << root->info <<endl;
    Print2D(root->left,space);
}
int main()
{
    BST *root = NULL;
    int ch;
    while (1)
    {
        cout << ".....1:insert 2: Find 3:Delete 4:PreOrder,5:inOrder,6:Print 2D,7:LevelOrder 8:DeleteTree 9:EXIT........" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter Value " << endl;
            cin >> ch;
            insert(root, ch);
            break;
        }
        case 2:
        {
            cout << "Enter Value " << endl;
            cin >> ch;
            BST *temp = find(root, ch);
            if (temp)
                cout << "Found: " << temp->info;
            else
                cout << "Not found " << endl;
            break;
        }
        case 3:
        {
            cout << "Enter Value " << endl;
            cin >> ch;
            DeleteRef(root, ch);
            break;
        }
        case 4:
            cout << "Preorder: " << endl;
            preorder(root);
            break;

        case 5:
            cout << "Inoder: " << endl;
            inorder(root);
            break;
        case 6:
            cout << "PRint2D: " << endl;
            Print2D(root,5);
            break;
        case 7:
            cout << "Level order: " << endl;
            LevelOrder(root);
            break;
        case 8:
            DeleteTree(root);
            break;
        case 9:
            cout << "Exit code 000 " << endl;
            return 0;
        default:
            cout << "Wrong Choise " << endl;
        }
    }
}