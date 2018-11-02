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
    
    T& operator [](size_t i){      //下标运算符
        return data[i];
    }

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
    bool resize (size_t newcapacity);    //重新分配大小
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
    if (size_l == capacity && !resize(capacity * 2))
        return ;
    data[size_l++] = ele;
}

template <typename T> T Myvector<T>::pop_back() {
    return data[--size_l];
}

int main()
{
    Myvector<int> ar;
    assert(ar.size() == 0);
    assert(ar.empty());
    ar.push_back(2);
    ar.push_back(4);
    assert(ar[0] == 2);
    assert(ar[1] == 4);
    assert(ar.pop_back() == 4);
    
    Myvector<double> temp(6);
    assert(temp.size() == 6);
    
	
    Myvector<string> S(5,"abc");
    assert(S.size() == 5);
    assert(S[3] == "abc");
    assert(S.pop_back() == "abc");
    return 0;
}
