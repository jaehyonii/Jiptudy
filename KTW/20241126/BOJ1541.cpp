#include <bits/stdc++.h>

using namespace std;

int main() {
    char arr[51];
    char tmp[51];
    vector <int> nums;
    vector <char> ops;
    
    char *str;
    
    cin >> arr;
    strcpy(tmp, arr);
    str = strtok(tmp, "+-");
    if (str)
        nums.push_back(atoi(str));
    while (str = strtok(NULL, "+-"))
        nums.push_back(atoi(str));
    strcpy(tmp, arr);
    str = strtok(tmp, "0123456789");
    if (str)
        ops.push_back(*str);
    while (str = strtok(NULL, "0123456789"))
        ops.push_back(*str);
    while (true) {
        int i;
        for (i = 0; i < ops.size(); i++) {
            if (ops[i] == '+') {
                nums[i] += nums[i+1];
                nums.erase(nums.begin()+i+1);
                ops.erase(ops.begin()+i);
                break;
            }
        }
        if (i == ops.size())
            break;
    }
    for (int i = 0; i < ops.size(); i++)
        nums[0] -= nums[i+1];
    cout << nums[0];
    return 0;
}