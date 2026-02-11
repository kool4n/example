#include <iostream>
using namespace std;

void function(int n) {
      for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            value += 1;
            cout << value << " ";
        }
    }
}

int main() {
    int value = 0;
    int n = 5;
    function(n, value);

    return 0;
}