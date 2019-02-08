/*
 * Options.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: pixari
 */

#include "Options.h"

Options::Options() {
	// TODO Auto-generated constructor stub
	//ensure the .pb files are using the same version of protobufs that we are
	GOOGLE_PROTOBUF_VERIFY_VERSION;
}

bool Options::load()
{
	//get file path from user
	string filename;
	cout << "Please enter the filepath for your options.army file: " << endl;
	cin >> filename;
	cout << "reading " << filename << endl;

	//open the file
	int fileDescriptor = open(filename, O_RDONLY);

	if( fileDescriptor < 0 )
	{
	std::cerr << " Error opening the file " << std::endl;
	return false;
	}

	//change it to something protobuffs can use
	google::protobuf::io::FileInputStream fileInput(fileDescriptor);
	fileInput.SetCloseOnDelete( true );

	//parse the file into an army object
	if (!google::protobuf::TextFormat::Parse(&fileInput, optionarmy))
	{
	cerr << std::endl << "Failed to parse file!" << endl;
	return false;
	}
	else
	{
	cout << "Read Input File - " << filename << endl;
	}

	return true;
}
