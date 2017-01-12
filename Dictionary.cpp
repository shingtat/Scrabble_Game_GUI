/*
 * Dictionary.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: kempe
 */

// The following is a suggestion for how to proceed.
// Feel free to make any changes you like.

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary (string dictionary_file_name)
{
	ifstream dictFile (dictionary_file_name.c_str());
	string word;


	if (dictFile.is_open())
	{
		while (getline (dictFile, word))
		{
			word.erase(word.length()); // remove end-of-line character
			
			dictionary.insert(word);
		
		}
		dictFile.close ();
	}
	else throw invalid_argument("Cannot open file: " + dictionary_file_name);
}

Dictionary::~Dictionary(){
	
}

bool Dictionary::checkWord(string what){

	// for(set<string>::iterator it = dictionary.begin(); it!=dictionary.end(); ++it){
	// 	if((*it)==what){
	// 		return true;
	// 	}
	// 	else{
	// 		return false;
	// 	}
	// }

	set<string>::iterator it;
	it = dictionary.find(what);
	if(it!=dictionary.end()){
		return true;
	}
	else{
		return false;
	}

 }

 void Dictionary::printDict(){
 	for(set<string>::iterator it = dictionary.begin(); it!=dictionary.end(); ++it){
 		cout<<(*it)<<endl;
 	}
 }
