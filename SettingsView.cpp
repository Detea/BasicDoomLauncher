#include "SettingsView.h"
#include <qboxlayout.h>

SettingsView::SettingsView() {
	createUI();
}

SettingsView::~SettingsView() {
	delete dialog;
	dialog = nullptr;
}

void SettingsView::createUI() {
	dialog = new QDialog(nullptr);

	tabWidget = new QTabWidget(dialog);

	tabWidget->addTab(createIWADTab(), "IWAD");
	tabWidget->addTab(createSourcePortTab(), "Source Ports");

	dialog->resize(400, 300);
	dialog->setWindowTitle("Settings");

	QGridLayout* layout = new QGridLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(tabWidget);

	dialog->setLayout(layout);
}

QWidget* SettingsView::createIWADTab() {
	QWidget* iwadWidget = new QWidget;

	lstIWAD = new QListWidget();

	btnAddIWAD = new QPushButton("Add");
	btnAddIWAD->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	btnRemoveIWAD = new QPushButton("Remove");
	btnRemoveIWAD->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	//QHBoxLayout* btnLayout = new QHBoxLayout;
	QVBoxLayout* layout = new QVBoxLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	
	QHBoxLayout* buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(btnAddIWAD);
	buttonLayout->addWidget(btnRemoveIWAD);
	buttonLayout->insertStretch(-1, 100);
	
	layout->addLayout(buttonLayout);
	layout->addWidget(lstIWAD);

	iwadWidget->setLayout(layout);

	return iwadWidget;
}

QWidget* SettingsView::createSourcePortTab() {
	QWidget* tabWidget = new QWidget;

	lstSourcePort = new QListWidget();

	btnAddSourcePort = new QPushButton("Add");
	btnAddSourcePort->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	btnRemoveSourcePort = new QPushButton("Remove");
	btnRemoveSourcePort->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	QVBoxLayout* layout = new QVBoxLayout;
	layout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout* buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(btnAddSourcePort);
	buttonLayout->addWidget(btnRemoveSourcePort);
	buttonLayout->insertStretch(-1, 100);

	layout->addLayout(buttonLayout);
	layout->addWidget(lstSourcePort);

	tabWidget->setLayout(layout);

	return tabWidget;
}

QPushButton* SettingsView::getIWADAddButton() const {
	return btnAddIWAD;
}

QPushButton* SettingsView::getIWADRemoveButton() const {
	return btnRemoveIWAD;
}

QListWidget* SettingsView::getIWADList() const {
	return lstIWAD;
}

QListWidget* SettingsView::getSourcePortList() const {
	return lstSourcePort;
}

QPushButton* SettingsView::getAddSourcePortButton() const {
	return btnAddSourcePort;
}

QPushButton* SettingsView::getRemoveSourcePortButton() const {
	return btnRemoveSourcePort;
}

QDialog* SettingsView::getDialog() const {
	return dialog;
}