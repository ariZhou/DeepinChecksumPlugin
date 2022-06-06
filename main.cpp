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
#include"BaseHasher.h"

#include <QDebug>
DWIDGET_USE_NAMESPACE


int main(int argc, char *argv[])
{
    if (argc  < 2){
        qDebug("未输入文件目标");
        return 0 ;
    }
    char * filepath = argv[1];
    QString path = filepath;
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
    DMainWindow w;
    w.titlebar()->setIcon(QIcon(":/images/logo.svg"));
    w.titlebar()->setTitle("Hash");
    // 设置标题，宽度不够会隐藏标题文字
    w.setMinimumSize(QSize(500, 300));
    w.setMaximumSize(QSize(500, 300));
    QWidget *cw = new QWidget(&w);
    QVBoxLayout *layout = new QVBoxLayout(cw);
    DListView *lv = new DListView();
    layout->addWidget(lv);
    QStandardItemModel *model = new QStandardItemModel();
    lv->setModel(model);
    lv->setEditTriggers(DListView::NoEditTriggers);
    baseHasher ba;
    QString MD5value =   ba.readFile(path,HashType::MD5);
    QString Sha1value = ba.readFile(path,HashType::SHA1);
    QString Sha256value = ba.readFile(path,HashType::SHA256);
    DStandardItem*MD5item = new DStandardItem ("MD5");
    DStandardItem*Sha1item = new DStandardItem("Sha1");
    DStandardItem*Sha256item = new DStandardItem("Sha256");
    DViewItemAction * itemaction = new DViewItemAction;
    itemaction->setText(MD5value);

    itemaction->setFontSize(DFontSizeManager::T8);
    itemaction->setTextColorRole(DPalette::TextTips);
    itemaction->setParent(&w);
    MD5item->setTextActionList({itemaction});
    itemaction = new DViewItemAction;
    itemaction->setText(Sha1value);
    itemaction->setFontSize(DFontSizeManager::T8);
    itemaction->setTextColorRole(DPalette::TextTips);
    itemaction->setParent(&w);
    Sha1item->setTextActionList({itemaction});

    itemaction = new DViewItemAction;
    itemaction->setText(Sha256value);
    itemaction->setFontSize(DFontSizeManager::T8);
    itemaction->setTextColorRole(DPalette::TextTips);
    itemaction->setParent(&w);
    Sha256item->setTextActionList({itemaction});
    model->appendRow(MD5item);
    model->appendRow(Sha1item);
    model->appendRow(Sha256item);
    w.setCentralWidget(cw);
    w.show();
    Dtk::Widget::moveToCenter(&w);
    return  a.exec();
}
