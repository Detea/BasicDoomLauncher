#include "MainView.h"
#include <qboxlayout.h>
#include <qlabel.h>

#include "MainWidget.h"

MainView::MainView() {
	
}

void MainView::createActions() {
	playAction = new QAction("Play", widget);
	addWADAction = new QAction("Add WAD", widget);
	removeWADAction = new QAction("Remove WAD", widget);
}

void MainView::createToolBar() {
	toolbar = new QToolBar(widget);

	toolbar->addAction(playAction);
	toolbar->addAction(addWADAction);
	toolbar->addAction(removeWADAction);

	QWidget* empty = new QWidget(toolbar);
	empty->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	toolbar->addWidget(empty);

	toolbar->addSeparator();

	QLabel* lblIWAD = new QLabel("IWAD:");
	toolbar->addWidget(lblIWAD);

	cbIWAD = new QComboBox(toolbar);
	cbIWAD->setMinimumWidth(100);
	toolbar->addWidget(cbIWAD);

	toolbar->addSeparator();

	QLabel* lblSourcePort = new QLabel("Source Port:");
	toolbar->addWidget(lblSourcePort);

	cbSourcePort = new QComboBox(toolbar);
	cbSourcePort->setMinimumWidth(100);
	toolbar->addWidget(cbSourcePort);

	toolbar->addSeparator();

	btnSettings = new QPushButton("Settings", toolbar);
	toolbar->addWidget(btnSettings);
}

void MainView::createUI() {
	widget = new QWidget;

	createActions();
	createToolBar();

	listWidget = new QListWidget(widget);

	auto vbox = new QVBoxLayout(widget);
	vbox->setSpacing(0);
	vbox->setContentsMargins(0, 0, 0, 0);

	vbox->addWidget(toolbar);
	vbox->addWidget(listWidget);
}

QToolBar* MainView::getToolBar() {
	return toolbar;
}

QAction* MainView::getPlayAction() {
	return playAction;
}

QAction* MainView::getAddWADAction() {
	return addWADAction;
}

QAction* MainView::getRemoveWADAction() {
	return removeWADAction;
}

QWidget* MainView::getWidget() {
	return widget;
}

QPushButton* MainView::getSettingsButton() {
	return btnSettings;
}

QComboBox* MainView::getIWADComboBox() {
	return cbIWAD;
}

QComboBox* MainView::getSourcePortComboBox() {
	return cbSourcePort;
}

QListWidget* MainView::getListWidget() {
	return listWidget;
}