#include "mainNext_window.h"



MainNext::MainNext(vector<Player*>& v){

	allPlayers=v;
	mainLayout = new QVBoxLayout;
	QLabel* final = new QLabel(QString::fromStdString("Final Score Report"));
	final->setStyleSheet("text-decoration: underline;");
	mainLayout -> addWidget(final);

	int max =0;
	int index =0;
	for(int i=0; i<allPlayers.size(); i++){
		int score = allPlayers[i]->getScore();
		if(score>=max){
			max = score;
			index = i;
		}
	}

	for(int i =0; i<allPlayers.size(); i++){
			if(i==index || allPlayers[i]->getScore()==max){
				continue;
			}
		set<Tile*>temp = allPlayers[i]->getTiles();
		int score = allPlayers[i]->getScore();
		for(set<Tile*>::iterator it2 = temp.begin(); it2!=temp.end(); ++it2){
			int subtract = (*it2)->getPoints();
			score = score - subtract;
		}
		 allPlayers[i]->setScore(score);
	}

	scoreBoard = new QFormLayout;
	for(int i=0; i<allPlayers.size(); i++){
		QLabel* name = new QLabel(QString::fromStdString(allPlayers[i]->getName())+": ");
		QLabel* score = new QLabel(QString::number(allPlayers[i]->getScore()));
		scoreBoard->addRow(name,score);
	}

	// QLabel* winner = new QLabel(QString::fromStdString("Winner/s"));
	// winner->setStyleSheet("text-decoration: underline;");
	// winnerBoard->addWidget(winner);
	// for(int i =0; i<allPlayers.size(); i++){
	// 		if(i==index || allPlayers[i]->getScore()==max){
	// 		QLabel* what = new QLabel(QString::fromStdString(allPlayers[i]->getName())+": ");
	// 		QLabel* omg = new QLabel(QString::number(allPlayers[i]->getScore()));
	// 		winnerBoard->addRow(what,omg);
	// 		}
	// }		

	oki = new QPushButton("&Ok");
	connect(oki, SIGNAL(clicked()), this, SLOT(ok()));
	mainLayout->addLayout(scoreBoard);
	//mainLayout->addLayout(winnerBoard);
	mainLayout->addWidget(oki);

	//mainLayout->addWidget(winner);
	//mainLayout->addLayout(winnerBoard);
	setLayout(mainLayout);


}

MainNext::~MainNext(){
	delete mainLayout;

}

void MainNext::ok(){
	close();
}