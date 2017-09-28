#include "imagen.h"
#include "pixel.h"

string Imagen::getMetadatos() const
{
    return metadatos;
}

void Imagen::setMetadatos(const string &value)
{
    metadatos = value;
}

Imagen::Imagen()
{
    xSizePx = 0 ;
    ySizePx = 0 ;
    xSize = 0 ;
    ySize = 0 ;
    unitOfMeasurement = "mm" ;
    metadatos = "no metadata yet";
}

/* ----------------------- Setters ----------------------- */
void Imagen::setXSizePx(unsigned int value)
{
    xSizePx = value;
}

void Imagen::setYSizePx(unsigned int value)
{
    ySizePx = value;
}

void Imagen::setXSize(unsigned int value)
{
    xSize = value;
}

void Imagen::setYSize(unsigned int value)
{
    ySize = value;
}

void Imagen::setUnitOfMeasurement(const string &value)
{
    unitOfMeasurement = value;
}

/* ----------------------- Getters ----------------------- */
unsigned int Imagen::getXSizePx() const
{
    return xSizePx;
}

unsigned int Imagen::getYSizePx() const
{
    return ySizePx;
}

unsigned int Imagen::getXSize() const
{
    return xSize;
}

unsigned int Imagen::getYSize() const
{
    return ySize;
}

string Imagen::getUnitOfMeasurement() const
{
    return unitOfMeasurement;
}

/* ------------ Public methods to manipulate an image ------------ */

void Imagen::resizeImage()
{
    /** Redimensiono la imagen si ambos índices son distintos de cero */
    if(xSizePx && ySizePx)
    {
        pixels.resize(xSizePx);
        for(unsigned int i=0; i < xSizePx; i++)
            pixels[i].resize(ySizePx);
    }
}

void Imagen::setPixel(unsigned int x, unsigned int y, const Pixel &dataPixel)
{
    if( (x < xSizePx) && (y < ySizePx))
        pixels[x][y] = dataPixel;

}

Pixel & Imagen::getPixel(unsigned int x, unsigned int y)
{
    /** TODO: no puedo devolver una referencia y pedirle al método que
        me asegure que no estoy modificando nada con const porque es una
        referencia! */
    if( (x < xSizePx) && (y < ySizePx))
        return pixels[x][y];
}

/* ------------------ Sobrecarga de operadores ------------------- */

Pixel & Imagen::operator()(unsigned int x, unsigned int y)
{
    if( (x < xSizePx) && (y < ySizePx))
        return pixels[x][y];

}

//Pixel & Imagen::operator[](unsigned int index)
//{
//    /** problema con la validación de índices*/
//    return pixels[index];
//}
