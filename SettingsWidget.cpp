#include "SettingsWidget.h"
#include <qfiledialog.h>
#include <qmessagebox.h>

SettingsWidget::SettingsWidget() {
	connect(view.getIWADAddButton(), &QPushButton::clicked, this, &SettingsWidget::addIWAD);
	connect(view.getIWADRemoveButton(), &QPushButton::clicked, this, &SettingsWidget::removeIWAD);

	connect(view.getAddSourcePortButton(), &QPushButton::clicked, this, &SettingsWidget::addSourcePort);
	connect(view.getRemoveSourcePortButton(), &QPushButton::clicked, this, &SettingsWidget::removeSourcePort);
}

void SettingsWidget::show() {
	int res = view.getDialog()->exec();

	// We only care about the dialog closing, not the result
	if (res == QDialog::Rejected) {
		emit closed();
	}
}

void SettingsWidget::addIWAD() {
	QStringList fileNames = QFileDialog::getOpenFileNames(view.getDialog(), "Add IWAD file...", "", "IWAD File (*.wad *.WAD)");

	view.getIWADList()->addItems(fileNames);
}

void SettingsWidget::removeIWAD() {
	removeItem(view.getIWADList());
}

void SettingsWidget::addSourcePort() {
	QStringList fileNames = QFileDialog::getOpenFileNames(view.getDialog(), "Add a source port...", "", "Windows executable (*.exe *.EXE)");

	view.getSourcePortList()->addItems(fileNames);
}

void SettingsWidget::removeSourcePort() {
	removeItem(view.getSourcePortList());
}

void SettingsWidget::removeItem(QListWidget* list) {
	int selection = list->currentRow();

	if (selection != -1) {
		QListWidgetItem* item = list->takeItem(selection);

		delete item;
	}
}

SettingsView& SettingsWidget::getView() {
	return view;
}
