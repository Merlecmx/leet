#include<iostream>
#include<string>
#include<cassert>
using namespace std;
template <typename T>
class Myvector {
public:
    Myvector();       //���캯�� 
	Myvector(size_t n);
	Myvector(size_t n, T ele);
	
	void push_back(T ele);
	T pop_back();
	
	T& operator [](size_t i);      //�±������ 
	
	size_t size(){
		return size_l;
	}
	bool empty() {
		return size_l == 0;
	}
	~Myvector() {
		delete []data;
	}
private:
	T* data;
	size_t size_l;       //��ǰ�����Ԫ�ظ��� 
	size_t capacity;          //��ǰ������������
	bool resize (size_t newcapacity);    //���·����С
};

template <typename T> Myvector<T>::Myvector() {
	data = new T[10];
	size_l = 0;
	capacity = 10;
}

template <typename T> Myvector<T>::Myvector(size_t n) {
	data = new T[n * 2];
	size_l = n;
	capacity = n * 2;
}

template <typename T> Myvector<T>::Myvector(size_t n,T ele) {
	data = new T[n * 2];
	size_l = n;
	capacity = n * 2;
	for (size_t i = 0;i < n;i++){
		data[i] = ele;
	}
}

template <typename T> bool Myvector<T>::resize (size_t newcapacity) {
	if (newcapacity < size_l)
		return false;
	T *newdata = new T[newcapacity];
	for (size_t i = 0;i < size_l;i++){
		newdata[i] = data[i];
	}
	delete []data;
	data = newdata;
	capacity = newcapacity;
	return true;
}

template <typename T> void Myvector<T>::push_back(T ele) {
	if (size_l == capacity)
	{
		if (!resize(capacity * 2)){
			cout << "Insert the failure";
			return ;
		}
	}
	data[size_l++] = ele;
}

template <typename T> T Myvector<T>::pop_back() {
	if (size_l > 0){
		T ele = data[--size_l];
		if (size_l == capacity / 4 && capacity >= 20){     //��֤������������10��Ԫ�ص��ڴ��С 
			resize(capacity / 2);
		}
		return ele;
	}
	else
		cout << "There are no elements in the container";
}
template <typename T> T& Myvector<T>::operator [](size_t i) {
	if (i >= 0 && i < size_l)
		return data[i];
	else
		cout << i << " out of range";
}
int main()
{
	Myvector<int> ar;
	assert(ar.size() == 0);
	if (ar.empty()){
		cout << "Hello World!" << endl;
	}
	cout << "ar is size = " << ar.size() << endl;
	ar.push_back(2);
	ar.push_back(4);
	cout << ar[1] << endl;
	cout << ar[3] << endl;
	cout << ar.pop_back() << endl;
	cout << endl;
	
	Myvector<double> temp(6);
	assert(temp.size() == 6);
	
	Myvector<string> S(5,"abc");
	assert(S.size() == 5);
	cout << S.pop_back() << endl;
	return 0;
}

