#ifndef MAINVIEW_H_
#define MAINVIEW_H_
#include <qtoolbar.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qlistwidget.h>
#include <qaction.h>


class MainView {
public:
	MainView();

	void createUI();

	QWidget* getWidget();

	QToolBar* getToolBar();

	QAction* getPlayAction();
	QAction* getAddWADAction();
	QAction* getRemoveWADAction();

	QPushButton* getSettingsButton();

	QComboBox* getIWADComboBox();
	QComboBox* getSourcePortComboBox();

	QListWidget* getListWidget();
private:
	void createActions();
	void createToolBar();

private:
	QWidget* widget = nullptr;

	QToolBar* toolbar = nullptr;
	QAction* playAction = nullptr;
	QAction* addWADAction = nullptr;
	QAction* removeWADAction = nullptr;

	QComboBox* cbIWAD = nullptr;
	QComboBox* cbSourcePort = nullptr;
	QPushButton* btnSettings = nullptr;

	QListWidget* listWidget = nullptr;
};


#endif