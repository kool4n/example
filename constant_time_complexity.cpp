#include <iostream>
using namespace std;

long long slowFunction(int n) {
    long long sum = 0;
    return (n * (n + 1)) / 2;
}

int main() {
    cout << slowFunction(2) << endl;
    return 0;
}