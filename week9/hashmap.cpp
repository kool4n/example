#include <iostream>
#include <list>
#include <utility>
using namespace std;

struct CountryNode {
    string country;
    string code;
    CountryNode* next;

    CountryNode(string c; string cd) : country(c), next(nullptr) {}
};

class HashTable {
    private:
    static const int TABLE_SIZE = 10;
    CountryNode* table[TABLE_SIZE];

    int hashFunction(string key) {
        int hash = 0;
        for (char c : key) {
            hash += (int)c;
        }

        return hash % TABLE_SIZE;
    }
}

public: 
HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

void insert(string country, string code) {
    int index = hashFunction(country);
    CountryNode* newNode = new CountryNode(country, code);

    if (table[index] == nullptr) {
        table[index] == newNode;

        cout << "inserted: " << country << " ->" << code << "at index"
    }
}