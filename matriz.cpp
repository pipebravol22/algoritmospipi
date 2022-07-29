// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int matriz[3][3];
    
    for(int i=0; i<3;i++) {
        for(int j=0; j<3;j++) {
            matriz[i][j] = i*3 + j;
            cout << matriz[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    
    for(int i=0; i<3;i++) {
        for(int j=0; j<3;j++) {
            cout << matriz[j][i];
        }
        cout << "\n";
    }

    return 0;
}
