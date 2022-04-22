#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include   <DMainWindow>
#include <DTitlebar>
#include <QLayout>
#include<QDate>
#include<DProgressBar>
#include<DFontSizeManager>
#include<DListView>
#include<QStandardItemModel>
#include<QPropertyAnimation>
DWIDGET_USE_NAMESPACE
class MainWindow:public DMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QWidget*cw;
    DProgressBar *yearProgressBar;
    QVBoxLayout *layout;
    DListView*lv;
    QStandardItemModel *model;
    };

#endif // MAINWINDOW_H
