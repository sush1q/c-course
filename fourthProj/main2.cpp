#include <iostream>

using namespace std;

template <typename T> 
const bool sort (T *m, int n) {
    int j;
    T tmp;
    for (int i=n-1; i>0; i--) {
        for (j=0; j<i; j++) {
            if (m[j] > m[j+1]) {
                tmp = m[j];
                m[j] = m[j+1];
                m[j+1] = tmp;
            }
        }
    }
    return true;
}

template <typename T> 
void printArr (T *m, int n) {
    for (int i=0; i<n; i++) cout << m[i] << " ";
    cout << endl;
}

int main(int argc, char** argv) {
	char carr[] = {'c', 'd', 'a'};
	int iarr[] = {3,2,4,5,1};
	float farr[] = {3.2,2.5,4.1,5.0,1.9};
	string sarr[] = {"bac", "cab", "abc"};
	
    sort(carr, 3);
    sort(iarr, 5);
    sort(farr, 5);
    sort(sarr, 3);

	printArr(carr, 3);
    printArr(iarr, 5);
    printArr(farr, 5);
    printArr(sarr, 3);
	
	return 0;
}

