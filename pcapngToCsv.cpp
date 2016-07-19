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
	
	pcapngToCsv_Impl.readFileHeader();
	while ( 0 == pcapngToCsv_Impl.readFileContent() ){
		cout<<"----------------------\n";
	}
	
	pcapngToCsv_Impl.fileClose();
	
	return 0;
}
