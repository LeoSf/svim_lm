#include <iostream>
#include "sistema.h"
#include "pixel.h"
#include "arhivadormif.h"

using namespace std;

const unsigned int N_DECIMALES = 2;

Sistema::Sistema()
{

}

void Sistema::printImagenPorConsola(Imagen &img)
{
    cout << "Filas: " << img.getYSizePx() << endl;
    cout << "Columnas: " << img.getXSizePx() << endl;
    cout << "Metadata: " << img.getMetadatos() << endl;

    for(unsigned int iy=0; iy<img.getYSizePx(); iy++)
    {
        for(unsigned int ix=0; ix<img.getXSizePx(); ix++)
            cout << std::setprecision(N_DECIMALES)
                 << img(ix,iy).getRed() << " ";
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

void Sistema::testArchivador()
{
    string inFileName = "patt01.mif";
    string outFileName = "patt01-mod.mif";

    Imagen img, img2;
    Pixel pix;
    ArhivadorMIF archiMif;

    cout << "Prueba de la lectura de una imagen \n";
    archiMif.loadImage(inFileName,img);
    printImagenPorConsola(img);

    img.setPixel(0,0,pix);
    img.setPixel(0,1,pix);
    img.setPixel(0,2,pix);
    img.setPixel(0,3,pix);
    archiMif.saveImage(outFileName,img);

    archiMif.loadImage(outFileName,img2);
    printImagenPorConsola(img2);
}
