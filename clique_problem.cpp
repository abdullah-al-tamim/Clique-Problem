#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int store[MAX];
int v, e;
bool check_clique(vector<int> graph[], int k)
{
    int count = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < graph[store[i]].size(); j++)
        {
            for (int p = 1; p <= k; p++)
            {
                if (graph[store[i]][j] == store[p])
                {
                    count++;
                }
            }
        }
    }
    if (count == (k * (k - 1)))
    {
        return true;
    }
    return false;
}
void print_clique(int lim)
{
    for (int i = 1; i <= lim; i++)
    {
        cout << store[i] << " ";
    }
    cout << endl;
}
void clique(int node, int num, int k, vector<int> graph[])
{
    for (int i = node + 1; i <= v - (k - num); i++)
    {
        if (graph[i].size() >= k - 1)
        {
            store[num] = i;
            if (check_clique(graph, k))
            {
                if (num == k)
                    print_clique(num);
            }
            if (num < k)
                clique(i, num + 1, k, graph);
        }
    }
}
int main()
{
    cin >> v >> e;
    vector<int> graph[v + 1];
    int x, y;
    /*Input:
    5 6
    1 2 2 3 3 1
    3 4 4 5 5 3
    3

    Output:
    (1 2 3) (3 4 5);
    */

    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int k;
    cin >> k;
    // for (int i = 1; i <= v; i++)
    // {
    //     cout << "vertex " << i;
    //     for (int j = 0; j < (int)graph[i].size(); j++)
    //     {
    //         cout << " --> " << graph[i][j];
    //     }
    //     // cout << graph[i].size() << endl;
    //     cout << endl;
    // }
    clique(0, 1, k, graph);
}