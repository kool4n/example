//O(n^2)

#include <iostream>
using namespace std;

long long slowFunction(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            sum ++;
        }
    }
    return sum;
}

int main() {
    cout << slowFunction(2) << endl;
    return 0;
}