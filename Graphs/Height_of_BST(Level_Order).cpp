#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

int height(struct Node *root)
{
    int ht = 1;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.empty() == false)
    {
        // cout << ht << endl;
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (q.empty() == false)
            {
                q.push(NULL);
                ht++;
            }
        }
        else
        {
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    return ht;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(12);
    root->right = newNode(13);

    root->right->left = newNode(14);
    root->right->right = newNode(15);

    root->right->left->left = newNode(21);
    root->right->left->right = newNode(22);
    root->right->right->left = newNode(23);
    root->right->right->right = newNode(24);

    cout << "Height(Depth) of tree is: " << height(root);
}