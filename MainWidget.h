#pragma once
#include <qobject.h>
#include <qstring.h>
#include <qstringlist.h>
#include <qprocess.h>

#include "MainView.h"

#include "SettingsWidget.h"

class MainWidget : public QObject {
	Q_OBJECT

public:
	MainWidget();
	
	QWidget* getView();

	void loadData();
	void saveData();
private slots:
	void playWAD();
	
	void addWAD();
	void removeWAD();

	void showSettings();

	void updateLists();

private:
	void updateComboBox(QComboBox* comboBox, QListWidget* listWidget);
	void updateStringList(QListWidget* listWidget, QStringList& strList);

	void updateComboBox(QComboBox* comboBox, QString string);
	void updateComboBox(QComboBox* comboBox, QStringList stringList);
private:
	MainView mainView;

	SettingsWidget settingsWidget;

	QStringList strListIWAD;
	QStringList strListSourcePorts;

	QProcess* process = nullptr;
};

