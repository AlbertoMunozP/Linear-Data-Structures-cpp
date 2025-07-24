#ifndef TADLISTACIRCULAR_H_INCLUDED
#define TADLISTACIRCULAR_H_INCLUDED
#include <cassert>


template <typename T> class ListaCir {
    struct nodo; 
    public:
        typedef nodo* posicion; 
        ListaCir();
        ListaCir(const ListaCir<T>& l);
        ListaCir<T>& operator =(const ListaCir<T>& l);
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const;
        T& elemento(posicion p);
        posicion buscar(const T& x) const;
        posicion inipos() const;
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        ~ListaCir(); 
    private:
        struct nodo {
            T elto;
            nodo *sig;
            nodo(const T& e, nodo* s = 0): elto(e), sig(s) {}
        };
    nodo* L; 
    const posicion POS_NULA = 0;

    void copiar(const ListaCir<T>& l);
};

template <typename T> void ListaCir<T>::copiar(const ListaCir<T> &l) {
    nodo* q = L;
    for (nodo* r = l.L->sig; r; r = r->sig) {
        q-> sig =new nodo (r->elto);
        q = q->sig;
    }
}

template <typename T> inline ListaCir<T>::ListaCir() : L(0) {
}

template <typename T> inline ListaCir<T>::ListaCir(const ListaCir<T>& l) {
     copiar(l);
}

template <typename T> ListaCir<T>& ListaCir<T>::operator =(const ListaCir<T>& l) {
    if (this != &l) {
        this->~ListaCir();
        copiar(l);
    }
    return *this;
}

template <typename T> void ListaCir<T>::insertar(const T& x, ListaCir<T>::posicion p) {
    if (L == 0){
        L = new nodo(T());
        L->sig = L;
        L->elto = x;
    } else
        p->sig = new nodo(x, p->sig);
}

template <typename T> void ListaCir<T>::eliminar(ListaCir<T>::posicion p) {
    assert(p != POS_NULA);
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
}

template <typename T> inline const T& ListaCir<T>::elemento(ListaCir<T>::posicion p) const {
    return p->sig->elto;
}

template <typename T> inline T& ListaCir<T>::elemento(ListaCir<T>::posicion p) {
    return p->sig->elto;
}

template <typename T> typename ListaCir<T>::posicion ListaCir<T>::buscar(const T& x) const {
    nodo* q = L;
    bool encontrado = false;
    while (q->sig != L && !encontrado){
        if (q->sig->elto == x)
            encontrado = true;
        else q = q->sig;
    }
    if (q->sig == L && q->elto != x) q = POS_NULA; 
    return q;
}

template <typename T> inline typename ListaCir<T>::posicion ListaCir<T>::inipos() const {
    return L;
}

template <typename T> inline typename ListaCir<T>::posicion ListaCir<T>::siguiente(ListaCir<T>::posicion p) const {
     return p->sig;
}

template <typename T> inline typename ListaCir<T>::posicion ListaCir<T>::anterior(ListaCir<T>::posicion p) const {
    nodo *q;

    for (q = L; q->sig != p; q = q->sig);
    return q;
}

template <typename T> ListaCir<T>::~ListaCir() {
    nodo* q;
    while (L->sig != L) {
        q = L->sig;
        L->sig = q->sig;
        delete q;
    }
    delete L;
}


#endif 
