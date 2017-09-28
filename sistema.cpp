#include <iostream>
#include "sistema.h"
#include "pixel.h"
#include "archivador.h"

using namespace std;

Sistema::Sistema()
{

}

void Sistema::printImagenPorConsola(Imagen &img)
{
    for(unsigned int iy=0; iy<img.getYSizePx(); iy++)
    {
        for(unsigned int ix=0; ix<img.getXSizePx(); ix++)
            cout << img(ix,iy).getRed() << " ";
        cout << endl;
    }
    cout << endl;

}

void Sistema::testImagenAndPixel()
{
    Imagen img;
    Pixel pix;

    img.setXSizePx(6);
    img.setYSizePx(10);
    img.resizeImage();

    /** Imagen creada de 6x10 vacía [solo capa de Rojo]*/
    printImagenPorConsola(img);

    pix.setRed(1.0);
    img.setPixel(0,0,pix);
    img.setPixel(0,3,pix);
    img.setPixel(4,6,pix);
    img.setPixel(5,9,pix);

    /** Imagen modificada de 6x10 vacía [solo capa de Rojo]*/
    printImagenPorConsola(img);

}

void Sistema::testArchivos()
{



}
