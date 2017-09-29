#include <QApplication>
#include <iostream>
#include <iomanip>
#include "sistema.h"
#include "pixel.h"
#include "arhivadormif.h"
#include "graficador.h"

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
            cout << setprecision(N_DECIMALES)
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

    for(unsigned int iy=0; iy < img.getYSizePx(); ++iy)
        img.setPixel(0,iy,pix);

    archiMif.saveImage(outFileName,img);

    archiMif.loadImage(outFileName,img2);
    printImagenPorConsola(img2);
}

void Sistema::testGraficador(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Imagen img;
    ArhivadorMIF archiMif;
    Graficador graf;

    /** Imagen patrón para el test de Graficación */
    string file = "patt02.mif";

    cout << "Prueba de graficación con OpenGL de una imagen \n";
    archiMif.loadImage(file,img);
    printImagenPorConsola(img);

    graf.resize(800,600);
    graf.graficarImagen(&img);

    graf.show();
    a.exec();

}
