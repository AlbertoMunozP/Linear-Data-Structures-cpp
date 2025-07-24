#ifndef TADPILADINAMICA_H
#define TADPILADINAMICA_H

#include <cassert>

template <typename tElemento>
class PilaD {
public:
    explicit PilaD();
    PilaD(const PilaD<tElemento>& P);
    PilaD<tElemento>& operator=(const PilaD<tElemento>& P);
    bool vacia() const;
    const tElemento& tope() const;
    tElemento pop();
    void push(const tElemento& x);
    ~PilaD();

private:
    struct nodo {
        tElemento elto;
        nodo* sig;
        nodo(const tElemento& e, nodo* p = nullptr) : elto(e), sig(p) {}
    };
    nodo* tope_;
    void copiar(const PilaD<tElemento>& P);
};

template <typename tElemento>
inline PilaD<tElemento>::PilaD() : tope_(nullptr) {}

template <typename tElemento>
PilaD<tElemento>::PilaD(const PilaD<tElemento>& P) : tope_(nullptr) {
    copiar(P);
}

template <typename tElemento>
PilaD<tElemento>& PilaD<tElemento>::operator=(const PilaD<tElemento>& P) {
    if (this != &P) {
        this->~PilaD();
        copiar(P);
    }
    return *this;
}

template <typename tElemento>
inline bool PilaD<tElemento>::vacia() const {
    return tope_ == nullptr;
}

template <typename tElemento>
inline const tElemento& PilaD<tElemento>::tope() const {
    assert(!vacia());
    return tope_->elto;
}

template <typename tElemento>
inline tElemento PilaD<tElemento>::pop() {
    assert(!vacia());
    nodo* p = tope_;
    tope_ = p->sig;
    tElemento eltoAux = p->elto;
    delete p;
    return eltoAux;
}

template <typename tElemento>
inline void PilaD<tElemento>::push(const tElemento& x) {
    tope_ = new nodo(x, tope_);
}

template <typename tElemento>
PilaD<tElemento>::~PilaD() {
    nodo* p;
    while (tope_) {
        p = tope_->sig;
        delete tope_;
        tope_ = p;
    }
}

template <typename tElemento>
void PilaD<tElemento>::copiar(const PilaD<tElemento>& P) {
    if (!P.vacia()) {
        tope_ = new nodo(P.tope());
        nodo* p = tope_;
        nodo* q = P.tope_->sig;
        while (q) {
            p->sig = new nodo(q->elto);
            p = p->sig;
            q = q->sig;
        }
    }
}

#endif
