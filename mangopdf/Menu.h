#ifndef MENU_H
#define MENU_H

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "mangopdf.h"

class WindowInfo;
class mangopdf;

class MMenu : public QObject
{
    Q_OBJECT

public:
    MMenu(WindowInfo * win);
    ~MMenu();

    //�ź�
signals:

    //��
private slots:
    void OpenFileSlot();         //���ļ��ۺ���
    void CloseFileSlot();       //�ر��ļ��ۺ���
    void ExitApp();            //�˳�Ӧ�ó���

public:
    WindowInfo *winInfo;

private:
    void CreateAction();
    void CreateMenu();

private:
    QAction *fileOpenAction;
    QAction *fileCloseAction;
    QAction *exitAction;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *modeMenu;
    QMenu *hlpeMenu;
};

#endif