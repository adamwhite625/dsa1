#include <iostream>
#include <cmath>

using namespace std;

void run(){
    struct diem{
        int x;
        int y;
        int z;
    };

    struct Node{
        diem data;
        Node* next;
    };

    struct List{
        Node* head;
        Node* tail;
    };

    void init(List& l){
        l.head = l.tail = NULL;
    }

    Node* createNode(diem x){
        Node* p = new Node;
        if(p == NULL) exit(1);
        p->data = x;
        p->next = NULL;
        return p;
    }

    void addTail(List& l, diem x){
        Node* p = createNode(x);
        if(l.head == l.tail){
            l.head = l.tail = p;
            return;
        }
        else{
            l.tail->next = p;
            l.tail = p;
        }
    }

    List l;
    init(l);

    void nhap(){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            diem a;
            cin >> a.x >> a.y >> a.z;
            addtail(l, a);
        }
    }
}

int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}