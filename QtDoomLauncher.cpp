#include "QtDoomLauncher.h"
#include <qboxlayout.h>

QtDoomLauncher::QtDoomLauncher(QWidget *parent) : QMainWindow(parent) {
    setCentralWidget(mainWidget.getView());

    resize(600, 800);

    setWindowTitle("Barebones Doom Launcher");
}

QtDoomLauncher::~QtDoomLauncher()
{}

void QtDoomLauncher::showEvent(QShowEvent* e) {
    mainWidget.loadData();
}

void QtDoomLauncher::closeEvent(QCloseEvent* e) {
    mainWidget.saveData();
}