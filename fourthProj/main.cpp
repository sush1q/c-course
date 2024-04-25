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
		const bool init(const int*, const int);
		const bool validateIndex(int) const;
		
		int n;
		int *m;
};

const bool TArray::init (const int *m, const int n) {
	int *tmp = new int[n];
	if (tmp==NULL) return false;

	if (m==NULL && TArray::m == NULL) {
		for (int i=0; i<n; i++) tmp[i] = 0;
	} else if (m==NULL && TArray::m != NULL) {
		for (int i=0; i<n; i++) {
			tmp[i] = TArray::m[i];
			if (i>=TArray::n) tmp[i] = 0;
		}
	} else {
		for (int i=0; i<n; i++) tmp[i] = m[i];
	}

	if (TArray::m != NULL) delete []TArray::m;
	TArray::n = n;
	TArray::m = tmp;
	return true;
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
	init(val.m, val.n);
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
	for (int i=0; i<n; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
	return true;
}

const bool TArray::addItem (const int data) {
	init(NULL, n+1);
	m[n-1]=data;
	return true;
}

const bool TArray::setItem (const int i, const int data) {
	if (!validateIndex(i)) return false;
	TArray::m[i]=data;
	return true;
}

const bool TArray::insertItem(const int index, const int data) {
	if (!validateIndex(index)) return false;
	int tmp1,tmp2;
	init(NULL, n+1);
	
	tmp1 = m[index];
	m[index] = data;

	for (int i=index+1; i<n; i++) {
		tmp2 = m[i];
		m[i] = tmp1;
	}

	return true;
}

const bool TArray::addArray(const int *arr, const int size) {
	if (size<0) return false;
	int old_n = n;
	init(NULL, n+size);

	if (arr!=NULL) {
		for (int i=0; i<size; i++) m[old_n+i] = arr[i];
	}

	return true;
}

const bool TArray::setArray(const int *arr, const int size) {
	if (size<0) return false;
	return init(arr, size);
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
    return true;
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
	init(rval.m, rval.n);
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
	cout << arr2.findItem(3) << endl;

	(arr1 + arr2).printArray();
	TArray arr3 = arr1 + arr2;
	arr3.printArray();

	return 0;
}
