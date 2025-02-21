#include <iostream>

using namespace std;

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    // Declare an array of pointers to int arrays
    int **jaggedArray = new int*[numRows];

    // Input for each row
    for (int i = 0; i < numRows; ++i) {
        int numCols;
        cout << "Enter number of columns for row " << i << ": ";
        cin >> numCols;

        // Allocate memory for this row
        jaggedArray[i] = new int[numCols];

        // Input elements for this row
        cout << "Enter " << numCols << " elements for row " << i << ": ";
        for (int j = 0; j < numCols; ++j) {
            cin >> jaggedArray[i][j];
        }
    }
   int q;
   std::cin>>q;
   for(int i=0;i<q;i++){
      int a,b;
      std::cin>>a>>b;
      std::cout<<jaggedArray[a][b];
   }

    // Deallocate memory
    for (int i = 0; i < numRows; ++i) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}
