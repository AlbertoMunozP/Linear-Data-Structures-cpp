#ifndef LISTA_ENLA_H
#define LISTA_ENLA_H

#include <cassert>

template <typename T>
class Lista {
    struct nodo;

public:
    typedef nodo* posicion;

    Lista();
    Lista(const Lista<T>& Lis);
    Lista<T>& operator=(const Lista<T>& Lis);

    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const;
    T& elemento(posicion p);
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;

    ~Lista();

private:
    struct nodo {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = nullptr) : elto(e), sig(p) {}
    };

    nodo* L;
    void copiar(const Lista<T>& Lis);
};

template <typename T>
void Lista<T>::copiar(const Lista<T>& Lis) {
    L = new nodo(T());
    nodo* q = L;
    for (nodo* r = Lis.L->sig; r; r = r->sig) {
        q->sig = new nodo(r->elto);
        q = q->sig;
    }
}

template <typename T>
inline Lista<T>::Lista() : L(new nodo(T())) {}

template <typename T>
inline Lista<T>::Lista(const Lista<T>& Lis) {
    copiar(Lis);
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& Lis) {
    if (this != &Lis) {
        this->~Lista();
        copiar(Lis);
    }
    return *this;
}

template <typename T>
inline void Lista<T>::insertar(const T& x, posicion p) {
    p->sig = new nodo(x, p->sig);
}

template <typename T>
inline void Lista<T>::eliminar(posicion p) {
    assert(p->sig);
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
}

template <typename T>
inline const T& Lista<T>::elemento(posicion p) const {
    assert(p->sig);
    return p->sig->elto;
}

template <typename T>
inline T& Lista<T>::elemento(posicion p) {
    assert(p->sig);
    return p->sig->elto;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const {
    assert(p->sig);
    return p->sig;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::anterior(posicion p) const {
    assert(p != L);
    nodo* q;
    for (q = L; q->sig != p; q = q->sig);
    return q;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const {
    return L;
}

template <typename T>
typename Lista<T>::posicion Lista<T>::fin() const {
    nodo* p;
    for (p = L; p->sig; p = p->sig);
    return p;
}

template <typename T>
Lista<T>::~Lista() {
    nodo* q;
    while (L) {
        q = L->sig;
        delete L;
        L = q;
    }
}

#endif // LISTA_ENLA_H
