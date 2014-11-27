#include "Menu.h"
#include <QFileDialog>


MMenu::MMenu(WindowInfo *win) : winInfo(win)
{
    CreateAction();
    CreateMenu();
}

MMenu::~MMenu()
{
}

void MMenu::CreateAction()
{
    //�������ļ�����
    fileOpenAction = new QAction(QIcon::fromTheme("���ļ�", QIcon(":/menu/Resources/Open.png")), QStringLiteral("&���ļ�..."), winInfo->mango);
    fileOpenAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));  //���ô��ļ������Ŀ�ݼ�
    fileOpenAction->setStatusTip(QStringLiteral("��һ���ļ�"));   //���ô��ļ���������ʾ��Ϣ
    connect(fileOpenAction, SIGNAL(triggered()), this, SLOT(OpenFileSlot()));//�������ļ��������źźͲ�
    //�ر��ļ�
    fileCloseAction = new QAction(QIcon::fromTheme("�ر��ļ�", QIcon(":/res/Close.png")), QStringLiteral("&�ر��ļ�..."), winInfo->mango);
    fileCloseAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));
    fileCloseAction->setStatusTip(QStringLiteral("�ر�һ���ļ�"));
    connect(fileCloseAction, SIGNAL(triggered()), this, SLOT(CloseFileSlot()));
    //�˳�
    exitAction = new QAction(QIcon::fromTheme("�˳�", QIcon(":/menu/Resources/Exit.png")), QStringLiteral("&�˳�..."), winInfo->mango);
    exitAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
    exitAction->setStatusTip(QStringLiteral("�˳�"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(CloseFileSlot()));
}

void MMenu::CreateMenu()
{
    fileMenu = winInfo->mango->menuBar()->addMenu(QStringLiteral("�ļ�"));
    fileMenu->addAction(fileOpenAction);
    fileMenu->addAction(fileCloseAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    editMenu = winInfo->mango->menuBar()->addMenu(QStringLiteral("�༭"));
}

void MMenu::OpenFileSlot()
{
    winInfo->filePath = QFileDialog::getOpenFileName(winInfo->mango, QStringLiteral("Open File..."),
                        QString(), QStringLiteral("pdf Files (*.pdf *.xps);;All Files (*)"));
}

void MMenu::CloseFileSlot()
{
}

void MMenu::ExitApp()
{
}

