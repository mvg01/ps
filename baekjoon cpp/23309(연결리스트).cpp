#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int id;
    Node *prev;
    Node *next;
    Node(int id) : id(id), prev(nullptr), next(nullptr) {}
};

unordered_map<int, Node *> ma;
int n, m;
Node *head;

void solve()
{
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        int x, y;
        if (s == "BN")
        {
            cin >> x >> y;
            Node *c = ma[x];
            Node *new_node = new Node(y);
            cout << c->next->id << '\n';
            new_node->prev = c;
            new_node->next = c->next;
            c->next->prev = new_node;
            c->next = new_node;
            ma[y] = new_node;
        }
        else if (s == "BP")
        {
            cin >> x >> y;
            Node *c = ma[x];
            Node *new_node = new Node(y);
            cout << c->prev->id << '\n';
            new_node->prev = c->prev;
            new_node->next = c;
            c->prev->next = new_node;
            c->prev = new_node;
            ma[y] = new_node;
        }
        else if (s == "CN")
        {
            cin >> x;
            Node *c = ma[x];
            Node *del = c->next;
            cout << c->next->id << '\n';
            c->next = del->next;
            del->next->prev = c;
            delete del;
        }
        else if (s == "CP")
        {
            cin >> x;
            Node *c = ma[x];
            Node *del = c->prev;
            cout << c->prev->id << '\n';
            c->prev = del->prev;
            del->prev->next = c;
            delete del;
        }
    }
}

void input()
{
    cin >> n >> m;
    Node *prev = nullptr;
    head = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *node = new Node(x);
        ma[x] = node;
        if (head == nullptr)
        {
            head = node;
        }
        else
        {
            node->prev = prev;
            prev->next = node;
        }
        prev = node;
    }
    prev->next = head;
    head->prev = prev;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}