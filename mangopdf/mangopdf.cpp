#include "mangopdf.h"

mangopdf::mangopdf(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    win = new WindowInfo();
    win->mango = this;
    //�����ʼ��
    WindowInit(win);
}

mangopdf::~mangopdf()
{
}

void mangopdf::WindowInit(WindowInfo *win)
{
    //�����˵���
    win->hwndMenu = new MMenu(win);
    this->resize(900, 600);
}
