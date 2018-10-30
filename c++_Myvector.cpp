#include<iostream>
#include<string>
#include<cassert>
using namespace std;
template <typename T>
class Myvector {
public:
    Myvector();       //构造函数 
	Myvector(size_t n);
	Myvector(size_t n, T ele);
	
	void push_back(T ele);
	T pop_back();
	
	T& operator [](size_t i);      //下标运算符 
	
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
	size_t size_l;       //当前数组的元素个数 
	size_t capacity;          //当前数组最大的容量
	void resize (size_t newcapacity);    //重新分配大小
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

template <typename T> void Myvector<T>::resize (size_t newcapacity) {
	assert(newcapacity >= size_l);
	T* newdata = new T[newcapacity];
	for (size_t i = 0;i < size_l;i++){
		newdata[i] = data[i];
	}
	delete []data;
	data = newdata;
	capacity = newcapacity;
}

template <typename T> void Myvector<T>::push_back(T ele) {
	if (size_l == capacity) {
		resize(capacity * 2);
	}
	data[size_l++] = ele;
}

template <typename T> T Myvector<T>::pop_back() {
	assert(size_l > 0);
	T ele = data[--size_l];
	if (size_l == capacity / 4){
		resize(capacity / 2);
	}
	return ele;
}
template <typename T> T& Myvector<T>::operator [](size_t i) {
	assert(i >= 0 && i <= size_l);
	return data[i];
}
int main()
{
	Myvector<int> ar;
	assert(ar.size() == 0);
	if (ar.empty()){
		cout << "Hello World!" << endl;
	}
	
	Myvector<double> temp(6);
	assert(temp.size() == 6);

	cout << "ar is size = " << ar.size() << endl;
	ar.push_back(2);
	ar.push_back(4);
	cout << ar[0] << endl;
	cout << ar.pop_back() << endl;
	cout << endl;
	
	Myvector<string> S(5,"abc");
	assert(S.size() == 5);
	cout << S.pop_back() << endl;
	return 0;
}
