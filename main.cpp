#include <iostream>
#include "sistema.h"

using namespace std;
/*!
 * \brief función main
 * \return 0: salida normal
 */
int main()
{
    cout << "SVIM Project" << endl<< endl;
    Sistema sis;

    /** Test de la implementación de Imagen y Pixel */
    sis.testImagenAndPixel();

    return 0;
}
