#include <iostream>
#include <string>
#include "listaenla.hpp"  

class Cartelera {
private:
    struct Sala {
        std::string nombre;  
        ListaEnla<std::string> espectaculos;  
    };

    ListaEnla<Sala> salas;  

public:

    void CrearCartelera() {
    
    }

    void AnadirSala(const std::string& nombreSala) {
        for (auto it = salas.primera(); it != salas.fin(); it = salas.siguiente(it)) {
            if (salas.elemento(it).nombre == nombreSala) {
                return;  
            }
        }

        Sala nuevaSala;
        nuevaSala.nombre = nombreSala;
        salas.insertar(nuevaSala, salas.fin());
    }


    void AnadirEspectaculo(const std::string& nombreSala, const std::string& espectaculo) {
        for (auto it = salas.primera(); it != salas.fin(); it = salas.siguiente(it)) {
            if (salas.elemento(it).nombre == nombreSala) {

                for (auto itEsp = salas.elemento(it).espectaculos.primera(); itEsp != salas.elemento(it).espectaculos.fin(); itEsp = salas.elemento(it).espectaculos.siguiente(itEsp)) {
                    if (salas.elemento(it).espectaculos.elemento(itEsp) == espectaculo) {
                        return;  
                    }
                }
                salas.elemento(it).espectaculos.insertar(espectaculo, salas.elemento(it).espectaculos.fin());
                return;
            }
        }
        std::cout << "Sala no encontrada." << std::endl;
    }

    void EliminarSala(const std::string& nombreSala) {
        for (auto it = salas.primera(); it != salas.fin(); it = salas.siguiente(it)) {
            if (salas.elemento(it).nombre == nombreSala) {
                salas.eliminar(it);
                return;
            }
        }
    }

    void EliminarEspectaculo(const std::string& nombreSala, const std::string& espectaculo) {
        for (auto it = salas.primera(); it != salas.fin(); it = salas.siguiente(it)) {
            if (salas.elemento(it).nombre == nombreSala) {
                for (auto itEsp = salas.elemento(it).espectaculos.primera(); itEsp != salas.elemento(it).espectaculos.fin(); itEsp = salas.elemento(it).espectaculos.siguiente(itEsp)) {
                    if (salas.elemento(it).espectaculos.elemento(itEsp) == espectaculo) {
                        salas.elemento(it).espectaculos.eliminar(itEsp);
                        return;
                    }
                }
            }
        }
    }

    void MostrarSalas() {
        for (auto it = salas.primera(); it != salas.fin(); it = salas.siguiente(it)) {
            std::cout << salas.elemento(it).nombre << std::endl;
        }
    }

    void MostrarEspectaculos(const std::string& nombreSala) {
        for (auto it = salas.primera(); it != salas.fin(); it = salas.siguiente(it)) {
            if (salas.elemento(it).nombre == nombreSala) {
                std::cout << "Espectáculos en " << nombreSala << ": ";
                for (auto itEsp = salas.elemento(it).espectaculos.primera(); itEsp != salas.elemento(it).espectaculos.fin(); itEsp = salas.elemento(it).espectaculos.siguiente(itEsp)) {
                    std::cout << salas.elemento(it).espectaculos.elemento(itEsp) << " ";
                }
                std::cout << std::endl;
                return;
            }
        }
        std::cout << "Sala no encontrada." << std::endl;
    }

    void MostrarEspectaculosConjunto() {
        ListaEnla<std::string> espectaculosConjunto;
        for (auto it = salas.primera(); it != salas.fin(); it = salas.siguiente(it)) {
            for (auto itEsp = salas.elemento(it).espectaculos.primera(); itEsp != salas.elemento(it).espectaculos.fin(); itEsp = salas.elemento(it).espectaculos.siguiente(itEsp)) {
                if (!EspectaculoExiste(espectaculosConjunto, salas.elemento(it).espectaculos.elemento(itEsp))) {
                    espectaculosConjunto.insertar(salas.elemento(it).espectaculos.elemento(itEsp), espectaculosConjunto.fin());
                }
            }
        }
        std::cout << "Espectáculos en conjunto: ";
        for (auto itEsp = espectaculosConjunto.primera(); itEsp != espectaculosConjunto.fin(); itEsp = espectaculosConjunto.siguiente(itEsp)) {
            std::cout << espectaculosConjunto.elemento(itEsp) << " ";
        }
        std::cout << std::endl;
    }

    void MostrarSalasPorEspectaculo(const std::string& espectaculo) {
        ListaEnla<std::string> salasConEspectaculo;
        for (auto it = salas.primera(); it != salas.fin(); it = salas.siguiente(it)) {
            for (auto itEsp = salas.elemento(it).espectaculos.primera(); itEsp != salas.elemento(it).espectaculos.fin(); itEsp = salas.elemento(it).espectaculos.siguiente(itEsp)) {
                if (salas.elemento(it).espectaculos.elemento(itEsp) == espectaculo) {
                    if (!SalaExiste(salasConEspectaculo, salas.elemento(it).nombre)) {
                        salasConEspectaculo.insertar(salas.elemento(it).nombre, salasConEspectaculo.fin());
                    }
                }
            }
        }
        std::cout << "Salas que ofrecen " << espectaculo << ": ";
        for (auto itSala = salasConEspectaculo.primera(); itSala != salasConEspectaculo.fin(); itSala = salasConEspectaculo.siguiente(itSala)) {
            std::cout << salasConEspectaculo.elemento(itSala) << " ";
        }
        std::cout << std::endl;
    }

private:
    bool EspectaculoExiste(const ListaEnla<std::string>& lista, const std::string& espectaculo) {
        for (auto it = lista.primera(); it != lista.fin(); it = lista.siguiente(it)) {
            if (lista.elemento(it) == espectaculo) {
                return true;
            }
        }
        return false;
    }

    bool SalaExiste(const ListaEnla<std::string>& lista, const std::string& sala) {
        for (auto it = lista.primera(); it != lista.fin(); it = lista.siguiente(it)) {
            if (lista.elemento(it) == sala) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Cartelera cartelera;

    cartelera.CrearCartelera();

    cartelera.AnadirSala("Sala 1");
    cartelera.AnadirSala("Sala 2");

    cartelera.AnadirEspectaculo("Sala 1", "Espectáculo A");
    cartelera.AnadirEspectaculo("Sala 1", "Espectáculo B");
    cartelera.AnadirEspectaculo("Sala 2", "Espectáculo B");
    cartelera.AnadirEspectaculo("Sala 2", "Espectáculo C");

    cartelera.MostrarSalas();

    cartelera.MostrarEspectaculos("Sala 1");

    cartelera.MostrarEspectaculosConjunto();

    cartelera.MostrarSalasPorEspectaculo("Espectáculo B");

    return 0;
}
