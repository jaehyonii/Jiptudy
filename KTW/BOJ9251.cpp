#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lcs(string &a, string &b, int m, int n, vector <vector <int> > &mm)
{
    if (m == 0 || n == 0)
        return 0; // empty string
    if (mm.at(m-1).at(n-1) != -1) // already find
        return mm.at(m-1).at(n-1);
    if (a.at(m-1) == b.at(n-1)) // last character matched
        return mm.at(m-1).at(n-1) = 1 + lcs(a, b, m-1, n-1, mm);
    int x = lcs(a, b, m, n-1, mm);
    int y = lcs(a, b, m-1, n, mm);
    int max = mm.at(m-1).at(n-1) = (x>y ? x : y); // no match
    return max;
}

int main(){
    string a, b;
    
    cin >> a >> b;
    int m = a.length();
    int n = b.length();
    vector <vector <int> > memo(m, vector<int>(n, -1)); // memoization vector, init by -1
    
    cout << lcs(a, b, m, n, memo);
    return 0;
}