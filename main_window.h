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
#include <QMessageBox>
#include <QDebug>

#include <string>
#include <vector>
#include <iostream>

#include "Bag.h"
#include "Dictionary.h"
#include "Board.h"
#include "player.h"
#include "mainNext_window.h"
#include <algorithm>

using namespace std;

class MainWindow : public QWidget
{

	Q_OBJECT

public:

	MainWindow(vector<string>x, vector<string>y);
	~MainWindow();

public slots:
	void change(int index); 
	void place();
	void exchange();
	void pass();
	void called();

private:

	QHBoxLayout* mainLayout;
	QGridLayout* g;
	QPushButton*** qboard;

	QVBoxLayout* secondaryLayout;
	QFormLayout* section1;
	QFormLayout* section0;
	QFormLayout* section2;
	QHBoxLayout* section3;
	QLabel* turn;
	QLabel* score;
	QFormLayout* formLayout;

	QLabel* tiles;
	QLineEdit* input;
	QPushButton* placeButton;
	QPushButton* exchangeButton;
	QPushButton* passButton;
	QComboBox* choose;
	QVector<QLabel*>scoreTracker;

	int size;
	vector<string>names;
	vector<string>importantFiles;

	string dictionaryFileName;
	string boardFileName;
	string bagFileName;
	int numTiles;

	Dictionary* dict;
	Bag* bag;
	Board* board;
	vector<Player*>allPlayers;
	MainNext* mainNext;

	int x;
	int y;
	int rows;
	int cols;
	int turnCounter; //determines player order
	int passCounter;
	int trueCounter; //determines overall total turns right now 
	bool firstmove;
	int determine=0;
};