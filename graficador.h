#ifndef GRAFICADOR_H
#define GRAFICADOR_H

#include <QOpenGLWidget>
#include "imagen.h"

class Graficador : public QOpenGLWidget
{
private:
    Imagen * img;

    float escala;

    float offsetX;
    float offsetY;

    void paintImage();

protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void    resizeGL(int ancho, int alto);

public:
    Graficador(QWidget * parent = 0);
    void graficarImagen(Imagen *im);
};

#endif // GRAFICADOR_H
