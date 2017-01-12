#include <QWidget>
#include <QObject>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QImage>
#include <QSpinBox>

#include <string>
#include <vector>
#include <iostream>

#include "naming_window.h"


class StartingWindow : public QWidget
{

	Q_OBJECT

public:
	StartingWindow(vector<string>x);
	~StartingWindow();
	vector<string>importantFiles;


public slots:
	void getPlayers();
	void quit();

private:

	QVBoxLayout *mainLayout;
	QApplication *app;
	QPushButton *confirmButton, *quitButton;
	QLineEdit *name;
	QSpinBox *number;
	NamingWindow* namingWindow;


};