#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DApplicationSettings>
#include <DTitlebar>
#include <DProgressBar>
#include <DFontSizeManager>
#include <DStandardItem>
#include <QPropertyAnimation>
#include <QDate>
#include <QLayout>
#include <DListView>
#include<QStandardItemModel>
#include"basehasher.h"
#include"mainwindow.h"
DWIDGET_USE_NAMESPACE


int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    DApplication a(argc, argv);
    a.setOrganizationName("deepin");
    a.setApplicationName("dtk-application");
    a.setApplicationVersion("1.0");
    a.setProductIcon(QIcon(":/images/logo.svg"));
    a.setProductName("Dtk Application");
    a.setApplicationDescription("This is a dtk template application.");
    a.loadTranslator();
    a.setApplicationDisplayName(QCoreApplication::translate("Main", "DTK Application"));

    // 保存程序的窗口主题设置
    DApplicationSettings as;
    Q_UNUSED(as)
    MainWindow w;
    /*
    w.titlebar()->setIcon(QIcon(":/images/logo.svg"));
    w.titlebar()->setTitle("Hello dtk");
    // 设置标题，宽度不够会隐藏标题文字
    w.setMinimumSize(QSize(500, 800));
    w.setMaximumSize(QSize(500, 800));

    QWidget *cw = new QWidget(&w);
    QVBoxLayout *layout = new QVBoxLayout(cw);
    QDate today = QDate::currentDate();
    DProgressBar *yearProgressBar = new DProgressBar();
    yearProgressBar->setMaximum(today.daysInYear());
    // 绑定字体大小
    DFontSizeManager::instance()->bind(yearProgressBar, DFontSizeManager::T1);
    DListView *lv = new DListView();
    lv->setEditTriggers(DListView::NoEditTriggers);
    yearProgressBar->setAlignment(Qt::AlignCenter);
    QObject::connect(yearProgressBar, &DProgressBar::valueChanged, yearProgressBar, [yearProgressBar](int value){
        yearProgressBar->setFormat(QString("您的 %1 使用进度： %2%").arg(QDate::currentDate().year())
                                   .arg(value * 100 / yearProgressBar->maximum()));
    });

    layout->addWidget(yearProgressBar);
    layout->addWidget(lv);
    QStandardItemModel *model = new QStandardItemModel();
    lv->setModel(model);
    baseHasher ba;
    QString MD5value =   ba.readFile("",HashType::MD5);
    DStandardItem*item = new DStandardItem ("MD5");
    QString Sha1value = ba.readFile("",HashType::SHA1);
    QString Sha256value = ba.readFile("",HashType::SHA256);
    DViewItemAction * itemaction = new DViewItemAction;
    itemaction->setText("把您的一个屏幕的内容复制到另外一个或多个屏幕");
     itemaction->setFontSize(DFontSizeManager::T8);
     itemaction->setTextColorRole(DPalette::TextTips);
     itemaction->setParent(&w);
     item->setTextActionList({itemaction});
    model->appendRow(item);
    w.setCentralWidget(cw);
    w.show();

    auto animation = new QPropertyAnimation(yearProgressBar, "value");
    animation->setDuration(5000);
    animation->setStartValue(0);
    animation->setEndValue(today.dayOfYear());
    animation->start();
    */
    w.show();
    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
