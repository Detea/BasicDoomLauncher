#include "MainWidget.h"
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qfile.h>
#include <qdatastream.h>

#include <qdebug.h>

MainWidget::MainWidget() {
	mainView.createUI();

	connect(mainView.getPlayAction(), &QAction::triggered, this, &MainWidget::playWAD);
	connect(mainView.getAddWADAction(), &QAction::triggered, this, &MainWidget::addWAD);
	connect(mainView.getRemoveWADAction(), &QAction::triggered, this, &MainWidget::removeWAD);
	connect(mainView.getSettingsButton(), &QPushButton::clicked, this, &MainWidget::showSettings);
	connect(&settingsWidget, &SettingsWidget::closed, this, &MainWidget::updateLists);

	process = new QProcess(this);
}

QWidget* MainWidget::getView() {
	return mainView.getWidget();
}

void MainWidget::playWAD() {
	int indexIWAD = mainView.getIWADComboBox()->currentIndex();
	QString strIWAD = strListIWAD[indexIWAD];
	
	int indexSourcePort = mainView.getSourcePortComboBox()->currentIndex();
	QString strSourcePort = strListSourcePorts[indexSourcePort];

	QStringList PWADS;
	for (int i = 0; i < mainView.getListWidget()->count(); i++) {
		PWADS << mainView.getListWidget()->item(i)->text();
	}

	QStringList args;
	args << "-iwad";
	args << strIWAD;
	args << "-file";
	args << PWADS;

	process->setProgram(strSourcePort);
	process->setArguments(args);

	process->start();
}

void MainWidget::addWAD() {
	QStringList fileNames = QFileDialog::getOpenFileNames(mainView.getWidget(), "Add a PWAD file...", "", "WAD File (*.wad *.WAD)");

	mainView.getListWidget()->addItems(fileNames);
}

void MainWidget::removeWAD() {
	int selection = mainView.getListWidget()->currentRow();

	if (selection != -1) {
		QListWidgetItem* item = mainView.getListWidget()->takeItem(selection);

		delete item;
	}
}

void MainWidget::showSettings() {
	settingsWidget.show();
}

void MainWidget::updateLists() {
	updateComboBox(mainView.getIWADComboBox(), settingsWidget.getView().getIWADList());
	updateComboBox(mainView.getSourcePortComboBox(), settingsWidget.getView().getSourcePortList());

	strListIWAD.clear();
	strListSourcePorts.clear();

	updateStringList(settingsWidget.getView().getIWADList(), strListIWAD);
	updateStringList(settingsWidget.getView().getSourcePortList(), strListSourcePorts);
}

void MainWidget::updateComboBox(QComboBox* comboBox, QListWidget* listWidget) {
	comboBox->clear();

	for (int i = 0; i < listWidget->count(); i++) {
		updateComboBox(comboBox, listWidget->item(i)->text());
	}
}

void MainWidget::updateStringList(QListWidget* listWidget, QStringList& strList) {
	for (int i = 0; i < listWidget->count(); i++) {
		strList << listWidget->item(i)->text();
	}
}

void MainWidget::updateComboBox(QComboBox* comboBox, QStringList stringList) {
	for (QString& s : stringList) {
		updateComboBox(comboBox, s);
	}
}

void MainWidget::updateComboBox(QComboBox* combobox, QString string) {
	QString s = string.split("/").last();

	combobox->addItem(s);
}

void MainWidget::loadData() {
	QFile file("bdl.dat");
	file.open(QIODevice::ReadOnly);

	int indexIWAD = 0;
	int indexSourcePort = 0;
	QDataStream in(&file);
	in >> indexIWAD;
	in >> indexSourcePort;

	in >> strListIWAD;
	in >> strListSourcePorts;

	int PWADCount = 0;
	in >> PWADCount;

	for (int i = 0; i < PWADCount; i++) {
		QString str;

		in >> str;

		mainView.getListWidget()->addItem(str);
	}

	settingsWidget.getView().getIWADList()->addItems(strListIWAD);
	settingsWidget.getView().getSourcePortList()->addItems(strListSourcePorts);

	updateComboBox(mainView.getIWADComboBox(), strListIWAD);
	updateComboBox(mainView.getSourcePortComboBox(), strListSourcePorts);

	mainView.getIWADComboBox()->setCurrentIndex(indexIWAD);
	mainView.getSourcePortComboBox()->setCurrentIndex(indexSourcePort);
}

void MainWidget::saveData() {
	QFile file("bdl.dat");
	bool open = file.open(QIODevice::WriteOnly);

	QDataStream out(&file);
	out << mainView.getIWADComboBox()->currentIndex();			// Currently selected IWAD
	out << mainView.getSourcePortComboBox()->currentIndex();	// Currently selected Source Port
	
	out << strListIWAD;
	out << strListSourcePorts;

	out << mainView.getListWidget()->count();
	for (int i = 0; i < mainView.getListWidget()->count(); i++) {
		out << mainView.getListWidget()->item(i)->text();
	}
}