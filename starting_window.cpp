#include "starting_window.h"

using namespace std;

StartingWindow::StartingWindow(vector<string>x){

	importantFiles = x;
	mainLayout = new QVBoxLayout;
	mainLayout->addWidget(new QLabel("Welcome to CSCI104 Scrabble!"));
	mainLayout->addWidget(new QLabel("Number of Players "));
	number = new QSpinBox;
	number->setMinimum(1);
	number->setMaximum(10);
	number->setValue(1);
	number->setSingleStep(1);
	mainLayout->addWidget(number);

	QHBoxLayout* buttonLayout = new QHBoxLayout;
	quitButton = new QPushButton("&Quit");
	confirmButton = new QPushButton("&Confirm");
	buttonLayout->addWidget(confirmButton);
	buttonLayout->addWidget(quitButton);
	mainLayout->addLayout(buttonLayout);
	connect(confirmButton, SIGNAL(clicked()), this, SLOT(getPlayers()));
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));



	setLayout(mainLayout);

}

StartingWindow::~StartingWindow(){

	delete mainLayout;

}

void StartingWindow::getPlayers(){
	int numPlayers = number->value();
	namingWindow = new NamingWindow(numPlayers, importantFiles);
	close();
	namingWindow->show();	
}

void StartingWindow::quit(){
	cout<<"Good Bye!"<<endl;
	close();
}