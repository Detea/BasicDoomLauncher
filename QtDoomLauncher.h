#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtDoomLauncher.h"

#include "MainWidget.h"

class QtDoomLauncher : public QMainWindow
{
    Q_OBJECT

public:
    QtDoomLauncher(QWidget *parent = nullptr);
    ~QtDoomLauncher();
    
    void showEvent(QShowEvent* e);
    void closeEvent(QCloseEvent* e);

private:
    MainWidget mainWidget;
};
