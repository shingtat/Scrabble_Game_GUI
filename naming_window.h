#include <QWidget>
#include <QObject>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>

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
#include <sstream>
#include <QVector>

#include "main_window.h"

using namespace std;

class NamingWindow : public QWidget
{

	Q_OBJECT

public:
	NamingWindow(int x, vector<string>y);
	~NamingWindow();
	vector<string>names;
	vector<string>files;

public slots:
	void done();

private:
	int players;
	QVBoxLayout* mainLayout;
	QFormLayout* formLayout;	
	QPushButton *doneButton;
	QLineEdit *name;
	QVector<QLineEdit*>information;
	MainWindow* mainWindow;

};