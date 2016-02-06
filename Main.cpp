#include <iostream>
#include <cstdio>
#include <cstring>

#include "MinHeap.h"
#include "Node.h"
#include "Encode.h"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) { 
        cerr << "Usage: "<< argv[0] << " encode/decode" << " TextFileName" << endl; 
        exit(1);
    }
    if (strcmp(argv[1],"encode") == 0) {
        char ch;
        freopen(argv[2],"r",stdin);
        int* array = new int[27];
        // Insert characters by ASCII values into array of size 27
        while (cin >> noskipws >> ch) {
            if((int)(ch - 97) >= 0 && (int)(ch - 97) <= 25)
                array[(int)(ch - 97)]++;
            // Insert spaces at the end of the array *ASCII value not in same range
            else if((int)(ch - 97) == -65)
                array[26]++;
        }
        MinHeap h(array);
        Encode huffman(h);
        int arr[30];
        huffman.encodeCharacters(huffman.getRoot(), arr, 0);
        fclose(stdin);
        cin.clear();
        freopen(argv[2],"r",stdin);
        while (cin >> noskipws >> ch) {
            huffman.printHuffmanCode(ch);
        }
        cout << endl;
        fclose(stdin);
        cin.clear();
    }
    else if (strcmp(argv[1], "decode") == 0) {
        string code;
        freopen(argv[2],"r",stdin);
        
    }
    else {
        cerr << "Usage: "<< argv[0] << " encode/decode" << " TextFileName" << endl; 
        exit(1);
    }
    
    return 0;
}