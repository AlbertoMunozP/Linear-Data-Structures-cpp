#ifndef TADCOLADINAMICA_H_INCLUDED
#define TADCOLADINAMICA_H_INCLUDED

#include <cassert>

template <typename T>
class ColaD {
public:
    ColaD();
    ColaD(const ColaD<T>& C);
    ColaD<T>& operator=(const ColaD<T>& C);
    bool vacia() const;
    const T& frente() const;
    void pop();
    void push(const T& x);
    ~ColaD();

private:
    struct nodo {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = nullptr) : elto(e), sig(p) {}
    };
    nodo* inicio;
    nodo* fin;
    void copiar(const ColaD<T>& C);
};

template <typename T>
void ColaD<T>::copiar(const ColaD<T>& C) {
    if (C.inicio) {
        inicio = fin = new nodo(C.inicio->elto);
        for (nodo* p = C.inicio->sig; p; p = p->sig) {
            fin->sig = new nodo(p->elto);
            fin = fin->sig;
        }
    }
}

template <typename T>
inline ColaD<T>::ColaD() : inicio(nullptr), fin(nullptr) {}

template <typename T>
inline ColaD<T>::ColaD(const ColaD<T>& C) : inicio(nullptr), fin(nullptr) {
    copiar(C);
}

template <typename T>
inline ColaD<T>& ColaD<T>::operator=(const ColaD<T>& C) {
    if (this != &C) {
        this->~ColaD();
        copiar(C);
    }
    return *this;
}

template <typename T>
inline bool ColaD<T>::vacia() const {
    return inicio == nullptr;
}

template <typename T>
inline const T& ColaD<T>::frente() const {
    assert(!vacia());
    return inicio->elto;
}

template <typename T>
inline void ColaD<T>::pop() {
    assert(!vacia());
    nodo* p = inicio;
    inicio = inicio->sig;
    if (!inicio) fin = nullptr;
    delete p;
}

template <typename T>
inline void ColaD<T>::push(const T& x) {
    nodo* p = new nodo(x);
    if (!inicio)
        inicio = fin = p;
    else
        fin = fin->sig = p;
}

template <typename T>
ColaD<T>::~ColaD() {
    nodo* p;
    while (inicio) {
        p = inicio->sig;
        delete inicio;
        inicio = p;
    }
    fin = nullptr;
}

#endif
