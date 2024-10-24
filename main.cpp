
#include <SerieNavidad.hpp>
#include <Lienzo.hpp>
#include <Vector.hpp>
#include <unistd.h>

int main(int argc, char const *argv[]){
    Vector p(0,5);
    Vector t (100,100);

    Lienzo lienzo(p,t);
    SerieNavidad serie(10);
    SerieNavidad serie2(10);

    bool estado = true;
    int incremento = 0;
    while (true){
        //Celula que explota 
        serie.Alternar(estado);
        lienzo.Dibujar(serie);
        estado = estado ? false : true;
        sleep(1);
        lienzo.Limpiar();
        // incremento
        serie2.apagar();
        serie2.Encender(5);
        lienzo.Dibujar(serie2);
        incremento++;
    }
/*    serie.Imprimir();
    serie.encender();
    serie.Imprimir();
    serie.apagar();
    serie.Imprimir();
    serie.Alternar(true);
    serie.Imprimir();
    serie.Alternar(false);
    serie.Imprimir(); 
    bool estado = true;
    while (true){
        serie.Alternar(estado);
        serie.Imprimir();
        estado = estado ? false : true;
    }
    */

    return 0;
}
