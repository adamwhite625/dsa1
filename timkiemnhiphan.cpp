#include <iostream>
using namespace std;


struct diem{
        float x;
        float y;
        float z;
};

int sosanh(diem a, diem b){
	if(a.x < b.x) return -1;
	else if(a.x == b.x){
		if(a.y < b.y) return -1;
		else if(a.y == b.y){
			if(a.z < b.z) return -1;
			else return 0;
		}
		else return 1;
	}
	else return 1;
}

void binarysearch(diem a[], diem b[], int n, int m){
	int i = 0;
	while(i <= m){
		int l = 0;
		int r = n - 1;
		while(l <= r){
			int cnt = 1;
			int m = (l+r) / 2;
			if(sosanh(b[i], a[m]) == -1){
				r = m - 1;
			}
			else if(sosanh(b[i], a[m]) == 0){
				cout << cnt << endl;
				break;
			}
			else{
				l = m +1;
			}
			cnt++;
		}
		i++;
		cout << "KHONG" << endl;
	}
}

diem a[100000];
	diem b[100000];
    
int main(){
	
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> b[i].x >> b[i].y >> b[i].z;
	}
	
	binarysearch(a, b, n, m);
	return 0;
}
