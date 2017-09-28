#ifndef IMAGEN_H
#define IMAGEN_H

#include <vector>
#include <string>
#include "pixel.h"
#include "metadatos.h"

using std::vector;
using std::string;

/*!
 * \brief Clase que modela una imagen
 * Esta clase modela toda la información contenida en un archivo de
 * imagen. Por lo tanto contendrá los atributos de la misma (resolución
 * en x, resolución en y, ancho, alto y dimensión física), los
 * metadatos y una matriz correspondiente a los pixeles.
 */
class Imagen
{
private:
    /* Atributos de la imagen */
    /*! Cantidad de píxeles en el eje X de la imagen */
    unsigned int xSizePx;
    /*! Cantidad de píxeles en el eje Y de la imagen */
    unsigned int ySizePx;
    /*! Dimensión física de la imagen en X */
    unsigned int xSize;
    /*! Dimensión física de la imagen en Y */
    unsigned int ySize;
    /*! Unidad físca de medida empleada para medir la imagen */
    string unitOfMeasurement;

    /* Metadatos de la imagen -- implementación báscia -- */
    string metadatos;

    /* pixeles de la imagen en formato mxn */
    vector<vector<Pixel>> pixels;

public:
    /*! Constructor vacío de la clase Imagen */
    Imagen();

    /* Setters */
    void setXSizePx(unsigned int value);
    void setYSizePx(unsigned int value);
    void setXSize(unsigned int value);
    void setYSize(unsigned int value);
    void setMetadatos(const string &value);
    void setUnitOfMeasurement(const string &value);

    /* Getters */
    unsigned int getXSizePx() const;
    unsigned int getYSizePx() const;
    unsigned int getXSize() const;
    unsigned int getYSize() const;
    string getMetadatos() const;
    string getUnitOfMeasurement() const;

    /* Public methods to manipulate an image */
    /**
     * @brief Método para redimensionar la imagen en función de los valores de
     * xSizePx y ySizePx que determinarán las dimensiones de la matriz de pixeles.
     */
    void resizeImage();

    /*!
     * \brief Método para setear un valor de un pixel en la imagen
     * \param x: coordenada en x [px]
     * \param y: coordenada en y [px]
     * \param dataPixel: objeto tipo Pixel con la información a guardar
     */
    void setPixel(unsigned int x, unsigned int y, const Pixel &dataPixel);
    /*!
     * \brief getPixel
     * \param x: coordenada en x [px]
     * \param y: coordenada en y [px]
     * \return referencia a un objeto tipo Pixel de la imagen.
     */
    Pixel & getPixel(unsigned int x, unsigned int y);

    /* Sobrecarga de operadores */
    /*!
     * \brief operator () para acceder a un pixel mediante sus
     * coordenadas x e y, y a su vez modificarlo. Esto permitiría
     * modificar el brillo de un pixel como:
     * imagen(x,y) = imagen(x,y)+1; si la suma estaría definida.
     * \param x: coordenada en x [px]
     * \param y: coordenada en y [px]
     * \return referencia al pixel.
     */
    Pixel & operator()(unsigned int x, unsigned int y);
    /*!
     * \brief operator [] para acceder a un pixel mediante sus
     * coordenadas x e y, y a su vez modificarlo. Esto permitiría
     * modificar el brillo de un pixel como:
     * imagen[x][y] = imagen[x][y]+1; si la suma estaría definida.
     * \param index
     * \return referencia al pixel.
     */
//    Pixel & operator[](unsigned int index);




};

#endif // IMAGEN_H
