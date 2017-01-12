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

#include <string>
#include <vector>
#include <iostream>

#include "Bag.h"
#include "Dictionary.h"
#include "Board.h"
#include "player.h"
#include <QDebug>

using namespace std;

class MainNext : public QWidget
{

	Q_OBJECT

public:

	MainNext(vector<Player*>& v);
	~MainNext();

public slots: 
	void ok();

protected:

QVBoxLayout* mainLayout;
QFormLayout* scoreBoard;
QFormLayout* winnerBoard;
vector<Player*> allPlayers;
vector<int> maxIndex;
QPushButton* oki;


};