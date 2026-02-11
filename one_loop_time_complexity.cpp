#include <iostream>
using namespace std;

long long slowFunction(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    cout << slowFunction(2) << endl;
    return 0;
}