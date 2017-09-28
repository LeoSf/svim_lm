#ifndef ARHIVADORMIF_H
#define ARHIVADORMIF_H

#include "archivador.h"

/*!
 * \brief Clase para manejar archivos tipo MIF
 */
class ArhivadorMIF : public Archivador
{
private:

public:
    /**
     * @brief Constructor vacío
     */
    ArhivadorMIF();

    /**
     * @brief método para cargar una imagen desde un archivo .MIF
     * @param nombre: nombre del archivo ej: "imgagen.mif"
     * @param img: referencia a una imagen a cargar
     * @return resultado de la lectura del archivo. True = éxito
     */
    bool loadImage(string nombre, Imagen & img);

    /**
     * @brief método para guardar una imagen en un archivo .MIF
     * @param nombre: nombre del archivo ej: "imgagen.mif"
     * @param img: referencia a una imagen precargada en memoria
     * @return resultado de guardar en un archivo. True = éxito
     */
    bool saveImage(string nombre, Imagen & img);

    ~ArhivadorMIF();
};

#endif // ARHIVADORMIF_H
