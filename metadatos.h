#ifndef METADATOS_H
#define METADATOS_H

#include <map>
#include <string>
#include <vector>

using std::map;
using std::string;
using std::vector;

/*!
 * \brief The Metadatos class
 * Clase que contiene los metadatos leídos desde un archivo de imagen.
 * A su vez, provee de métodos para inserción de nuevos metadatos y la
 * búsqueda de los mismos por su código correspondiente.
 */
class Metadatos
{
private:
    /*!
     * \brief contenedor
     */
    map<string, string> contenedor;
public:
    /*!
     * \brief Constructor vacío
     */
    Metadatos();
    /*!
     * \brief Cosntructor con vectores de códigos y valores
     * Este constructor recibe punteros a dos vectores de índices
     * correlativos, en los cuales uno corresponde a los códigos,
     * mientras que el otro posee los valores asociados. Este
     * constructor previene el almacenamiento de códigos duplicados.
     * \param codes: vector de códigos
     * \param values: vector de valores asociados
     */
    Metadatos(const vector<string> * codes, const vector<string> values);

    /* Métodos públicos */
    /*!
     * \brief Método para agregar un metadato al contenedor
     * \param code: código del metadato (este debe ser único)
     * \param value: valor asociado al código
     * \return true: si el metadato puedo ser agregado exitosamente al
     * contenedor. false: en caso de que el código ya exista.
     */
    bool addMetadato(const string * code, const string * value);
    /*!
     * \brief Método para obtener un metadato por el código asociado
     * \param code: código del metadato
     * \return valor del metadato asociado al código solicitado. Null
     * en caso de que el código no exista.
     */
    string getMetadatoByCode(string code);
    /*!
     * \brief Método para obtener todos los códigos y valores de los
     * metadatos asociados.
     * \return String con una sucesión de metadatos ordenados por
     * código y valor, con formato: code1:value1;code2:value2;...
     */
    string getCodesAndValues();
};

#endif // METADATOS_H
