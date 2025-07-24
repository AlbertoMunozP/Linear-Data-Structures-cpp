#include <iostream>
#include "colaenla.hpp"  
#include <string>

class Usuario {
public:
    ColaEnla<std::string> colaUrgentes;   
    ColaEnla<std::string> colaNoUrgentes; 

    Usuario() {}  
};

class GestorDeImpresion {
private:
    Usuario* usuarios;   
    int numUsuarios;     
    int turnoActual;     

public:

    GestorDeImpresion(int n) : numUsuarios(n), turnoActual(0) {
        usuarios = new Usuario[numUsuarios];  
    }

    ~GestorDeImpresion() {
        delete[] usuarios;  
    }


    void AñadirTrabajo(int idUsuario, const std::string& trabajo, bool urgente) {
        if (idUsuario >= 0 && idUsuario < numUsuarios) {
            if (urgente) {
                usuarios[idUsuario].colaUrgentes.push(trabajo);     
            } else {
                usuarios[idUsuario].colaNoUrgentes.push(trabajo); 
            }
        } else {
            std::cout << "Usuario no válido.\n";
        }
    }

    std::string EliminarTrabajoImprimir() {
        int intentos = 0;

        while (intentos < numUsuarios) {
            int idUsuario = turnoActual;

            if (!usuarios[idUsuario].colaUrgentes.vacia()) {
                std::string trabajo = usuarios[idUsuario].colaUrgentes.frente();
                usuarios[idUsuario].colaUrgentes.pop();  
                AvanzarTurno();
                return trabajo;
            } else if (!usuarios[idUsuario].colaNoUrgentes.vacia()) {
                std::string trabajo = usuarios[idUsuario].colaNoUrgentes.frente();
                usuarios[idUsuario].colaNoUrgentes.pop();                  AvanzarTurno();
                return trabajo;
            }

            AvanzarTurno();
            intentos++;
        }

        throw std::runtime_error("No hay trabajos para imprimir.");
    }

    void CancelarTrabajosUsuario(int idUsuario) {
        if (idUsuario >= 0 && idUsuario < numUsuarios) {
            while (!usuarios[idUsuario].colaUrgentes.vacia()) {
                usuarios[idUsuario].colaUrgentes.pop();
            }
            while (!usuarios[idUsuario].colaNoUrgentes.vacia()) {
                usuarios[idUsuario].colaNoUrgentes.pop();
            }
        } else {
            std::cout << "Usuario no válido.\n";
        }
    }

private:
    void AvanzarTurno() {
        turnoActual = (turnoActual + 1) % numUsuarios;
    }
};

int main() {
    GestorDeImpresion gestor(3);  

    gestor.AñadirTrabajo(0, "Trabajo1", true);  
    gestor.AñadirTrabajo(1, "Trabajo2", false);  
    gestor.AñadirTrabajo(2, "Trabajo3", true);  

    std::cout << "Trabajo a imprimir: " << gestor.EliminarTrabajoImprimir() << std::endl;
    std::cout << "Trabajo a imprimir: " << gestor.EliminarTrabajoImprimir() << std::endl;

    gestor.CancelarTrabajosUsuario(1);  

    std::cout << "Trabajo a imprimir: " << gestor.EliminarTrabajoImprimir() << std::endl;

    return 0;
}
gh