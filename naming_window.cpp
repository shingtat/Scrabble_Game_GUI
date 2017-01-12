#include "naming_window.h"

using namespace std;

NamingWindow::NamingWindow(int x, vector<string>y): players(x), files(y){

	mainLayout = new QVBoxLayout;
	mainLayout->addWidget(new QLabel("Please enter the names of each player"));
	formLayout = new QFormLayout;
	// QVBoxLayout* formLayout = new QVBoxLayout;

	for(int i=1; i<=x; i++){
		//QHBoxLayout* playerName = new QHBoxLayout;		
		QString playerNumber;
		playerNumber.setNum(i);
		QLabel* first = new QLabel("Player "+playerNumber+" ");
		QLineEdit* name = new QLineEdit(" ");
		information.push_back(name);
		formLayout->addRow(first,name);
		// playerName->addWidget(new QLabel("Player "+playerNumber+" "));
		// playerName->addWidget(new QLineEdit(" "));
		// formLayout->addLayout(playerName);

	}

	mainLayout->addLayout(formLayout);

	doneButton = new QPushButton("&Done");
	connect(doneButton,SIGNAL(clicked()),this,SLOT(done()));

	mainLayout->addWidget(doneButton);

	setLayout(mainLayout);
}

NamingWindow::~NamingWindow(){

	delete mainLayout;

}

void NamingWindow::done(){
	// QList<QLineEdit*> list = formLayout->findChildren<QLineEdit*>();
	// for(QList<QLineEdit*>::iterator it = list.begin(); it!=list.end(); ++it){
	// 	cout<<(*it)->text().toStdString()<<endl;
	// 	//qDebug()<<(*it)->text();
	// }

	for(unsigned int i =0; i<information.size(); i++){
		string name = information[i]->text().toStdString();
		names.push_back(name);
	}

	mainWindow = new MainWindow(names, files);
	close();
	mainWindow->show();	

}