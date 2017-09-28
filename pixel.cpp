#include "pixel.h"


Pixel::Pixel()
{
    red = 0;
    green = 0;
    blue = 0;
    intesidad = 0;
}

Pixel::Pixel(unsigned short redValue, unsigned short greenValue, unsigned short blueValue)
{
    red = float(redValue)/65536;
    green = float(greenValue)/65536;
    blue = float(blueValue)/65536;
    intesidad = (red+green+blue)/3.0;
}

Pixel::Pixel(float redValue, float greenValue, float blueValue)
{
    red = redValue;
    green = greenValue;
    blue = blueValue;
    intesidad = (red+green+blue)/3.0;

}

float Pixel::calcularIntensidad()
{
    intesidad = (red+green+blue)/3.0;
}

void Pixel::setRed(float value)
{
    red = value;
}

void Pixel::setGreen(float value)
{
    green = value;
}

void Pixel::setBlue(float value)
{
    blue = value;
}

void Pixel::setRGB(float redValue, float greenValue, float blueValue)
{
    red = redValue;
    green = greenValue;
    blue = blueValue;
}

float Pixel::getRed() const
{
    return red;
}

float Pixel::getGreen() const
{
    return green;
}

float Pixel::getBlue() const
{
    return blue;
}

float Pixel::getIntesidad() const
{
    return intesidad;
}

bool Pixel::operator==(Pixel anotherPixel)
{
    bool aux = false;
    float Raux = (this->getRed() - anotherPixel.getRed());
    float Gaux = (this->getGreen() - anotherPixel.getGreen());
    float Baux = (this->getBlue() - anotherPixel.getBlue());

    if( ( Raux <= 0.2501f && Raux >= -0.2501) && ( Gaux <= 0.2501f && Gaux >= -0.2501) && ( Baux <= 0.2501f && Baux >= -0.2501))
        aux = true;

    return aux;
}

void Pixel::operator+(float deltaValue)
{
    red += deltaValue;
    if( red>= 1.0)
        red = 1.0;

    green += deltaValue;
    if( green>= 1.0)
        green = 1.0;

    blue += deltaValue;
    if( blue>= 1.0 )
        blue = 1.0;
}

void Pixel::operator-(float deltaValue)
{
    red -= deltaValue;
    if( red<= 0)
        red = 0;

    green -= deltaValue;
    if( green<= 0)
        green = 0;

    blue -= deltaValue;
    if( blue<= 0)
        blue = 0;
}




