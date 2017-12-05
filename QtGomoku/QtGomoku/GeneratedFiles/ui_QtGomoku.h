/********************************************************************************
** Form generated from reading UI file 'QtGomoku.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGOMOKU_H
#define UI_QTGOMOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGomokuClass
{
public:
    QAction *action;
    QAction *actionAI;
    QAction *action_2;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralWidget;
    QGraphicsView *BoardView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QListWidget *listWidget_History;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_HumanBlack;
    QLabel *label_4;
    QLabel *label_3;
    QComboBox *comboBox_AiAlgorithm;
    QSlider *horizontalSlider_AiLevel;
    QRadioButton *radioButton_HumanWhite;
    QRadioButton *radioButton_PVE;
    QRadioButton *radioButton_EnableForbidden;
    QRadioButton *radioButton_UnableForbidden;
    QRadioButton *radioButton_SoundOn;
    QRadioButton *radioButton_SoundOff;
    QPushButton *pushButton_NewGame;
    QRadioButton *radioButton_PVP;
    QPushButton *pushButton_Undo;
    QPushButton *pushButton_StopGame;
    QPushButton *pushButton_Help;
    QGroupBox *groupBox_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_BlackOwner;
    QLabel *label_WhiteOwner;
    QMenuBar *menuBar;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGomokuClass)
    {
        if (QtGomokuClass->objectName().isEmpty())
            QtGomokuClass->setObjectName(QStringLiteral("QtGomokuClass"));
        QtGomokuClass->setEnabled(true);
        QtGomokuClass->resize(959, 674);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtGomokuClass->sizePolicy().hasHeightForWidth());
        QtGomokuClass->setSizePolicy(sizePolicy);
        QtGomokuClass->setStyleSheet(QStringLiteral("background-image: url(:/QtGomoku/Resources/bg.png);"));
        action = new QAction(QtGomokuClass);
        action->setObjectName(QStringLiteral("action"));
        actionAI = new QAction(QtGomokuClass);
        actionAI->setObjectName(QStringLiteral("actionAI"));
        actionAI->setCheckable(true);
        action_2 = new QAction(QtGomokuClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_2->setCheckable(true);
        action_4 = new QAction(QtGomokuClass);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_4->setCheckable(true);
        action_5 = new QAction(QtGomokuClass);
        action_5->setObjectName(QStringLiteral("action_5"));
        centralWidget = new QWidget(QtGomokuClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BoardView = new QGraphicsView(centralWidget);
        BoardView->setObjectName(QStringLiteral("BoardView"));
        BoardView->setGeometry(QRect(10, 10, 600, 600));
        sizePolicy.setHeightForWidth(BoardView->sizePolicy().hasHeightForWidth());
        BoardView->setSizePolicy(sizePolicy);
        BoardView->setStyleSheet(QStringLiteral("border-image: url(:/QtGomoku/Resources/board.png);"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(620, 10, 331, 351));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidget_History = new QListWidget(groupBox);
        listWidget_History->setObjectName(QStringLiteral("listWidget_History"));

        gridLayout->addWidget(listWidget_History, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(620, 370, 331, 161));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButton_HumanBlack = new QRadioButton(groupBox_2);
        radioButton_HumanBlack->setObjectName(QStringLiteral("radioButton_HumanBlack"));

        gridLayout_2->addWidget(radioButton_HumanBlack, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        comboBox_AiAlgorithm = new QComboBox(groupBox_2);
        comboBox_AiAlgorithm->setObjectName(QStringLiteral("comboBox_AiAlgorithm"));

        gridLayout_2->addWidget(comboBox_AiAlgorithm, 3, 1, 1, 3);

        horizontalSlider_AiLevel = new QSlider(groupBox_2);
        horizontalSlider_AiLevel->setObjectName(QStringLiteral("horizontalSlider_AiLevel"));
        horizontalSlider_AiLevel->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_AiLevel, 4, 1, 1, 3);

        radioButton_HumanWhite = new QRadioButton(groupBox_2);
        radioButton_HumanWhite->setObjectName(QStringLiteral("radioButton_HumanWhite"));

        gridLayout_2->addWidget(radioButton_HumanWhite, 0, 1, 1, 1);

        radioButton_PVE = new QRadioButton(groupBox_2);
        radioButton_PVE->setObjectName(QStringLiteral("radioButton_PVE"));

        gridLayout_2->addWidget(radioButton_PVE, 1, 2, 1, 1);

        radioButton_EnableForbidden = new QRadioButton(groupBox_2);
        radioButton_EnableForbidden->setObjectName(QStringLiteral("radioButton_EnableForbidden"));

        gridLayout_2->addWidget(radioButton_EnableForbidden, 0, 2, 1, 1);

        radioButton_UnableForbidden = new QRadioButton(groupBox_2);
        radioButton_UnableForbidden->setObjectName(QStringLiteral("radioButton_UnableForbidden"));

        gridLayout_2->addWidget(radioButton_UnableForbidden, 0, 3, 1, 1);

        radioButton_SoundOn = new QRadioButton(groupBox_2);
        radioButton_SoundOn->setObjectName(QStringLiteral("radioButton_SoundOn"));

        gridLayout_2->addWidget(radioButton_SoundOn, 1, 0, 1, 1);

        radioButton_SoundOff = new QRadioButton(groupBox_2);
        radioButton_SoundOff->setObjectName(QStringLiteral("radioButton_SoundOff"));

        gridLayout_2->addWidget(radioButton_SoundOff, 1, 1, 1, 1);

        pushButton_NewGame = new QPushButton(groupBox_2);
        pushButton_NewGame->setObjectName(QStringLiteral("pushButton_NewGame"));

        gridLayout_2->addWidget(pushButton_NewGame, 2, 0, 1, 1);

        radioButton_PVP = new QRadioButton(groupBox_2);
        radioButton_PVP->setObjectName(QStringLiteral("radioButton_PVP"));

        gridLayout_2->addWidget(radioButton_PVP, 1, 3, 1, 1);

        pushButton_Undo = new QPushButton(groupBox_2);
        pushButton_Undo->setObjectName(QStringLiteral("pushButton_Undo"));

        gridLayout_2->addWidget(pushButton_Undo, 2, 1, 1, 1);

        pushButton_StopGame = new QPushButton(groupBox_2);
        pushButton_StopGame->setObjectName(QStringLiteral("pushButton_StopGame"));

        gridLayout_2->addWidget(pushButton_StopGame, 2, 2, 1, 1);

        pushButton_Help = new QPushButton(groupBox_2);
        pushButton_Help->setObjectName(QStringLiteral("pushButton_Help"));

        gridLayout_2->addWidget(pushButton_Help, 2, 3, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(620, 540, 331, 71));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 41, 41));
        label->setStyleSheet(QStringLiteral("background-image: url(:/QtGomoku/Resources/black.png);"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(210, 20, 41, 41));
        label_2->setStyleSheet(QStringLiteral("background-image: url(:/QtGomoku/Resources/white.png);"));
        label_BlackOwner = new QLabel(groupBox_3);
        label_BlackOwner->setObjectName(QStringLiteral("label_BlackOwner"));
        label_BlackOwner->setGeometry(QRect(70, 20, 48, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(18);
        label_BlackOwner->setFont(font);
        label_WhiteOwner = new QLabel(groupBox_3);
        label_WhiteOwner->setObjectName(QStringLiteral("label_WhiteOwner"));
        label_WhiteOwner->setGeometry(QRect(260, 20, 48, 31));
        label_WhiteOwner->setFont(font);
        QtGomokuClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGomokuClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 959, 23));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        QtGomokuClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGomokuClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGomokuClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGomokuClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGomokuClass->setStatusBar(statusBar);

        menuBar->addAction(menu_2->menuAction());
        menu_2->addAction(action);

        retranslateUi(QtGomokuClass);

        QMetaObject::connectSlotsByName(QtGomokuClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGomokuClass)
    {
        QtGomokuClass->setWindowTitle(QApplication::translate("QtGomokuClass", "QtGomoku", Q_NULLPTR));
        action->setText(QApplication::translate("QtGomokuClass", "\345\205\263\344\272\216", Q_NULLPTR));
        actionAI->setText(QApplication::translate("QtGomokuClass", "AI\346\211\247\351\273\221\345\205\210\350\241\214", Q_NULLPTR));
        action_2->setText(QApplication::translate("QtGomokuClass", "\347\216\251\345\256\266\346\211\247\351\273\221\345\205\210\350\241\214", Q_NULLPTR));
        action_4->setText(QApplication::translate("QtGomokuClass", "\350\277\236\347\217\240", Q_NULLPTR));
        action_5->setText(QApplication::translate("QtGomokuClass", "\344\270\211\345\244\247\347\246\201\346\211\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QtGomokuClass", "\350\220\275\345\255\220\350\256\260\345\275\225", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("QtGomokuClass", "\350\256\276\347\275\256", Q_NULLPTR));
        radioButton_HumanBlack->setText(QApplication::translate("QtGomokuClass", "\347\216\251\345\256\266\346\211\247\351\273\221", Q_NULLPTR));
        label_4->setText(QApplication::translate("QtGomokuClass", "AI\347\255\211\347\272\247:", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtGomokuClass", "AI\347\256\227\346\263\225:", Q_NULLPTR));
        radioButton_HumanWhite->setText(QApplication::translate("QtGomokuClass", "\347\216\251\345\256\266\346\211\247\347\231\275", Q_NULLPTR));
        radioButton_PVE->setText(QApplication::translate("QtGomokuClass", "\344\272\272\346\234\272\345\257\271\346\210\230", Q_NULLPTR));
        radioButton_EnableForbidden->setText(QApplication::translate("QtGomokuClass", "\346\234\211\347\246\201\346\211\213", Q_NULLPTR));
        radioButton_UnableForbidden->setText(QApplication::translate("QtGomokuClass", "\346\227\240\347\246\201\346\211\213", Q_NULLPTR));
        radioButton_SoundOn->setText(QApplication::translate("QtGomokuClass", "\346\234\211\345\243\260\351\237\263", Q_NULLPTR));
        radioButton_SoundOff->setText(QApplication::translate("QtGomokuClass", "\346\227\240\345\243\260\351\237\263", Q_NULLPTR));
        pushButton_NewGame->setText(QApplication::translate("QtGomokuClass", "\346\226\260\346\270\270\346\210\217", Q_NULLPTR));
        radioButton_PVP->setText(QApplication::translate("QtGomokuClass", "\344\272\272\344\272\272\345\257\271\346\210\230", Q_NULLPTR));
        pushButton_Undo->setText(QApplication::translate("QtGomokuClass", "\346\202\224\346\243\213", Q_NULLPTR));
        pushButton_StopGame->setText(QApplication::translate("QtGomokuClass", "\347\273\223\346\235\237\346\270\270\346\210\217", Q_NULLPTR));
        pushButton_Help->setText(QApplication::translate("QtGomokuClass", "\345\270\256\345\212\251", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("QtGomokuClass", "\347\216\251\345\256\266\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        label_BlackOwner->setText(QApplication::translate("QtGomokuClass", "\347\216\251\345\256\266", Q_NULLPTR));
        label_WhiteOwner->setText(QApplication::translate("QtGomokuClass", "\347\224\265\350\204\221", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("QtGomokuClass", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGomokuClass: public Ui_QtGomokuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGOMOKU_H
