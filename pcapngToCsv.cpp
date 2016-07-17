#include <iostream>
#include <vector>
#include <fstream>
#include "lib.h"

using std::cin;
using std::cout;
using std::vector;

int main() {
	pcapngToCsv pcapngToCsv_Impl;
    char filename[20] = "./test.pcapng";
	pcapngToCsv_Impl.fileOpen(filename);
	//return 0;	
	pcapngToCsv_Impl.readFile();
	pcapngToCsv_Impl.fileClose();
	
	return 0;
}
