#ifndef LISTA_VEC_H
#define LISTA_VEC_H
#include <cassert>

template <typename T>
 class Lista {
 	public:
 		typedef size_t posicion; // Posición de un elemento
 		explicit Lista(size_t TamaMax); // Constructor, req. ctor. T()
 		Lista(const Lista<T>& L); // Ctor. de copia, requiere ctor. T()
 		Lista<T>& operator =(const Lista<T>& L);// Asig, req. ctor. T()
 		void insertar(const T& x, posicion p);
 		void eliminar(posicion p);
 		const T& elemento(posicion p) const;// Lec. elto. en Lista const
 		T& elemento(posicion p); // Lec/Esc elto. en Lista no=const
 		posicion siguiente(posicion p) const;
 		posicion anterior(posicion p) const;
 		posicion primera() const;
 		posicion fin() const; // Posición después del último
 		~Lista(); // Destructor
	private:
 		T *elementos; // Vector de elementos
 		size_t Lmax; // Tamaño del vector
 		size_t n; // Longitud de la lista
 };
 
 // clase Lista genérica: vector pseudo=estático.
 // Una lista de longitud n se almacena en celdas
 // consecutivas del vector, desde 0 hasta n=1.
 // La posición de un elemento es el índice de la celda
 // en que se almacena.
 //
 // Implementación de operaciones
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
 		for (Lista<T>::posicion p = 0; p < n; ++p) // Copiar eltos.
 		elementos[p] = L.elementos[p];
 	}

template <typename T>
 Lista<T>& Lista<T>::operator =(const Lista<T>& L)
 {
 	if (this != &L) { // Evitar autoasignación
	 // Destruir el vector y crear uno nuevo si es necesario
		 if (Lmax != L.Lmax) {
 			delete[] elementos;
 			Lmax = L.Lmax;
 			elementos = new T[Lmax];
 		}
 		n = L.n;
 		// Copiar elementos
 		for (Lista<T>::posicion p = 0; p < n; ++p)
 			elementos[p] = L.elementos[p];
	}
	
 return *this;
 }

template <typename T>
 void Lista<T>::insertar(const T& x, posicion p) {
 	
	assert(p >= 0 && p <= n); // Posición válida
	assert(n < Lmax); // Lista no llena
 	// Desplazar los eltos. en p, p+1,..., n=1, a la siguiente posición
 	for (Lista<T>::posicion q = n; q > p; --q)
 		elementos[q] = elementos[q-1];
 	elementos[p] = x;
 	++n;
 }
 
template <typename T>
 void Lista<T>::eliminar(posicion p) {
 	
 	assert(p >= 0 && p < n); // Posición válida
 	--n;
 	// Desplazar los eltos. en p+1, p+2,...,n a la posición anterior
 	for (Lista<T>::posicion q = p; q < n; ++q)
 		elementos[q] = elementos[q+1];
}

template <typename T>
 inline const T& Lista<T>::elemento(posicion p) const {
 	assert(p >= 0 && p < n); // Posición válida
 	return elementos[p];
 }
 
template <typename T>
 inline T& Lista<T>::elemento(posicion p) {
 	assert(p >= 0 && p < n); // Posición válida
 	return elementos[p];
 }
 
template <typename T> 
 inline typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const {
 	assert(p >= 0 && p < n); // Posición válida
	return p+1;
 }
 
template <typename T> 
inline typename Lista<T>::posicion Lista<T>::anterior(posicion p) const
 {
	 assert(p > 0 && p <= n); // Posición válida
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
