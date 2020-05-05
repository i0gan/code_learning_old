#include "smaliwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
SmaliWidget::SmaliWidget(QWidget *parent) : QWidget(parent)
{

    QSpinBox *spin = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal, this);

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(spin);
    hLayout->addWidget(slider);

    //As the slider slides, the balue of the other control changes
    connect(spin,static_cast<void (QSpinBox::*) (int)>(&QSpinBox::valueChanged), slider, &QSlider::setValue);
    connect(slider, &QSlider::valueChanged, spin, &QSpinBox::setValue);
}

