#include <iostream>
#include "pilaenla.hpp"  

class Tren {
private:
    PilaEnla<int> izquierda;
    PilaEnla<int> derecha;

public:

    Tren() {}

    void DesplazarIzquierda() {
        if (!derecha.vacia()) {
            izquierda.push(derecha.tope());  
            derecha.pop();
        }
    }

    void DesplazarDerecha() {
        if (!izquierda.vacia()) {
            derecha.push(izquierda.tope());
            izquierda.pop();
        }
    }

    void EliminarVagonActivo() {
        if (!derecha.vacia()) {
            derecha.pop();
        } else if (!izquierda.vacia()) {
            izquierda.pop();
        }
    }

    void InsertarVagon(int nuevoVagon) {
        derecha.push(nuevoVagon);
    }

    int ObservarVagonActivo() const {
        if (!derecha.vacia()) {
            return derecha.tope();  
        } else if (!izquierda.vacia()) {
            return izquierda.tope();
        } else {
            throw std::runtime_error("El tren está vacío.");
        }
    }

    bool TrenVacio() const {
        return derecha.vacia() && izquierda.vacia();  
    }
};

int main() {
    Tren tren;

    tren.InsertarVagon(1);
    tren.InsertarVagon(2);
    tren.InsertarVagon(3);

    std::cout << "Vagón activo: " << tren.ObservarVagonActivo() << std::endl;

    tren.DesplazarIzquierda();  
    std::cout << "Vagón activo tras desplazar a la izquierda: " << tren.ObservarVagonActivo() << std::endl;

    tren.DesplazarDerecha();
    std::cout << "Vagón activo tras desplazar a la derecha: " << tren.ObservarVagonActivo() << std::endl;

    tren.EliminarVagonActivo();
    std::cout << "Vagón activo tras eliminar: " << tren.ObservarVagonActivo() << std::endl;

    tren.EliminarVagonActivo();
    std::cout << "Vagón activo tras eliminar otro: " << tren.ObservarVagonActivo() << std::endl;

    if (tren.TrenVacio()) {
        std::cout << "El tren está vacío." << std::endl;
    } else {
        std::cout << "El tren no está vacío." << std::endl;
    }

    return 0;
}
