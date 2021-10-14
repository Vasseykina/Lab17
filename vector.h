
#ifndef LAB01_VECTOR_H
#define LAB01_VECTOR_H

#include <cstddef>
#include <stdexcept>

template<class T>
class vector {
private:
    T *array;
    size_t size;
    size_t capacity;
public:
    explicit vector(const size_t &size);

    void push_back(const T &);

    size_t size_vector() { return size; };

    virtual ~vector();

    T operator[](const size_t index);

    T &at(size_t index);

    void insert(size_t index, const T &value);

    void erase(size_t index);
};

template<class T>
inline vector<T>::vector(const size_t &size)  : size(size) {
    array = new T[size];
    capacity = size;
}

template<class T>
inline vector<T>::~vector() {
    delete[] array;
    array = nullptr;
    capacity = 0;
}

template<class T>
inline void vector<T>::push_back(const T &v) {
    if (capacity == size) {
        T *arr;
        arr = new T[2 * capacity];
        for (auto i = 0; i < size; i++) {
            arr[i] = array[i];
        }
        capacity *= 2;
        delete[] array;
        array = arr;
    }
    array[size++] = v;
}

template<class T>
inline T vector<T>::operator[](const size_t index) {
    return array[index];
}

template<class T>
inline T &vector<T>::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("index out of range");
    }
    return array[index];
}

template<class T>
inline void vector<T>::insert(size_t index, const T &value) {
    if (index >= size) {
        throw std::out_of_range("index out of range");
    }
    push_back(value);
    for (auto i = size - 1; i > index; i--) {
        swap(array[i], array[i - 1]);
    }
}

template<class T>
inline void vector<T>::erase(size_t index) {
    if (index >= size) {
        throw std::out_of_range("index out of range");
    }
    for (auto i = index; i < size - 1; i++) {
        swap(array[i], array[i + 1]);
    }
    size--;
}

template<class T>
inline std::ostream &operator<<(std::ostream &out, vector<T> &v) {
    for (auto i = 0; i < v.size_vector(); i++) {
        out << v.at(i) << ' ';
    }
    return out;
}

template<class T>
inline std::istream &operator>>(std::istream &in, vector<T> &v) {
    for (auto i = 0; i < v.size_vector(); i++) {
        in >> v.at(i);
    }
    return in;
}

#endif //LAB01_VECTOR_H
