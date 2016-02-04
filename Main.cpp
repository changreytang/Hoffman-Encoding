#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char ch;
    freopen("test.txt","r",stdin);
    int* array = new int[27];
    while (cin >> noskipws >> ch) {
        if((int)(ch - 97) >= 0 && (int)(ch - 97) <= 25)
            array[(int)(ch - 97)]++;
        else if((int)(ch - 97) == -65)
            array[26]++;
    }
    for (int i=0; i < 27; i++) {
        cout << array[i] << endl;
    }
    
    return 0;
}