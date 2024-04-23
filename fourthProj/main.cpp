#include <iostream>
#ifndef DEFAULT_SIZE
#define DEFAULT_SIZE 5
#endif


using namespace std;

class TArray {
	public:
		TArray();
		TArray(int);
		TArray(int*, int);
		TArray(const TArray&);
		~TArray();
		
		const int length(void) const { return n; }

		const int getItem(int) const;
		const bool setItem(int, int);
		const bool insertItem(int, int);
		const bool addItem(int);

		const bool addArray(TArray*);
		const bool addArray(int*);
		const bool setArray(TArray*);
		const bool setArray(int*);
		
		const bool printArray(void) const;

	private:
		void init(int*, int);
		int n;
		int *m;
};

void TArray::init (int *m, int n) {
	TArray::n = n;
	TArray::m = new int[n];
	if (m==NULL) {
		for (int i=0; i<n; i++) TArray::m[i] = 0;
	} else {
		for (int i=0; i<n; i++) TArray::m[i] = m[i];
	}	
}

TArray::TArray () {
	init(NULL, DEFAULT_SIZE);
}

TArray::TArray (int size) {
	init(NULL, size);
}

TArray::TArray (int *m, int n) {
	init(m, n);
}

TArray::~TArray () {
	delete []m;
}

const int TArray::getItem (int i) const {
	if ((i>=0)&&(i<n)) return m[i];
	return 0;
}

const bool TArray::printArray (void) const {
	for (int i=0; i<this->length(); i++) {
		cout << this->getItem(i) << " ";
	}
	cout << endl;
}

const bool TArray::addItem (int data) {
	n++;
	int *new_m=new int[n];
	if (!new_m) {
		n--;
		return false;
	}
	for (int i=0; i<n-1; i++) new_m[i]=m[i];
	new_m[n-1]=data;
	delete []m;
	m=new_m;
	return true;
}

const bool TArray::setItem (int i, int data) {
	if ((i<0)&&(i>n)) return false;
	TArray::m[i]=data;
	return true;
}

const bool TArray::insertItem(int i, int data) {
	if ((i<0)&&(i>n)) return false;
	
}


int main(void) {
	
	int m[] = {1,2,3,4,5};
	TArray arr1(m, 5);

	arr1.printArray();
	arr1.addItem(6);
	arr1.printArray();
	arr1.setItem(5, 7);
	arr1.printArray();
	arr1.insertItem(5, 6);
	arr1.printArray();
	

	return 0;
}
