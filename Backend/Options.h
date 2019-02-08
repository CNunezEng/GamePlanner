/**
 * @file  Options.h
 * @brief This class loads and stores the options for building an army
 *
 * Created on: Jan 15, 2019
 * @author: pixari
 */
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <iostream>
#include <map>

#include "../proto/Army.pb.h"

using namespace std;

#ifndef BACKEND_OPTIONS_H_
#define BACKEND_OPTIONS_H_

/**
 * @class Options
 *
 * @brief a class to handle options files
 */
class Options {
public:
	/**
	 * @brief The class constructor checks the protobuf version
	 */
	Options();

	/**
	 * @brief the class destructor is empty.
	 */
	virtual ~Options(){};

	/**
	 * @brief The load function loads the options
	 *
	 * This function asks the user for a file path, opens the file
	 * and reads it into a ArmyDescription protobuf
	 *
	 * @return success is true if the file opened and was parsed false ow.
	 */
	bool load();

	/**
	 * @var optionarmy is the army container that holds the options for units
	 */
	ArmyDescription optionarmy;
};

#endif /* BACKEND_OPTIONS_H_ */
