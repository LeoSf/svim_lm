#include <iostream>
#include "sistema.h"

using namespace std;
/*!
 * \brief función main
 * \return 0: salida normal
 */
int main(int argc, char *argv[])
{
    cout << "SVIM Project" << endl<< endl;
    Sistema sis;

    /** Test de la implementación de Imagen y Pixel */
//    sis.testImagenAndPixel();

    /** Test de la lectura de un archivo */
//    sis.testArchivador();

    /** Test de graficación de una imagen */
    sis.testGraficador(argc, argv);

    return 0;
}
