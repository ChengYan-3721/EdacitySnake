/********************************************************************************
** Form generated from reading UI file 'windowoJYeXF.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINDOWOJYEXF_H
#define WINDOWOJYEXF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *menu;
    QHBoxLayout *horizontalLayout;
    QLabel *score_label;
    QLabel *score;
    QSpacerItem *horizontalSpacer;
    QLabel *speed_label;
    QSpinBox *speed;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *set;
    QPushButton *pause;
    QPushButton *restart;
    QGraphicsView *view;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->setWindowModality(Qt::NonModal);
        Form->resize(500, 550);
        Form->setMinimumSize(QSize(500, 550));
        Form->setFocusPolicy(Qt::StrongFocus);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        menu = new QFrame(Form);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setMinimumSize(QSize(500, 50));
        menu->setFrameShape(QFrame::StyledPanel);
        menu->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(menu);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        score_label = new QLabel(menu);
        score_label->setObjectName(QString::fromUtf8("score_label"));
        score_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(score_label);

        score = new QLabel(menu);
        score->setObjectName(QString::fromUtf8("score"));

        horizontalLayout->addWidget(score);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        speed_label = new QLabel(menu);
        speed_label->setObjectName(QString::fromUtf8("speed_label"));
        speed_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(speed_label);

        speed = new QSpinBox(menu);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setFocusPolicy(Qt::ClickFocus);
        speed->setMinimum(1);
        speed->setMaximum(10);
        speed->setValue(1);

        horizontalLayout->addWidget(speed);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        set = new QPushButton(menu);
        set->setObjectName(QString::fromUtf8("set"));
        set->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(set);

        pause = new QPushButton(menu);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pause);

        restart = new QPushButton(menu);
        restart->setObjectName(QString::fromUtf8("restart"));
        restart->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(restart);


        verticalLayout->addWidget(menu);

        view = new QGraphicsView(Form);
        view->setObjectName(QString::fromUtf8("view"));
        view->setMinimumSize(QSize(500, 500));
        view->setFocusPolicy(Qt::NoFocus);
        QBrush brush(QColor(0, 0, 0, 180));
        brush.setStyle(Qt::SolidPattern);
        view->setBackgroundBrush(brush);

        verticalLayout->addWidget(view);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "\344\272\214\347\273\264\350\264\252\345\220\203\350\233\207", nullptr));
        score_label->setText(QCoreApplication::translate("Form", "\345\275\223\345\211\215\345\210\206\346\225\260", nullptr));
        score->setText(QCoreApplication::translate("Form", "0", nullptr));
        speed_label->setText(QCoreApplication::translate("Form", "\346\270\270\346\210\217\351\200\237\345\272\246", nullptr));
        set->setText(QCoreApplication::translate("Form", "\350\256\276\347\275\256", nullptr));
        pause->setText(QCoreApplication::translate("Form", "\346\232\202\345\201\234", nullptr));
        restart->setText(QCoreApplication::translate("Form", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WINDOWOJYEXF_H
