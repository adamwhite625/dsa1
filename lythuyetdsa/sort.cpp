#include <bits/stdc++.h>
using namespace std;

//selection sort
void selectionsort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        //dung 1 bien de luu tru chi so cua phan tu nho nhat
        int min_pos = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min_pos]){
                min_pos = j;
            }
        }
        swap(a[i], a[min_pos]);
    }
}

//bubble sort
void bubblesort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j ++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}

//insertion sort
void insertionsort(int a[], int n){
    for(int i = 1; i < n; i++){
        //lay ra phan tu o chi so i
        int x = a[i], pos = i - 1;
        while(pos >= 0 && x < a[pos]){
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = x;
    }
}

//merge sort
void merge(int a[], int l, int m, int r){
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while( i < x.size() && j < y.size(){
        if(x[i] <= y[j]){
            a[l] = x[i]; ++l; ++i;
        }
        else{
            a[l] = y[j]; ++l; ++j;
        }
    }
    while(i < x.size()){
        a[l] = x[i]; ++l; ++i;
    }
    while(j < y.size()){
        a[l] = y[j]; ++l; ++j;
    }
}

void mergesort(int a[i], int l, int r){
    if( l >= r) return;
    int m = (l + r) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge(a, l, m, r);
}

//quicksort lomuto
int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] <= pivot){
            ++i;
            swap(a[i], a[j]);
        }
    }
    // dua chot ve giua
    ++i;
    swap(a[i], a[r]);
    return i; // vi tri
}

void quicksort(int a[], int l, int r){
    if(l >= r) return;
    int p = partition(a, l, r);
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, r);
}

//heap sort
void heapify(int a[], int n, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if(l < n && a[l] > a[largest]){
        largest = l;
    }
    if(r < n && a[r] > a[largest]){
        largest = r;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n){
    //xay dung max heap
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
    //
    for(int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

map<string, set<pair<string, int>>> adj;

void nhap(){
    int m;
    string s, t;
    cin >> m >> s >> t;
    for(int i = 0; i < m; i++){
        string x, y;
        int w;
        cin >> x >> y >> w;
        adj[x].insert({y, w});
    }
}

map<string, set<pair<string, int>>> adj;

void nhap(){
    int m;
    string s, t;
    cin >> m >> s >> t;
    for(int i = 0 ; i < m; i++){
        string x, y;
        int w;
        cin >> x >> y >>w;
        adj[x].insert({y, w});
    }
}

const int inf = 1e9;
map<string, string> pre;

void dijkstra(const string& s, const string& t){
    map<string, long long> d;
    map<string, bool> visited;

    for(const auto& p : adj){
        d[p.first] = inf;
    }

    d[s] = 0;
    pre[s] = s;

    priority_queue<pair<long long, string>, vector<pair<long long, string>>, greater<pair<long long, string>>> Q;

    Q.push({0, s});

    while(!Q.empty()){
        pair<long long, string> top = Q.top(); Q.pop();
        string u = top.second;
        long long kc = top.first;

        if(visited[u]) continue;
        visited[u] = true;

        for(const auto& it : adj[u]){
            string v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
                pre[v] = u;
            }
        }
    }

    cout << d[t];

    vector<string> path;
    string current = t;
    while(1){
        path.push_back(current);
        if(current == s) break;
    }
}