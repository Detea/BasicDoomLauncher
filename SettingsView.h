#pragma once
#include <qwidget.h>
#include <qtabwidget.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qboxlayout.h>

#include <qstringlistmodel.h>
#include <qdialog.h>

class SettingsView {
public:
	SettingsView();
	~SettingsView();

	QListWidget* getIWADList() const;
	QListWidget* getSourcePortList() const;

	QPushButton* getIWADAddButton() const;
	QPushButton* getIWADRemoveButton() const;

	QPushButton* getAddSourcePortButton() const;
	QPushButton* getRemoveSourcePortButton() const;

	QDialog* getDialog() const;
private:
	void createUI();

	QWidget* createIWADTab();
	QWidget* createSourcePortTab();

private:
	QDialog* dialog = nullptr;

	QTabWidget* tabWidget = nullptr;

	QListWidget* lstIWAD = nullptr;
	QListWidget* lstSourcePort = nullptr;

	QPushButton* btnAddIWAD = nullptr;
	QPushButton* btnRemoveIWAD = nullptr;

	QPushButton* btnAddSourcePort = nullptr;
	QPushButton* btnRemoveSourcePort = nullptr;
};

