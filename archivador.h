#ifndef ARCHIVADOR_H
#define ARCHIVADOR_H

#include <string>
#include "imagen.h"

using std::string;

/*!
 * \brief Clase abstracta para manejar archivos
 */
class Archivador
{
public:
    /**
     * @brief Constructor vacío
     */
    Archivador();

    /**
     * @brief método virtual para cargar una imagen desde un archivo
     * @param nombre: nombre del archivo ej: "imgagen.ext"
     * @param img: referencia a una imagen a cargar
     * @return resultado de la lectura del archivo. True = éxito
     */
    virtual bool loadImage(string nombre, Imagen & img)=0;

    /**
     * @brief método virtual para guardar una imagen en un archivo
     * @param nombre: nombre del archivo ej: "imgagen.ext"
     * @param img: referencia a una imagen precargada en memoria
     * @return resultado de guardar en un archivo. True = éxito
     */
    virtual bool saveImage(string nombre, Imagen & img)=0;

    ~Archivador();

};

#endif // ARCHIVADOR_H
