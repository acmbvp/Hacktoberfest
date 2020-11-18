#include <iostream>

using namespace std;

int main()
{
    char *buffer = new char[8]; // This will allocate 8 bytes of memory in heap if char is 1 byte
    memset(buffer, 'A', 8);       // memset fills a memory block with the a character or 0/-1 integer provided
    cout << buffer << endl
         << *buffer << endl;
    char **ptr = &buffer; // Pointer to a pointer
    cout << *ptr << endl
         << **ptr << endl;
    delete[] buffer;
    return 0;
}
