#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    initializeGL();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initializeGL()
{
    setSurfaceType(QWindow::OpenGLSurface);
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2, 1);
    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);
    openGLFuncitons = context->functions();
}

void MainWindow::resizeGL()
{

}

void MainWindow::paintGL()
{
    glClearColor(1.0, 0.0f, 0.0f, 0.0f); //设置颜色
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS); //画矩形
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);

    glEnd();

    glFlush(); //刷新缓冲区
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL(); //调用
}

