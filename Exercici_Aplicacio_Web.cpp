#include <iostream>
#include <string>
using namespace std;

class SessioUsuari
{
private:
    string nomUsuari;
    int tempsLlimitSegons;
    bool activa;   //Sessió oberta (true) o tancada (false)

    void tancarSessio() {
        activa = false;
    }

public:

    SessioUsuari() {   //Creó el método constructor por defecto, el cual no recibe parámetros
        nomUsuari = "convidat";
        tempsLlimitSegons = 300;
        activa = true;
    }

    explicit SessioUsuari(string nom) {   //Creó el método constructor explicit, porque trae un parámetro
        nomUsuari = nom;
        tempsLlimitSegons = 600;
        activa = true;
    }

    explicit SessioUsuari(string nom, int temps) :   //Creó el método constructor explicit, porque trae parámetros
        nomUsuari(nom), tempsLlimitSegons(temps <= 0 ? 60 : temps), activa(true) {
    }

    string getNomUsuari() const {
        return nomUsuari;
    }

    bool isActiva() const {
        return activa;
    }

    void ampliarTemps(int segons) {
        if (segons <= 0) {
            cout << "Error: temps fora de rang!" << endl;
        }
        else {
            tempsLlimitSegons += segons;
        }
    }

    ~SessioUsuari() {   //Destructor
        if (activa) {
            tancarSessio();
            cout << "[AUDITORIA] La sessio de " << nomUsuari << " s'ha tancat automaticament en sortir d'ambit." << endl;
        }
    }

};

int main()
{
    SessioUsuari sessio1;
    SessioUsuari sessio2("Nicoll");
    SessioUsuari sessio3("Alejandra", 400);

    return 0;
}
