#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

struct Trie
{
    vector<Trie *> lttr;
    bool isEnd;
    Trie()
    {
        lttr = vector<Trie *>(26, NULL);
        isEnd = false;
    }
};

void insert(Trie *root, string s)
{
    Trie *temp = root;
    for (int i = 0; i < s.length(); ++i)
    {
        int ind = s[i] - 'a';
        if (temp->lttr[ind] == NULL)
            temp->lttr[ind] = new Trie;
        temp = temp->lttr[ind];
    }
    temp->isEnd = true;
}

bool search(Trie *root, string s)
{
    Trie *temp = root;
    for (int i = 0; i < s.length(); ++i)
    {
        int ind = s[i] - 'a';
        if (temp->lttr[ind] == NULL)
            return false;
        temp = temp->lttr[ind];
    }
    return temp->isEnd;
}

int main()
{
    vector<string> arr = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = arr.size();
    Trie *root = new Trie;
    for (int i = 0; i < n; ++i)
    {
        insert(root, arr[i]);
    }
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}