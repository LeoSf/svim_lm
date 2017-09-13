#include "pixel.h"


Pixel::Pixel()
{

}

Pixel::Pixel(unsigned short redValue, unsigned short greenValue, unsigned short blueValue)
{

}

Pixel::Pixel(float redValue, float greenValue, float blueValue)
{

}

float Pixel::calcularIntensidad()
{

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

}

void Pixel::operator+(float deltaValue)
{

}

void Pixel::operator-(float deltaValue)
{

}




