#ifndef LISTA_VEC_H
#define LISTA_VEC_H
#include <cassert>

template <typename T>
 class Lista {
 	public:
 		typedef size_t posicion; 
 		explicit Lista(size_t TamaMax);
 		Lista(const Lista<T>& L);
 		Lista<T>& operator =(const Lista<T>& L);
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
 		T *elementos; 
 		size_t Lmax; 
 		size_t n; 
 };
 

template <typename T>
 inline Lista<T>::Lista(size_t TamaMax) :
	elementos(new T[TamaMax]),
	Lmax(TamaMax),
	n(0) {}	
	
template <typename T>
 Lista<T>::Lista(const Lista<T>& L) :
	elementos(new T[L.Lmax]),
 	Lmax(L.Lmax),
 	n(L.n)
 	{
 		for (Lista<T>::posicion p = 0; p < n; ++p) 
 		elementos[p] = L.elementos[p];
 	}

template <typename T>
 Lista<T>& Lista<T>::operator =(const Lista<T>& L)
 {
 	if (this != &L) { 
		
		 if (Lmax != L.Lmax) {
 			delete[] elementos;
 			Lmax = L.Lmax;
 			elementos = new T[Lmax];
 		}
 		n = L.n;

		for (Lista<T>::posicion p = 0; p < n; ++p)
 			elementos[p] = L.elementos[p];
	}
	
 return *this;
 }

template <typename T>
 void Lista<T>::insertar(const T& x, posicion p) {
 	
	assert(p >= 0 && p <= n); 
	assert(n < Lmax); 
	
 	for (Lista<T>::posicion q = n; q > p; --q)
 		elementos[q] = elementos[q-1];
 	elementos[p] = x;
 	++n;
 }
 
template <typename T>
 void Lista<T>::eliminar(posicion p) {
 	
 	assert(p >= 0 && p < n); 
 	--n;

	for (Lista<T>::posicion q = p; q < n; ++q)
 		elementos[q] = elementos[q+1];
}

template <typename T>
 inline const T& Lista<T>::elemento(posicion p) const {
 	assert(p >= 0 && p < n); 
 	return elementos[p];
 }
 
template <typename T>
 inline T& Lista<T>::elemento(posicion p) {
 	assert(p >= 0 && p < n); 
 	return elementos[p];
 }
 
template <typename T> 
 inline typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const {
 	assert(p >= 0 && p < n); 
	return p+1;
 }
 
template <typename T> 
inline typename Lista<T>::posicion Lista<T>::anterior(posicion p) const
 {
	 assert(p > 0 && p <= n); 
 	return p-1;
 }
 
template <typename T> 
 inline typename Lista<T>::posicion Lista<T>::primera() const
 	{ return 0; }
 	
template <typename T> 
 inline typename Lista<T>::posicion Lista<T>::fin() const
 	{ return n; }
 	
template <typename T>
 inline Lista<T>::~Lista()
 {
 delete[] elementos;
 }
 
#endif
