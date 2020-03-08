#include "filter.h"

/**
 * @brief Filter::Filter a constructor.
 * @param parent
 */
Filter::Filter(QWidget *parent) : QDialog(parent)
{

}

/**
 * @brief Filter::createButtonBox
 *
 * Create button box with close and apply button. Subscribe signals.
 */
void Filter::createButtonBox()
{
    buttonBox= new QDialogButtonBox();


    closeButton = buttonBox->addButton(QDialogButtonBox::Close);
applyButton = buttonBox->addButton(QDialogButtonBox::Apply);
    connect(applyButton, SIGNAL(released()), this, SLOT(applyFilter()));
    connect(closeButton, &QPushButton::clicked, this, &Filter::close);
}

/**
 * @brief Filter::createLayout
 *
 *  Create layout with options box and buttons box. Set size. Set title.
 */
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
