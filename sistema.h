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
    void testArchivos();
};

#endif // SISTEMA_H
