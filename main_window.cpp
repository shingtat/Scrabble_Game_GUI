#include "main_window.h"

using namespace std;

void createBoard(QPushButton***& qboard, QGridLayout*& g, Board*& board){
	int rows = board->_x;
	int cols = board->_y;

	g = new QGridLayout;
	qboard = new QPushButton**[rows];
	for(int i=0; i<rows; i++){
		qboard[i] = new QPushButton*[cols];
	}

	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			qboard[i][j] = new QPushButton;
			//QObject::connect(qboard[i][j], SIGNAL(clicked()), this, SLOT(called()));
			qboard[i][j]->setFixedSize(30,30);
			qboard[i][j]->setEnabled(false);
			if(board->getBoard()[i][j]->getString()=="*** "){
				QString text = QString::fromStdString("S");
				qboard[i][j]->setText(text);
				qboard[i][j]->setStyleSheet("background-color: yellow;");
			}
			else if(board->getBoard()[i][j]->getString()=="2L  "){
				QString text = QString::fromStdString("2L");
				qboard[i][j]->setText(text);
				qboard[i][j]->setStyleSheet("background-color: green;" "color: white;");

			}

			else if(board->getBoard()[i][j]->getString()=="3L  "){
				QString text = QString::fromStdString("3L");
				qboard[i][j]->setText(text);
				qboard[i][j]->setStyleSheet("background-color: blue;""color: white;");

			}

			else if(board->getBoard()[i][j]->getString()=="2W  "){
				QString text = QString::fromStdString("2W");
				qboard[i][j]->setText(text);
				qboard[i][j]->setStyleSheet("background-color: red;""color: white;");

			}

			else if(board->getBoard()[i][j]->getString()=="3W  "){
				QString text = QString::fromStdString("3W");
				qboard[i][j]->setText(text);
				qboard[i][j]->setStyleSheet("background-color: purple;""color: white;");

			}													
			g->addWidget(qboard[i][j], i, j); //BECAREFUL IT IS i+1 and j+1 here, becareful of placement and accessing grid positions			
		}
	}

}

void updateBoard(QPushButton***& qboard, Board*& board){
	int rows = board->_x;
	int cols = board->_y;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			string update = board->getBoard()[i][j]->getString();
			if(update!="... " && board->getBoard()[i][j]->isOccupied()==true){
			qboard[i][j]->setText(QString::fromStdString(update));
			qboard[i][j]->setStyleSheet("background-color: gray;" "color: white;");
			}
		}
	}
}

QFormLayout* printUserTiles(vector<Player*>& allplayers, int index, QLabel*& turn, QLabel*& tiles){

	QFormLayout* overall = new QFormLayout;
	turn = new QLabel(QString::fromStdString("It is "+allplayers[index]->getName()+"'s turn!"));
	turn->setStyleSheet("QLabel { text-decoration: underline; font-weight: bold; }");	
	QLabel* temp = new QLabel(QString::fromStdString("Your Tiles: "));
	set<Tile*>p1tiles = allplayers[index]->getTiles();
	string s =" ";
	 for(set<Tile*>::iterator it = p1tiles.begin(); it!= p1tiles.end(); ++it){

	 	s+=(*it)->getLetter();
	 	string num = to_string((*it)->getPoints());
	 	s+=num;
	 	s+=" ";
	 }
	 
	tiles = new QLabel(QString::fromStdString(s));
	overall->addRow(turn);
	overall->addRow(temp);
	overall->addRow(tiles);

	return overall;	
}

void updateUserTiles(vector<Player*>& allplayers, int index, QLabel*& turn, QLabel*& tiles){

	turn->setText(QString::fromStdString("It is "+allplayers[index]->getName()+"'s turn!"));
	set<Tile*>p1tiles = allplayers[index]->getTiles();
	string s =" ";
	 for(set<Tile*>::iterator it = p1tiles.begin(); it!= p1tiles.end(); ++it){

	 	s+=(*it)->getLetter();
	 	string num = to_string((*it)->getPoints());
	 	s+=num;
	 	s+=" ";
	 }
	tiles->setText(QString::fromStdString(s));
}

QFormLayout* printScoreBoard(vector<Player*>& allPlayers){

	QFormLayout* formLayout = new QFormLayout;	
	QLabel* scores = new QLabel("Scores");
	formLayout->addRow(scores);
	for(int i=0; i<allPlayers.size(); i++){
		QLabel* name = new QLabel(QString::fromStdString(allPlayers[i]->getName())+" ");
		QLabel* score = new QLabel(QString::number(allPlayers[i]->getScore()));
		formLayout->addRow(name,score);
	}

	return formLayout;

}

void updateScoreBoard(QVector<QLabel*>&x, int index, vector<Player*>& allPlayers){
	int z = allPlayers[index]->getScore();
	string s = to_string(z);
	x[index]->setText(QString::fromStdString(s));

}

bool checkMatch(set<Tile*> p1tiles, vector<char> storage){

	vector<int>confirm;
	for(vector<char>::iterator it2 = storage.begin(); it2!=storage.end(); ++it2){ //HAND TILES
		for(set<Tile*>::iterator it = p1tiles.begin(); it!= p1tiles.end(); ++it){
			if((*it2)==(*it)->getLetter() && (*it2=='?')){
				confirm.push_back(1);
				confirm.push_back(1);
				p1tiles.erase(it);
				p1tiles.erase(++it);
				break;
			}

			else if((*it2)==(*it)->getLetter()){
				confirm.push_back(1);
				p1tiles.erase(it);
				break;
			}
		}
	}

	if(confirm.size()==storage.size()){
		return true;
	}
	else{
		return false;
	}

}

bool isValidHorizontal(Board* board, Dictionary* dict){
	cout<<endl;
	//cout<<"isVALIDHORIZONTAL CALLED: "<<endl;
	Square*** copy = board->getBoard();
	vector<string>storage;
	vector<bool>checking;
	string a;
	for(int i=0; i<board->_x; i++){
		for(int j=0; j<board->_y; j++){
			if(copy[i][j]->getTile()!=NULL){
				if(copy[i][j]->getTile()->getLetter()!=' '){
					a+=copy[i][j]->getTile()->getLetter();
					int counter=1;
					while(copy[i][j+counter]->getTile()!=NULL){
						//cout << copy[i][j+counter]->getTile()->getLetter() << " " << counter << endl;
						a+=copy[i][j+counter]->getTile()->getLetter();
						counter++;
						if(j+counter == board->_y) break;
					}//while loop if

				} //first if 
				j+=a.length()-1;

				if(a.length()>1){
				storage.push_back(a);
				}
				a="";			
				
			}//if for Tile not being NULL
		}//j forloop
	}// i forloop

	for(vector<string>::iterator it = storage.begin(); it!=storage.end(); ++it){

		//cout<<"STORAGE: "<<(*it)<<endl;
		string temp = *it;
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if(dict->checkWord(temp)==true){
			checking.push_back(true);
		}
	}

	if(storage.size()==checking.size()){
		return true;
	}

	else{
		return false;
	}

}

bool isValidVertical(Board* board, Dictionary* dict){
	cout<<endl;
	//cout<<"isVALIDVERTICAL CALLED: "<<endl;
	Square*** copy = board->getBoard();
	vector<string>storage;
	vector<bool>checking;
	string a;
	for(int i=0; i<board->_x; i++){
		for(int j=0; j<board->_y; j++){
			if(copy[i][j]->getTile()!=NULL){
				if(copy[i][j]->getTile()->getLetter()!=' '){
					a+=copy[i][j]->getTile()->getLetter();
					int counter=1;
					while(copy[i+counter][j]->getTile()!=NULL){
						a+=copy[i+counter][j]->getTile()->getLetter();
						counter++;
						if(i+counter==board->_x){
							break;
						}
					}//while loop if

				} //first if 				
				//cout<<"A IS: "<<a<<endl;
				i+=a.length()-1;

				if(a.length()>1){
				storage.push_back(a);
				}
				a="";			
				
			}//if for Tile not being NULL
		}//j forloop
	}// i forloop

	for(vector<string>::iterator it = storage.begin(); it!=storage.end(); ++it){

		//cout<<"STORAGE: "<<(*it)<<endl;
		string temp = *it;
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if(dict->checkWord(temp)==true){
			checking.push_back(true);
		}
	}

	if(storage.size()==checking.size()){
		return true;
	}
	else{
		return false;
	}

}

void reset(multimap<int,int>& prevlocation1, vector<string>& prevstring, Board*& board){

	int stringcounter = 0;
	for(multimap<int,int>::iterator it = prevlocation1.begin(); it!=prevlocation1.end(); ++it){
		int x = it->first;
		int y = it->second;
		board->getBoard()[x][y]->setTileNull();
		board->getBoard()[x][y]->setString(prevstring[stringcounter]);
		stringcounter++;		
	}
}

void resetOriginalCondition(multimap<int,int>& prevlocation1, vector<string>& prevstring, Board*& board, set<Tile*>& p1tiles, set<Tile*>& tilesdeleted){

	reset(prevlocation1, prevstring, board);
	
	for(set<Tile*>::iterator it= tilesdeleted.begin(); it!=tilesdeleted.end(); ++it){ //replace lost tiles 
		p1tiles.insert(*it);
	}

}

string replaceTilesNew(set<Tile*>& addBack, int addback, set<Tile*>& p1tiles, Bag*& bag){
	string s = "";
	addBack = bag->drawTiles(addback);
	for(set<Tile*>::iterator it = addBack.begin(); it!=addBack.end(); ++it){
		p1tiles.insert(*it);
		s.push_back((*it)->getLetter());
		s+=to_string((*it)->getPoints());
		s+=" ";
	}
}

int countNeighborHorizontal(multimap<int,int> prevlocation1, Board* board, vector<char>& storage){

		int neighborcounter=0;

		int index = 0;

		for(multimap<int,int>::iterator it = prevlocation1.begin(); it!=prevlocation1.end(); ++it){

		if(it==prevlocation1.begin()){
			int x = it->first;
			int y = it->second;
			if(board->getBoard()[x-1][y]->isOccupied()==true || board->getBoard()[x][y-1]->isOccupied()==true || board->getBoard()[x+1][y]->isOccupied()==true){
				neighborcounter++; //check NWS
			}

			for(unsigned int i =0; i<storage.size(); i++){
				if(storage[i]==board->getBoard()[x][y]->getTile()->getLetter()){
					index = i;
					break;
				}
			}

			if(storage.size()==1){
				if(board->getBoard()[x][y+1]->isOccupied()==true){
					neighborcounter++;
					}			
			}

			else{
				if(board->getBoard()[x][y+1]->getTile()->getLetter()!=storage[index+1]) {
					if(board->getBoard()[x][y+1]->isOccupied()==true){
						neighborcounter++;
						index=0;
					}
				}
			}


		}

		else if(it==prevlocation1.end()){
			int x = it->first;
			int y = it->second;
			if(board->getBoard()[x-1][y]->isOccupied()==true || board->getBoard()[x][y+1]->isOccupied()==true || board->getBoard()[x+1][y]->isOccupied()==true){
				neighborcounter++; //check NES
			}

		}

		else{
			int x = it->first;
			int y = it->second;
			if(board->getBoard()[x-1][y]->isOccupied()==true || board->getBoard()[x+1][y]->isOccupied()==true){
				neighborcounter++; //check NS
			}										
		}

	}

	return neighborcounter;
}

int countNeighborVertical(multimap<int,int> prevlocation1, Board* board, vector<char>& storage){
		int neighborcounter=0;

		int index = 0;

		for(multimap<int,int>::iterator it = prevlocation1.begin(); it!=prevlocation1.end(); ++it){

		if(it==prevlocation1.begin()){
			int x = it->first;
			int y = it->second;
			if(board->getBoard()[x-1][y]->isOccupied()==true || board->getBoard()[x][y-1]->isOccupied()==true || board->getBoard()[x][y+1]->isOccupied()==true){
				neighborcounter++; //check NWE, first tile placed
			}

			for(unsigned int i =0; i<storage.size(); i++){
				if(storage[i]==board->getBoard()[x][y]->getTile()->getLetter()){
					index = i;
					break;
				}
			}

			if(storage.size()==1){
				if(board->getBoard()[x+1][y]->isOccupied()==true){
					neighborcounter++;
					}	//accounting for single letter placements that are still valid		
			}

			else{
				if(board->getBoard()[x+1][y]->getTile()->getLetter()!=storage[index+1]) { //accounting for next tile after first. Only count it was previously occupied
					if(board->getBoard()[x+1][y]->isOccupied()==true){
						neighborcounter++;
						index=0;
					}
				}
			}


		}

		else if(it==prevlocation1.end()){
			int x = it->first;
			int y = it->second;
			if(board->getBoard()[x][y-1]->isOccupied()==true || board->getBoard()[x][y+1]->isOccupied()==true || board->getBoard()[x+1][y]->isOccupied()==true){
				neighborcounter++; //check WES
			}

		}

		else{
			int x = it->first;
			int y = it->second;
			if(board->getBoard()[x][y-1]->isOccupied()==true || board->getBoard()[x][y+1]->isOccupied()==true){
				neighborcounter++; //check WE
			}										
		}

	}

	return neighborcounter;
}

MainWindow::MainWindow(vector<string>x, vector<string>y){

	names = x;
	importantFiles = y;
	turnCounter=0;
	passCounter=0;
	trueCounter=0;
	firstmove=true;

	dictionaryFileName = importantFiles[0];
	boardFileName = importantFiles[1];
	bagFileName = importantFiles [2];
	numTiles = atoi(importantFiles[3].c_str());

	dict = new Dictionary(dictionaryFileName);
	board = new Board(boardFileName);
	bag = new Bag(bagFileName,794);

	for(int i=0; i<names.size(); i++){
		string name = names[i];
		Player *p = new Player();
		p->setName(name);

		set<Tile*>temp = bag->drawTiles(numTiles);
		p->setTiles(temp);	
		allPlayers.push_back(p);	
	}


	mainLayout = new QHBoxLayout;
	rows = board->_x;
	cols = board->_y;

	g = new QGridLayout;
	qboard = new QPushButton**[rows];
	for(int i=0; i<rows; i++){
		qboard[i] = new QPushButton*[cols];
	}

	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			qboard[i][j] = new QPushButton;
			QObject::connect(qboard[i][j], SIGNAL(clicked()), this, SLOT(called()));
			qboard[i][j]->setFixedSize(30,30);
			if(board->getBoard()[i][j]->getString()=="*** "){
				QString text = QString::fromStdString("S");
				qboard[i][j]->setText(text);
				qboard[i][j]->setStyleSheet("background-color: yellow;");
			}
			else if(board->getBoard()[i][j]->getString()=="2L  "){
				QString text = QString::fromStdString("2L");
				qboard[i][j]->setText(text);
				qboard[i][j]->setStyleSheet("background-color: green;" "color: white;");

			}

			else if(board->getBoard()[i][j]->getString()=="3L  "){
				QString text = QString::fromStdString("3L");
				qboard[i][j]->setText(text);
				qboard[i][j]->setStyleSheet("background-color: blue;""color: white;");

			}

			else if(board->getBoard()[i][j]->getString()=="2W  "){
				QString text = QString::fromStdString("2W");
				qboard[i][j]->setText(text);
				qboard[i][j]->setStyleSheet("background-color: red;""color: white;");

			}

			else if(board->getBoard()[i][j]->getString()=="3W  "){
				QString text = QString::fromStdString("3W");
				qboard[i][j]->setText(text);
				qboard[i][j]->setStyleSheet("background-color: purple;""color: white;");

			}													
			g->addWidget(qboard[i][j], i, j); //BECAREFUL IT IS i+1 and j+1 here, becareful of placement and accessing grid positions			
		}
	}
	//createBoard(qboard, g, board);
	mainLayout->addLayout(g);

	secondaryLayout = new QVBoxLayout;

	section1 = new QFormLayout;
	QLabel* scores = new QLabel("Scores");
	scores->setStyleSheet("QLabel { text-decoration: underline; font-weight: bold; }");	
	section1->addRow(scores);
	for(int i=0; i<allPlayers.size(); i++){
		QLabel* name = new QLabel(QString::fromStdString(allPlayers[i]->getName())+" ");
		QLabel* score = new QLabel(QString::number(allPlayers[i]->getScore()));
		scoreTracker.push_back(score);
		section1->addRow(name,score);
	}
	secondaryLayout->addLayout(section1);

	section0= new QFormLayout;
	QLabel* instruction = new QLabel("Instructions:");
	instruction->setStyleSheet("QLabel { text-decoration: underline; font-weight: bold; }");
	section0->addRow(instruction);
	section0->addRow(new QLabel("1. For placing, please click on a square, select horizontal or vertical placement, \n    input tiles then click the place button."));
	section0->addRow(new QLabel("\n2. For exchanging, please input the tiles you want to exchange,\n     then press the exchange button."));
	secondaryLayout->addLayout(section0);

	section2 = new QFormLayout;
	section2 = printUserTiles(allPlayers,0,turn,tiles);
	input = new QLineEdit("");
	section2->addRow(input);
	secondaryLayout->addLayout(section2);

	section3 = new QHBoxLayout;
	placeButton = new QPushButton("Place");
	exchangeButton = new QPushButton("Exchange");
	passButton = new QPushButton("Pass");
	choose = new QComboBox;
	choose->addItem("Horizontal");
	choose->addItem("Vertical");
	section3->addWidget(choose);
	section3->addWidget(placeButton);
	section3->addWidget(exchangeButton);
	section3->addWidget(passButton);

	connect(choose, SIGNAL(currentIndexChanged(int)), this, SLOT(change(int)));
	connect(placeButton, SIGNAL(clicked()), this, SLOT(place()));
	connect(exchangeButton, SIGNAL(clicked()), this, SLOT(exchange()));
	connect(passButton, SIGNAL(clicked()), this, SLOT(pass()));

	secondaryLayout->addLayout(section3);

	mainLayout->addLayout(secondaryLayout);
	setLayout(mainLayout);

	if(passCounter==allPlayers.size()){
		mainNext = new MainNext(allPlayers);
		close();
		mainNext->show();
	}
}

MainWindow::~MainWindow(){
	delete dict;
	delete board;
	delete bag;

	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			delete qboard[i][j];
		}
		delete [] qboard[i];
	}
	delete [] qboard;
	delete mainLayout;

	for(int i=0; i<allPlayers.size(); i++){
		delete allPlayers[i];

	}


}

void MainWindow::change(int index){
	switch (index){
		case 0:
		determine=0;
		break;

		case 1:
		determine=1;
		break;
	}

}

void MainWindow::called(){
	int rows = board->_x;
	int cols = board->_y;

	QPushButton *called = (QPushButton*) QObject::sender();
	int i=0, j=0;
	for(int x =0; x<rows; x++){
		for(int y =0; y<cols; y++){
			qboard[x][y]->setDown(false);
			if(qboard[x][y]==called){
				i=x;
				j=y;
			}
		}
	}

	x=i;
	y=j;
	qboard[x][y]->setDown(true);
	//qboard[x][y]->setStyleSheet("border: 1px solid black;");
	//setStyleSheet("border: 1px solid black;");

	//qDebug()<<"xy "<<x<<y<<endl;
}

void MainWindow::place(){

	vector<char>storage;
	int ycounter=0;
	int xcounter=0;
	int addback=0;
	int score=0;
	int prevScore=allPlayers[turnCounter]->getScore();
	vector<int>multipliers;

	set<Tile*>p1tiles = allPlayers[turnCounter]->getTiles();
	multimap<int,int>prevlocation1;
	vector<string>prevstring;	
	set<Tile*>addBack;
	set<Tile*>tilesdeleted;
	string boo;


	if(input->text().isEmpty()){
		return;
	}
	//qDebug()<<x<<y<<endl;
	string input3 = input->text().toStdString();
	transform(input3.begin(), input3.end(), input3.begin(), ::toupper);

	//qDebug()<<"board y "<<board->_y<<endl;

if(determine==0){

	if(input3.length()+y>board->_y || y-input3.length()<0){ //invalid length placement
		QMessageBox msgBox;
		msgBox.setText("Invalid Location!");
		msgBox.exec();
		input->setText("");		
		return;
	}

	if(board->getBoard()[x][y]->isOccupied()==true){ //invalid, trying to place on something that is already there
		QMessageBox msgBox;
		msgBox.setText("Square is already occupied!");
		msgBox.exec();	
		return;
	}

	for(unsigned int i=0; i<input3.length(); i++){
		storage.push_back(input3[i]);
	}

	//ACTUAL IMPLEMENTATION
	if(checkMatch(p1tiles,storage)==true){ //checks whether tiles are in hand
		for(vector<char>::iterator it=storage.begin(); it!=storage.end(); ++it){
			for(set<Tile*>::iterator it2=p1tiles.begin(); it2!=p1tiles.end(); ++it2){
				if((*it2)->getLetter()==(*it)){	

					p1tiles.erase(it2);
					addback++; //
					Square* specific = (board->getBoard())[x][y+ycounter]; //gets specific board
					string s;
					s.push_back(*it);
					s+="   ";
					string num = to_string((*it2)->getPoints());
					s+=num;
					tilesdeleted.insert(*it2);

					if(specific->isOccupied()==false){ //if there is a tile

					int charScore=(*it2)->getPoints();
					//qDebug()<<charScore<<endl;
					if(specific->getString()=="2L  "){
						charScore = 2*charScore;
						score+=charScore;
					}
					else if(specific->getString()=="3L  "){
						charScore = 3*charScore;
						score+=charScore;
					}
					else if(specific->getString()=="2W  "){
						multipliers.push_back(2);
					}
					else if(specific->getString()=="3W  "){
						multipliers.push_back(3);
					}
					else{
						score+=charScore;
					}
					prevlocation1.insert(make_pair(x, y+ycounter));	
					prevstring.push_back(specific->getString());											
					specific->setTile(*it2); //sets tile of board 										
					specific->setString(s);
					ycounter++;

					}

					else if(specific->isOccupied()==true){
						int skipPointCounter=0;
							while(specific->isOccupied()){
								specific = board->getBoard()[x][y+ycounter];

								if(specific->isOccupied()){
								//qDebug()<<specific->getTile()->getLetter()<<" ";
								skipPointCounter+=specific->getTile()->getPoints();
								}

								ycounter++;
							}
							score+=skipPointCounter; //count points of skipped tiles

							int charScore=(*it2)->getPoints();
							if(specific->getString()=="2L  "){ //calculate point of new tiles
								charScore = 2*charScore;
								score+=charScore;
							}
							else if(specific->getString()=="3L  "){
								charScore = 3*charScore;
								score+=charScore;
							}
							else if(specific->getString()=="2W  "){
								multipliers.push_back(2);
							}
							else if(specific->getString()=="3W  "){
								multipliers.push_back(3);
							}
							else{
								score+=charScore;
							}								
						
							prevlocation1.insert(make_pair(x, y-1+ycounter));	
							prevstring.push_back(specific->getString());												
							specific->setTile(*it2);
							specific->setString(s);	
					}

					
					break;
				}
			}
		} //THE END OF TRYING TO PLACE TILES INCLUDING SKIPS, BUT THATS IT DOES NOT CHECK FOR GAPS

		if(board->getBoard()[board->getFirstMoveX()][board->getFirstMoveY()]->getTile()!=NULL){
			firstmove=false;
		}

		if(isValidHorizontal(board,dict)==false || firstmove==true){ //if word is invalid, or first move not placed on "S" 
																	//replace your deleted tiles, and replace board like it used to be
			reset(prevlocation1, prevstring, board);
			score=prevScore;
			
			for(set<Tile*>::iterator it= tilesdeleted.begin(); it!=tilesdeleted.end(); ++it){ //replace lost tiles 
				p1tiles.insert(*it);
			}
				if(firstmove==true){
				QMessageBox msgBox;
				msgBox.setText("Must place first move on start tile!");
				msgBox.exec();
				input->setText("");}

				else{
				QMessageBox msgBox;
				msgBox.setText("Invalid Word!");
				msgBox.exec();
				input->setText("");}		
	
		}

		else if(isValidHorizontal(board,dict)==true && firstmove==false && trueCounter==0){ //first valid move on start tile
			if(addback>0){
				addBack = bag->drawTiles(addback);
				for(set<Tile*>::iterator it = addBack.begin(); it!=addBack.end(); ++it){
					p1tiles.insert(*it);
					boo.push_back((*it)->getLetter());
					boo+=to_string((*it)->getPoints());
					boo+=" ";
				}
			}


				allPlayers[turnCounter]->setScore(score);
				allPlayers[turnCounter]->setTiles(p1tiles);
				string temp = to_string(score);

				QMessageBox msgBox;
				msgBox.setText("You Have Placed Your Tiles!\nYour new tiles are: " + QString::fromStdString(boo) +"\nYou scored: "+ QString::fromStdString(temp));
				msgBox.exec();
				input->setText("");
				updateScoreBoard(scoreTracker,turnCounter,allPlayers);
				trueCounter++;
				if(allPlayers.size()==1){
					turnCounter=0;
				}
				else{
				turnCounter++;					
				}
				passCounter=0;

										

		} //end to check if checkmatch wowrks

		else if(isValidHorizontal(board,dict)==true && firstmove==false && trueCounter>0){ //if there are no neighbors, reset everything

			int neighborcounter = countNeighborHorizontal(prevlocation1, board, storage);

			if(neighborcounter==0){ //if no neighbors, reset

			resetOriginalCondition(prevlocation1, prevstring, board, p1tiles, tilesdeleted);

			QMessageBox msgBox;
			msgBox.setText("Tiles must be adjacent!");
			msgBox.exec();
			input->setText("");

			}

			else{ //else there are neighbors and continue placing everything
			if(addback>0){
				addBack = bag->drawTiles(addback);
				for(set<Tile*>::iterator it = addBack.begin(); it!=addBack.end(); ++it){
					p1tiles.insert(*it);
					boo.push_back((*it)->getLetter());
					boo+=to_string((*it)->getPoints());
					boo+=" ";
				}
			}
				multimap<int,int>::iterator it = prevlocation1.begin();
				int x = it->first;
				int y = it->second;
				int counter=0;
				allPlayers[turnCounter]->setTiles(p1tiles);
				firstmove=false;				

				if (board->getBoard()[x][y-1]->isOccupied()==true){ //Takes care of scoring for placing tiles at end of word. DIE + "D".
					while(board->getBoard()[x][y-1-counter]->isOccupied()==true){
						score+=board->getBoard()[x][y-1-counter]->getTile()->getPoints();
						counter++;
					}
				}

				for(int i=0; i<multipliers.size(); i++){
					score*=multipliers[i];
				}
				string temp = to_string(score);
				QMessageBox msgBox;
				msgBox.setText("You Have Placed Your Tiles!\nYour new tiles are: "+ QString::fromStdString(boo) + "\nYou scored: "+QString::fromStdString(temp));
				msgBox.exec();
				input->setText("");
				passCounter=0;		

				score+=prevScore;
				allPlayers[turnCounter]->setScore(score);
				updateScoreBoard(scoreTracker,turnCounter,allPlayers);				

				if(allPlayers.size()==1){
					turnCounter=0;
				}

				else if(turnCounter==allPlayers.size()-1){
					turnCounter=0;
				}
				else{
				turnCounter++;
				}

			}		
		} //end of last else if

	}
	

	else if(checkMatch(p1tiles,storage)==false){ //if tiles don't match, don't do anything and still players turn
		QMessageBox msgBox;
		msgBox.setText("Invalid Tiles!");
		msgBox.exec();
	}
		updateUserTiles(allPlayers, turnCounter, turn, tiles);
		updateBoard(qboard, board);

} //end of determine ==0


else if(determine==1){

	if(input3.length()+x>board->_x || x-input3.length()<0){ //invalid length placement
		QMessageBox msgBox;
		msgBox.setText("Invalid Location!");
		msgBox.exec();
		input->setText("");		
		return;
	}

	if(board->getBoard()[x][y]->isOccupied()==true){ //invalid, trying to place on something that is already there
		QMessageBox msgBox;
		msgBox.setText("Square is already occupied!");
		msgBox.exec();	
		return;
	}

	for(unsigned int i=0; i<input3.length(); i++){
		if(input3[i]=='?' && i!=input3.length()-1){
			storage.push_back(input3[i+1]);
		}
		else if(input3[i]=='?' && i==input3.length()-1){
		QMessageBox msgBox;
		msgBox.setText("Invalid use of ?");
		msgBox.exec();
		}
		storage.push_back(input3[i]);
	}

	//ACTUAL IMPLEMENTATION
	if(checkMatch(p1tiles,storage)==true){ //checks whether tiles are in hand
		for(vector<char>::iterator it=storage.begin(); it!=storage.end(); ++it){
			for(set<Tile*>::iterator it2=p1tiles.begin(); it2!=p1tiles.end(); ++it2){
				if((*it2)->getLetter()==(*it)){	

					p1tiles.erase(it2);
					addback++; //
					Square* specific = (board->getBoard())[x+xcounter][y]; //gets specific board
					string s;
					s.push_back(*it);
					s+="   ";
					string num = to_string((*it2)->getPoints());
					s+=num;
					tilesdeleted.insert(*it2);

					if(specific->isOccupied()==false){ //if there is a tile

					int charScore=(*it2)->getPoints();
					//qDebug()<<charScore<<endl;
					if(specific->getString()=="2L  "){
						charScore = 2*charScore;
						score+=charScore;
					}
					else if(specific->getString()=="3L  "){
						charScore = 3*charScore;
						score+=charScore;
					}
					else if(specific->getString()=="2W  "){
						multipliers.push_back(2);
					}
					else if(specific->getString()=="3W  "){
						multipliers.push_back(3);
					}
					else{
						score+=charScore;
					}
					prevlocation1.insert(make_pair(x+xcounter, y));	
					prevstring.push_back(specific->getString());											
					specific->setTile(*it2); //sets tile of board 										
					specific->setString(s);
					xcounter++;

					}

					else if(specific->isOccupied()==true){
						int skipPointCounter=0;
							while(specific->isOccupied()){
								specific = board->getBoard()[x+xcounter][y];

								if(specific->isOccupied()){
								skipPointCounter+=specific->getTile()->getPoints();
								}

								xcounter++;
							}
							score+=skipPointCounter; //count points of skipped tiles

							int charScore=(*it2)->getPoints();
							if(specific->getString()=="2L  "){ //calculate point of new tiles
								charScore = 2*charScore;
								score+=charScore;
							}
							else if(specific->getString()=="3L  "){
								charScore = 3*charScore;
								score+=charScore;
							}
							else if(specific->getString()=="2W  "){
								multipliers.push_back(2);
							}
							else if(specific->getString()=="3W  "){
								multipliers.push_back(3);
							}
							else{
								score+=charScore;
							}								
						
							prevlocation1.insert(make_pair(x-1+xcounter, y));	
							prevstring.push_back(specific->getString());												
							specific->setTile(*it2);
							specific->setString(s);	
					}

					
					break;
				}
			}
		} //THE END OF TRYING TO PLACE TILES INCLUDING SKIPS, BUT THATS IT DOES NOT CHECK FOR GAPS

		if(board->getBoard()[board->getFirstMoveX()][board->getFirstMoveY()]->getTile()!=NULL){
			firstmove=false;
		}

		if(isValidVertical(board,dict)==false || firstmove==true){ //if word is invalid, or first move not placed on "S" 
																	//replace your deleted tiles, and replace board like it used to be
			reset(prevlocation1, prevstring, board);
			score=prevScore;
			
			for(set<Tile*>::iterator it= tilesdeleted.begin(); it!=tilesdeleted.end(); ++it){ //replace lost tiles 
				p1tiles.insert(*it);
			}
				if(firstmove==true){
				QMessageBox msgBox;
				msgBox.setText("Must place first move on start tile!");
				msgBox.exec();
				input->setText("");}

				else{
				QMessageBox msgBox;
				msgBox.setText("Invalid Word!");
				msgBox.exec();
				input->setText("");}		
	
		}

		else if(isValidVertical(board,dict)==true && firstmove==false && trueCounter==0){ //first valid move on start tile
			if(addback>0){
				addBack = bag->drawTiles(addback);
				for(set<Tile*>::iterator it = addBack.begin(); it!=addBack.end(); ++it){
					p1tiles.insert(*it);
					boo.push_back((*it)->getLetter());
					boo+=to_string((*it)->getPoints());
					boo+=" ";
				}
			}

				allPlayers[turnCounter]->setScore(score);
				allPlayers[turnCounter]->setTiles(p1tiles);
				string temp = to_string(score);

				QMessageBox msgBox;
				msgBox.setText("You Have Placed Your Tiles!\nYour new tiles are: " + QString::fromStdString(boo) +"\nYou scored: "+ QString::fromStdString(temp));
				msgBox.exec();
				input->setText("");
				updateScoreBoard(scoreTracker,turnCounter,allPlayers);
				trueCounter++;
				if(allPlayers.size()==1){
					turnCounter=0;
				}
				else{
				turnCounter++;					
				}				
				passCounter=0;							

		} //end to check if checkmatch wowrks

		else if(isValidVertical(board,dict)==true && firstmove==false && trueCounter>0){ //if there are no neighbors, reset everything

			int neighborcounter = countNeighborVertical(prevlocation1, board, storage);

			if(neighborcounter==0){ //if no neighbors, reset

			resetOriginalCondition(prevlocation1, prevstring, board, p1tiles, tilesdeleted);
			QMessageBox msgBox;
			msgBox.setText("Tiles must be adjacent!");
			msgBox.exec();
			input->setText("");

			}

			else{ //else there are neighbors and continue placing everything
			if(addback>0){
				addBack = bag->drawTiles(addback);
				for(set<Tile*>::iterator it = addBack.begin(); it!=addBack.end(); ++it){
					p1tiles.insert(*it);
					boo.push_back((*it)->getLetter());
					boo+=to_string((*it)->getPoints());
					boo+=" ";
				}
			}
				multimap<int,int>::iterator it = prevlocation1.begin();
				int x = it->first;
				int y = it->second;
				int counter=0;
				allPlayers[turnCounter]->setTiles(p1tiles);
				firstmove=false;				

				if (board->getBoard()[x-1][y]->isOccupied()==true){ //Takes care of scoring for placing tiles at end of word. DIE + "D".
					while(board->getBoard()[x-1-counter][y]->isOccupied()==true){
						score+=board->getBoard()[x-1-counter][y]->getTile()->getPoints();
						counter++;
					}
				}

				for(int i=0; i<multipliers.size(); i++){
					score*=multipliers[i];
				}
				string temp = to_string(score);
				QMessageBox msgBox;
				msgBox.setText("You Have Placed Your Tiles!\nYour new tiles are: "+ QString::fromStdString(boo) + "\nYou scored: "+QString::fromStdString(temp));
				msgBox.exec();
				input->setText("");
				passCounter=0;		

				score+=prevScore;
				allPlayers[turnCounter]->setScore(score);
				updateScoreBoard(scoreTracker,turnCounter,allPlayers);				

				if(allPlayers.size()==1){
					turnCounter=0;
				}

				else if(turnCounter==allPlayers.size()-1){
					turnCounter=0;
				}
				else{
				turnCounter++;
				}


			}		
		} //end of last else if

	}
	

	else if(checkMatch(p1tiles,storage)==false){ //if tiles don't match, don't do anything and still players turn
		QMessageBox msgBox;
		msgBox.setText("Invalid Tiles!");
		msgBox.exec();
	}
		updateUserTiles(allPlayers, turnCounter, turn, tiles);
		updateBoard(qboard, board);

} //end of determine ==1



}//end of place function

void MainWindow::exchange(){
	if(input->text().isEmpty()){
		return;
	}

	set<Tile*>p1tiles = allPlayers[turnCounter]->getTiles(); //gets tiles fine after every turn. 
	vector<char>storage;
	vector<Tile*>addtobag;
	set<Tile*>addBack;

	string input2 = input->text().toStdString();
	transform(input2.begin(), input2.end(), input2.begin(), ::toupper);

	for(unsigned int i=0; i<input2.length(); i++){
		storage.push_back(input2[i]);
	}

	if(checkMatch(p1tiles,storage)==true){					
		for(vector<char>::iterator it=storage.begin(); it!=storage.end(); ++it){
			for(set<Tile*>::iterator it2=p1tiles.begin(); it2!=p1tiles.end(); ++it2){
				if((*it2)->getLetter()==(*it)){
					addtobag.push_back((*it2));
					p1tiles.erase(it2);										
					break;
				}
			}
		}

	if(addtobag.size()>0){
		bag->addTiles(addtobag);
		addBack = bag->drawTiles(addtobag.size());
	}

	string temp = "";
	for(set<Tile*>::iterator it = addBack.begin(); it!=addBack.end(); ++it){
		p1tiles.insert(*it);
		temp.push_back((*it)->getLetter());
		temp+=to_string((*it)->getPoints());
		temp+=" ";
	}

	allPlayers[turnCounter]->setTiles(p1tiles);
	QMessageBox msgBox;
	msgBox.setText("Successful!\nYour new tiles are: " + QString::fromStdString(temp));
	msgBox.exec();
	if(turnCounter==allPlayers.size()-1){
		turnCounter=0;
	}
	else{
	turnCounter++;				
	}
	updateUserTiles(allPlayers, turnCounter, turn, tiles);
	input->setText(QString::fromStdString(""));
	passCounter=0;	


	} //end to check if checkmatch wowrks

	else if(checkMatch(p1tiles,storage)==false){
		QMessageBox msgBox;
		msgBox.setText("Invalid Tiles");
		msgBox.exec();
		input->setText(QString::fromStdString(""));		
	}	


}

void MainWindow::pass(){

	if(allPlayers.size()==1){
		turnCounter=0;
		updateUserTiles(allPlayers,turnCounter, turn, tiles);	
	}

	else if(turnCounter==allPlayers.size()-1){
		turnCounter=0;
		updateUserTiles(allPlayers,turnCounter, turn, tiles);
		passCounter++;

		QMessageBox msgBox;
		msgBox.setText("You have passed your turn");
		msgBox.exec();	

		if(passCounter==allPlayers.size()){
		mainNext = new MainNext(allPlayers);
		close();
		mainNext->show();
		}			
	}	
	else{
		turnCounter++;
		updateUserTiles(allPlayers, turnCounter, turn, tiles);	
		passCounter++;

		QMessageBox msgBox;
		msgBox.setText("You have passed your turn");
		msgBox.exec();	

		if(passCounter==allPlayers.size()){
		mainNext = new MainNext(allPlayers);
		close();
		mainNext->show();
		}

	}

}