#include "filter.h"

Filter::Filter(QWidget *parent) : QDialog(parent)
{

}

void Filter::createButtonBox()
{
    buttonBox= new QDialogButtonBox();


    closeButton = buttonBox->addButton(QDialogButtonBox::Close);
applyButton = buttonBox->addButton(QDialogButtonBox::Apply);
    connect(applyButton, SIGNAL(released()), this, SLOT(applyFilter()));
    connect(closeButton, &QPushButton::clicked, this, &Filter::close);
}

void Filter::createLayout()
{
    createButtonBox();
    createOptionBox();
    layout = new QGridLayout;
    layout->addWidget(optionsBox);
    layout->addWidget(buttonBox);
    setLayout(layout);
    layout->setSizeConstraint(QLayout::SetMinimumSize);

    setWindowTitle(tr("Filter"));
}
