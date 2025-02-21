#include <iostream>

using namespace std;

int main() {

   std::string a;
   std::string query;
   std::getline(std::cin,a);
   int n=a[0]-'0';
   int q=a[2] - '0';

    // Declare an array of pointers to int arrays
    int **jaggedArray = new int*[n];

    // Input for each row
    for (int i = 0; i < n; ++i) {
        int numCols;
        cin >> numCols;

        // Allocate memory for this row
        jaggedArray[i] = new int[numCols];

        // Input elements for this row
        for (int j = 0; j < numCols; ++j) {
            cin >> jaggedArray[i][j];
        }
    }

    // Output the jagged array
   //  for (int i = 0; i < n; ++i) {
   //      int numCols = sizeof(jaggedArray[i]) / sizeof(int); // Incorrect method, should use numCols from input
   //      cout << "Row " << i << ": ";
   //      for (int j = 0; j < numCols; ++j) {
   //          cout << jaggedArray[i][j] << " ";
   //      }
   //      cout << endl;
   //  }
    
   for(int x=0;x<q;x++){
      std::getline(std::cin,query);
      int k=query[0]-'0';
      int l=query[2]-'0';
      // std::string out=array[k];
      // std::cout<<"out ="<<out;
      // std::cout<<out[2*l]<<'\n';
      cout << jaggedArray[k][l] << " ";
   }

    // Deallocate memory
    for (int i = 0; i < n; ++i) {
        delete[] jaggedArray[i];
    }
    delete[] jaggedArray;

    return 0;
}
