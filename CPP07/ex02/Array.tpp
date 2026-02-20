/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:59:47 by sbruma            #+#    #+#             */
/*   Updated: 2026/02/20 11:59:47 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : arr(nullptr), n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), n(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other) : arr(new T[other.n]()), n(other.n) {
    for (unsigned int i = 0; i < n; ++i) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] arr;
        n = other.n;
        arr = new T[n]();
        for (unsigned int i = 0; i < n; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= n) {
        throw OutOfBoundsException();
    }
    return arr[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return n;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return "Index out of bounds";
}