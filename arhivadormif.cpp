#include "arhivadormif.h"
#include <fstream>
#include <cstring>

using std::string;
using std::ifstream;
using std::ios;

ArhivadorMIF::ArhivadorMIF()
{

}

bool ArhivadorMIF::loadImage(std::string nombre, Imagen &img)
{

    bool result = false;
    string relPath = "../svim_lm/imags/";
    string mif = ".mif";

    /** Posición en bytes del comienzo de la lectura de la parte
        binaria del archivo */
    unsigned int offsetBinaryPosition = 0;

    /** path completo del archivo a leer */
    nombre = relPath + nombre;

    /* variables de lectura */
    unsigned int xPxLeido, yPxLeido;
    float xLeido, yLeido;
    string unidadLeida;
    string metadatosLeidos;


    ifstream infile;
    /** Verificación de la extensión del archivo */
    if(strstr(nombre.c_str() , mif.c_str()) !=NULL)
    {
        /** lectura en modo texto plano */
        infile.open(nombre.c_str());

        if(infile.is_open())
        {
            /* Lectura de los parámetros de la imagen */
            infile >> xPxLeido;
            infile.ignore();
            infile >> yPxLeido;
            infile.ignore();
            infile >> xLeido;
            infile.ignore();
            infile >> yLeido;
            infile.ignore();
            getline(infile, unidadLeida);

            /** Lectura de los metadatos -- TBD*/
            getline(infile, metadatosLeidos);
            /** Almacenamiento de la posición del cursor de lectura */
            offsetBinaryPosition = infile.tellg();

            /* Cargado de valores en la imagen */
            img.setXSizePx(xPxLeido);
            img.setYSizePx(yPxLeido);

            img.resizeImage();

            img.setXSize(xLeido);
            img.setYSize(xLeido);
            img.setUnitOfMeasurement(unidadLeida);
            img.setMetadatos(metadatosLeidos);

            infile.close();
        }
        else
        {
            /** Problema al leer el archivo en modo texto */
            result = false;
        }

        /** lectura en modo binario para los valores de RGB */
        infile.open(nombre.c_str(), ios::binary | ios::in);

        if(infile.is_open())
        {
            Pixel pix;
            unsigned short S;

            infile.seekg(offsetBinaryPosition);

            for(unsigned iy=0 ; iy <yPxLeido ; ++iy)
                for(unsigned ix=0 ; ix<xPxLeido ; ++ix)
                {
                    infile.read((char*)&S , sizeof(unsigned short));
                    pix.setRed(S/65535.0f);
                    infile.read((char*)&S , sizeof(unsigned short));
                    pix.setGreen(S/65535.0f);
                    infile.read((char*)&S , sizeof(unsigned short));
                    pix.setBlue(S/65535.0f);

                    img.setPixel(ix,iy,pix);
                }
            infile.close();
        }
        else
        {
            /** Problema al leer el archivo en modo binario */
            result = false;
        }
    }
    else
        /** extensión de archivo incorrecta */
        result = false;

    return result;

}

bool ArhivadorMIF::saveImage(std::string nombre, Imagen &img)
{
    bool result = false;

    return result;
}

ArhivadorMIF::~ArhivadorMIF()
{

}
