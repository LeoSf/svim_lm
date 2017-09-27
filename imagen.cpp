#include "imagen.h"
#include "pixel.h"

Imagen::Imagen()
{

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

void Imagen::setPixel(unsigned int x, unsigned int y, const Pixel &dataPixel)
{

}

Pixel & Imagen::getPixel(unsigned int x, unsigned int y) const
{

}

/* ------------------ Sobrecarga de operadores ------------------- */

Pixel & Imagen::operator()(unsigned int x, unsigned int y)
{

}

Pixel & Imagen::operator[](unsigned int index)
{

}
