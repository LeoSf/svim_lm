#ifndef PIXEL_H
#define PIXEL_H

/*!
 * \brief Clase para modelar la información contenida en un pixel
 */
class Pixel
{
private:
    /* Atributos privados */
    float red;
    float green;
    float blue;
    float intesidad;

    /* Métodos privados */
    /*!
     * \brief Cálculo de la intensidad del pixel
     * La intensidad de un pixel es calculada como el promedio de los
     * valores RGB.
     * \return valor de pto flotante de la intensidad
     */
    float calcularIntensidad();

public:
    /*!
     * \brief Cosntructor por defecto
     * Inicialización de todos los parámetros a cero.
     */
    Pixel();
    /*!
     * \brief Constructor para raw data de 16 bits
     * \param valor de rojo entre [0,16535]
     * \param valor de rojo entre [0,16535]
     * \param valor de rojo entre [0,16535]
     */
    Pixel(unsigned short redValue, unsigned short greenValue, unsigned short blueValue);
    /*!
     * \brief Constructor para valores de punto flotante
     * \param valor de rojo entre [0,1]
     * \param valor de rojo entre [0,1]
     * \param valor de rojo entre [0,1]
     */
    Pixel(float redValue, float greenValue, float blueValue);

    /* Métodos setters */
    /*!
     * \brief Ajuste del valor de Rojo
     * \param valor de punto flotante para el Rojo entre [0,1]
     */
    void setRed(float value);
    /*!
     * \brief Ajuste del valor de Verde
     * \param valor de punto flotante para el Verde entre [0,1]
     */
    void setGreen(float value);
    /*!
     * \brief Ajuste del valor de Azul
     * \param valuvalor de punto flotante para el Azul entre [0,1]
     */
    void setBlue(float value);

    /*!
     * \brief Ajuste del valor de Rojo, Verde y Azul
     * \param valores de punto flotante entre [0,1]
     */
    void setRGB(float redValue, float greenValue, float blueValue);

    /* Métodos getters */
    /*!
     * \brief Función para devolver el valor de Rojo
     * \return valor de Rojo en punto flotante entre [0,1]
     */
    float getRed() const;
    /*!
     * \brief Función para devolver el valor de Verde
     * \return valor de Verde en punto flotante entre [0,1]
     */
    float getGreen() const;
    /*!
     * \brief Función para devolver el valor de Azul
     * \return valor de Azul en punto flotante entre [0,1]
     */
    float getBlue() const;
    /*!
     * \brief Función para devolver el valor de intesidad del pixel.
     * La intensidad de un pixel es calculada como el promedio de los
     * valores RGB.
     * \return valor de intensidad del pixel [0,1]
     */
    float getIntesidad() const;

    /* Métodos públicos de cálculo */
    /*!
     * \brief Operador == para comparar la intensidad de dos pixeles
     * \param otro Pixel
     * \return true si ambos pixeles poseen la misma intensidad.
     */
    bool operator==(Pixel anotherPixel);
    /*!
     * \brief Sobrecarga del operatorador + para el incremento del
     * brillo.
     * El incremento del brillo se traduce un un incremento en los
     * valores de RGB del pixel.
     * \param Valor del delta a incrementar.
     */
    Pixel operator+(float deltaValue);
    /*!
     * \brief Sobrecarga del operatorador - para la reducción del
     * brillo.
     * La reducción del brillo se traduce un un decremento en los
     * valores de RGB del pixel.
     * \param Valor del delta a decrementar.
     */
    Pixel operator-(float deltaValue);


};

#endif // PIXEL_H
