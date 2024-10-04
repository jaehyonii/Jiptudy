#include <bits/stdc++.h>

using namespace std;

class PriorityQueue {
    private:
        int arr[100001];
        int idx;
    public:
        PriorityQueue() {
            idx = 1; // place to insert data
        }
    
        int length() {
            return idx-1;
        }
        
        void insert (int n) {
            int id;
            
            id = idx++;
            while (id/2 > 0 && arr[id/2] > n) {
                arr[id] = arr[id/2];
                id /= 2;
            }
            arr[id] = n;
        }

        int dele() {
            int ret = arr[1];
            int num, min, id;
            
            num = arr[--idx]; 
            id = 1;
            while (id*2 < idx) {
                if (id*2+1 == idx) {
                    if (arr[id*2] >= num)
                        break;
                    id *= 2;
                    arr[id/2] = arr[id];
                    break;
                }
                
                id = (arr[id*2] < arr[id*2+1]) ? id*2 : id*2+1;
                min = arr[id];

                if (min >= num) {
                    id /= 2;
                    break;
                }
                arr[id/2] = min;
            }
            arr[id] = num;
            return ret;
        }
};

int main() {
    PriorityQueue q;
    int num, len, sum;
    int n1, n2;
    
    cin >> len;
    for (int i = 0; i < len; i++) {
        cin >> num;
        q.insert(num);
    }
    if (q.length() == 1) {
        cout << 0;
        return 0;
    }
    sum = 0;
    while (q.length() != 1) {
        n1 = q.dele();
        n2 = q.dele();
        sum += n1 + n2;
        q.insert(n1 + n2);
    }
    cout << sum << "\n";
    return 0;
}