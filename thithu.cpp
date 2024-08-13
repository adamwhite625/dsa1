#include <iostream>
#include <cmath>

using namespace std;

 struct diem{
        float x;
        float y;
        float z;
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
  
  bool isEmpty(List l){
    if(l.head == NULL) return true;
    return false;
}
    
void addHead(List& l, diem x){
    Node* p = createNode(x);
    if(isEmpty(l)) l.head = l.tail = p;
    else{
        p->next = l.head;
        l.head = p;
    }
}

    void addTail(List& l, diem x){
        Node* p = createNode(x);
        if(isEmpty(l)){
            l.head = l.tail = p;
        
        }
        else{
            l.tail->next = p;
            l.tail = p;
        }
    }

 void nhap(List& l){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            diem a;
            cin >> a.x >> a.y >> a.z;
            addTail(l, a);
        }
    }

void search(List& l, List& l1){
	
	
	Node* q = l1.head;
	while(q != NULL){
		Node* p = l.head;
		int cnt = 0;
		while(p != NULL){
			if(q->data.x == p->data.x && q->data.y == p->data.y && q->data.z == p->data.z){
				cout << cnt << endl;
				break;
				
			}
			else{
			p= p->next;
			cnt++;
			
		}
		}
		if(p == NULL){
		cout << "KHONG" << endl;
	}
		q = q->next;
		cnt++;
	}
}    

void run(){
   
    
    List l;
    init(l);
	nhap(l);
	List l1;
	init(l1);
	nhap(l1);
	
   search(l, l1);
}

int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}
