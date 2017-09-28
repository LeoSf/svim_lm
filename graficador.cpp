#include "graficador.h"

Graficador::Graficador(QWidget* parent) : QOpenGLWidget(parent)
{

}

void Graficador::graficarImagen(Imagen *im)
{
    img = im;
}


void Graficador::initializeGL()
{
//    initializeOpenGLFunctions();
    /** Definición del color de fondo para la limpieza de pantalla */
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void Graficador::resizeGL(int ancho, int alto)
{
    glViewport(0, 0, ancho, alto);  // Se define el viewport para que se utilice todo el espacio de la ventana
    glMatrixMode(GL_PROJECTION);    // Cambiamos al modo proyección para definirla
    glLoadIdentity();               // Se borran todas las matrices anteriores
    glOrtho(0, width(), 0, height(), -1, 1);
    glMatrixMode(GL_MODELVIEW);     // Se vuelve al modo modelview para que sea utilizado en el dibujo
    glLoadIdentity();               // Se borran odas las matrices anteriores
}

void Graficador::paintGL()
{
    escala = 1.0f;
    offsetX = 0.0f;
    offsetY = 0.0f;

    /** Limpiar la pantalla */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /** Dimensiones relativas para mantener la relación de aspecto */
    float relAncho = ((float)width())  / ((float) img->getXSizePx());
    float relAlto  = ((float)height()) / ((float) img->getYSizePx());

    if(relAncho < relAlto)
    {
        escala = relAncho;
        offsetY = (height() - img->getYSizePx()*escala)*0.5f;
    }
    else
    {
        escala = relAlto;
        offsetX = (width() - img->getXSizePx()*escala)*0.5f;
    }

    paintImage();

}

void Graficador::paintImage()
{
    glPushMatrix();                         // Iniciar un bloque(matriz) aislado para las transformaciones

    glTranslatef(offsetX, offsetY, 0.0f); // Desplaza la imagen al centro de la ventana
    glScalef(escala, escala, 1.0f);     // Escalar que mantenga sus proporciones al tamaño de ventana actual

    glBegin(GL_QUADS);                  // Cuadrados para los pixeles, se modifican de tamaño al cambiar el tamaño de la ventana.

    Pixel pix;

    for(unsigned iy=0; iy < img->getYSizePx() ; ++iy)
        for(unsigned ix=0; ix < img->getXSizePx() ; ++ix)
        {
            pix = (*img).getPixel(ix,iy);
            float R = pix.getRed();
            float G = pix.getGreen();
            float B = pix.getBlue();

            glColor3f( R, G, B );

            glVertex3f(ix, img->getYSizePx()-iy, 0);
            glVertex3f(ix, img->getYSizePx()-(iy+1), 0);
            glVertex3f(ix+1, img->getYSizePx()-(iy+1), 0);
            glVertex3f(ix+1, img->getYSizePx()-iy, 0);
        }

    glEnd();

    /** Finaliza el bloque de transformaciones */
    glPopMatrix();

}




