#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent ):DMainWindow (parent)
{
    this->titlebar()->setIcon(QIcon(":/images/logo.svg"));
    this->titlebar()->setTitle("Hello dtk");
    // 设置标题，宽度不够会隐藏标题文字
    this->setMinimumSize(QSize(500, 800));
    this->setMaximumSize(QSize(500, 800));
    cw = new QWidget(this);
    layout = new QVBoxLayout(cw);
    QDate today = QDate::currentDate();
    yearProgressBar = new DProgressBar();
    yearProgressBar->setMaximum(today.daysInYear());
    DFontSizeManager::instance()->bind(yearProgressBar, DFontSizeManager::T1);

    yearProgressBar->setAlignment(Qt::AlignCenter);
    QObject::connect(yearProgressBar, &DProgressBar::valueChanged, yearProgressBar, [this](int value){
        yearProgressBar->setFormat(QString("您的 %1 使用进度： %2%").arg(QDate::currentDate().year())
                                   .arg(value * 100 / yearProgressBar->maximum()));
    });

    layout->addWidget(yearProgressBar);

    auto animation = new QPropertyAnimation(yearProgressBar, "value");
    animation->setDuration(5000);
    animation->setStartValue(0);
    animation->setEndValue(today.dayOfYear());
    animation->start();
}
MainWindow::~MainWindow(){

}
