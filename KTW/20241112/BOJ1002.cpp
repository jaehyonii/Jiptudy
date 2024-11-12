#include <bits/stdc++.h>
#define dis_pow(x1, x2, y1, y2) ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))
using namespace std;

int main() {
    int x1,y1,r1,x2,y2,r2;
    int test, dist_pow;
    
    cin >> test;
    vector <int> v(test);
    for (int i = 0; i < test; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        dist_pow = dis_pow(x1, x2, y1, y2);
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2)
                v[i] = -1;
            else
                v[i] = 0;
        }
        else {
            if ((r1+r2)*(r1+r2) < dist_pow || (r2-r1)*(r2-r1) > dist_pow)
                v[i] = 0;
            else if ((r1+r2)*(r1+r2) == dist_pow || (r2-r1)*(r2-r1) == dist_pow)
                v[i] = 1;
            else
                v[i] = 2;
        } 
    }
    for (int i = 0; i < test; i++)
        cout << v[i] << "\n";
    return 0;
}