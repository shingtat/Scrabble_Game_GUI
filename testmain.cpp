#include "starting_window.h"
#include <QApplication>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

#include "Dictionary.h"
#include "Board.h"
#include "Bag.h"

void readConfigFile (string config_file_name,
					 string & dictionary_file_name,
					 string & board_file_name,
					 string & bag_file_name,
					 unsigned int & hand_size)
{
	ifstream configFile (config_file_name.c_str());
	string line;
    bool number = false, board = false, tiles = false, dictionary = false;

	if (!configFile.is_open())
		throw invalid_argument("Cannot open file: " + config_file_name);
	while (getline (configFile, line))
	{
		stringstream ss (line);
		string parameter;
		ss >> parameter;
		if (parameter == "NUMBER:")
			{ ss >> hand_size; number = true; }
		else if (parameter == "BOARD:")
		    { ss >> board_file_name; board = true; }
		else if (parameter == "TILES:")
			{ ss >> bag_file_name; tiles = true; }
		else if (parameter == "DICTIONARY:")
			{ ss >> dictionary_file_name; dictionary = true; }
	}
	if (!number)
		throw invalid_argument("Hand size not specified in config file");
	if (!board)
		throw invalid_argument("Board file name not specified in config file");
	if (!tiles)
		throw invalid_argument("Bag file name not specified in config file");
	if (!dictionary)
		throw invalid_argument("Dictionary file name not specified in config file");
}

int main(int argc, char* argv[]){
	

	if (argc < 2 || argc > 2)
		cout << "Usage: Scrabble <config-filename>\n";
	try {
		string dictionaryFileName, boardFileName, bagFileName;
		unsigned int numTiles;

		readConfigFile (argv[1],
						dictionaryFileName, boardFileName, bagFileName,
						numTiles);	

	QApplication app(argc, argv);

	vector<string>fileNames;
	fileNames.push_back(dictionaryFileName);
	fileNames.push_back(boardFileName);
	fileNames.push_back(bagFileName);
	string s = to_string(numTiles);
	fileNames.push_back(s);

	StartingWindow startWindow(fileNames);

	startWindow.show();

	return app.exec();

		}

	catch (invalid_argument & e)
	{ 
		cout << "Fatal Error! " << e.what()<<endl;
	}			

}