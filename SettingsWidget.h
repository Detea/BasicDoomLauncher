#pragma once
#include <qobject.h>
#include <qtabwidget.h>
#include <qstring.h>

#include "SettingsView.h"

class SettingsWidget : public QObject {
	Q_OBJECT

public:
	SettingsWidget();

	void show();

	SettingsView& getView();
signals:
	void closed();

private:
	void removeItem(QListWidget* list);

private slots:
	void addIWAD();
	void removeIWAD();

	void addSourcePort();
	void removeSourcePort();


private:
	SettingsView view;

};

