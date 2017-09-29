#include "arhivadormif.h"
#include <fstream>
#include <cstring>
#include "defines.h"

using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::endl;

ArhivadorMIF::ArhivadorMIF()
{
    /** Nothing to do here */
}

bool ArhivadorMIF::loadImage(string nombre, Imagen &img)
{
    /** Resultado de la operación de lectura */
    bool result = false;

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

    ofstream outfile;

    /** path completo del archivo a leer */
    nombre = relPath + nombre;

    /* Escritura de los atributos y metadatos en modo texto */
    outfile.open(nombre.c_str());

    if(outfile.is_open())
    {
        /** Atributos de la imagen */
        outfile << img.getXSizePx() << ";" << img.getYSizePx() << ";" << img.getXSize()
                << ";" << img.getYSize() << ";" << img.getUnitOfMeasurement() << endl;
        /** Metadatos de la imagen */
        outfile << img.getMetadatos() << endl;
        outfile.close();

        /* Escritura de los pixeles en modo binario */
        outfile.open(nombre.c_str(), ios::binary | ios::out | ios::app);

        if(outfile.is_open())
        {
            unsigned short usData;

            for(unsigned iy=0 ; iy<img.getYSizePx() ; ++iy)
                for(unsigned ix=0 ; ix < img.getXSizePx() ; ++ix)
                {
                    usData = img(ix,iy).getRed() * 65535;
                    outfile.write((char*)&usData , sizeof(unsigned short) );

                    usData = img(ix,iy).getGreen() * 65535;
                    outfile.write((char*)&usData , sizeof(unsigned short) );

                    usData = img(ix,iy).getBlue() * 65535;
                    outfile.write((char*)&usData , sizeof(unsigned short) );
                }
            outfile.close();

            /** Se completó con la escritura de atributos, metadatos y valores de pixeles */
            result = true;
        }
        else
        {
            /** Problema al abrir el archivo en modo binario */
            result = false;
        }
    }
    else
    {
        /** Problema al abrir el archivo en modo texto para guardar la imagen */
        result = false;
    }

    return result;
}

ArhivadorMIF::~ArhivadorMIF()
{

}
