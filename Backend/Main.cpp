#include "Options.h"

using namespace std;

int main(int argc, char* argv[])
{
	Options optionclass;

	if(!optionclass.load())
	{
		cerr << "failed to load";
		return 0;
	}



	return 0;
}
