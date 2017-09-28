#ifndef SISTEMA_H
#define SISTEMA_H

#include "imagen.h"

/*!
 * \brief Clase para interconectar todos los módulos de SVIM
 */
class Sistema
{
private:
    void printImagenPorConsola(Imagen & img);
public:
    Sistema();
    void testImagenAndPixel();
    void testArchivador();
};

#endif // SISTEMA_H
