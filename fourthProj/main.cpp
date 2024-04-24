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

		const int getItem(const int) const;
		const bool setItem(const int, const int);
		const bool insertItem(const int, const int);
		const bool addItem(const int);

		const bool addArray(const int*, const int);
		const bool setArray(const int*, const int);
		const bool sort(void);
		const int findItem(const int) const;
		
		const TArray operator+(const TArray &rval) const;
		const TArray operator=(const TArray &rval);
		
		const bool printArray(void) const;

	private:
		void init(int*, int);
		const bool validateIndex(int) const;
		const bool setNewM(int*);
		
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

TArray::TArray (const TArray &val) {
	m=val.m;
	n=val.n;
}

const bool TArray::setNewM (int *new_m) {
	delete []m;
	m=new_m;
}

const bool TArray::validateIndex (int index) const {
	if ((index>=0)&&(index<n)) return true;
	return false;
}

const int TArray::getItem (const int i) const {
	if (validateIndex(i)) return m[i];
	return 0;
}

const bool TArray::printArray (void) const {
	for (int i=0; i<this->length(); i++) {
		cout << this->getItem(i) << " ";
	}
	cout << endl;
}

const bool TArray::addItem (const int data) {
	int *new_m=new int[++n];
	if (new_m == NULL) {n--; return false;}
	for (int i=0; i<n-1; i++) new_m[i]=m[i];
	new_m[n-1]=data;
	setNewM(new_m);
	return true;
}

const bool TArray::setItem (const int i, const int data) {
	if (!validateIndex(i)) return false;
	TArray::m[i]=data;
	return true;
}

const bool TArray::insertItem(const int index, const int data) {
	if (!validateIndex(index)) return false;
	int *new_m=new int[++n];
	int new_i=0;
	if (new_m == NULL) {n--; return false;}
	for (int i=0; i<n; i++) {
		if (i==index) new_m[i] = data, new_i++;
		new_m[i+new_i] = m[i];
	}
	setNewM(new_m);
	return true;
}

const bool TArray::addArray(const int *arr, const int size) {
	if (size<0) return false;
	int new_n = n+size;
	int *new_m=new int[new_n];
	if (new_m == NULL) return false;
	
	for (int i=0; i<n; i++) new_m[i] = m[i];
	if (m==NULL) {
		for (int i=0; i<size; i++) new_m[n+i] = 0;
	} else {
		for (int i=0; i<size; i++) new_m[n+i] = arr[i];
	}
	
	setNewM(new_m);
	n=new_n;
	return true;
}

const bool TArray::setArray(const int *arr, const int size) {
	if (size<0) return false;
	int *new_m=new int[size];
	if (new_m == NULL) return false;

	for (int i=0; i<size; i++) new_m[i] = arr[i];

	setNewM(new_m);
	n=size;
	return true;
}

const bool TArray::sort(void) {
    int j;
    int tmp;
    for (int i=n-1; i>0; i--) {
        for (j=0; j<i; j++) {
            if (m[j] > m[j+1]) {
                tmp = m[j];
                m[j] = m[j+1];
                m[j+1] = tmp;
            }
        }
    }
}

const int TArray::findItem (const int elem) const {
	for(int i=0; i<n;i++) {
		if (m[i] == elem) return i;
	}
	return -1;
}

const TArray TArray::operator+ (const TArray &rval) const {
	TArray res(m,n);
	res.addArray(rval.m, rval.n);
	return res;
}

const TArray TArray::operator= (const TArray &rval) {
	m=rval.m;
	return *this;
}

int main(void) {
	
	int m[] = {1,2,3,4,5};
	int unsorted[] = {5,2,3,1,4};
	TArray arr1(m, 5);

	arr1.printArray();
	arr1.addItem(6);
	arr1.printArray();
	arr1.setItem(5, 7);
	arr1.printArray();
	arr1.insertItem(5, 6);
	arr1.printArray();
	
	TArray arr2(arr1);
	arr2.printArray();
	arr2.addArray(m, 5);
	arr2.printArray();
	arr2.setArray(unsorted, 5);
	arr2.printArray();
	arr2.sort();
	arr2.printArray();
	cout << arr2.findItem(2) << endl;
	
	TArray arr3 = arr1 + arr2;
	arr3.printArray();
	

	return 0;
}
