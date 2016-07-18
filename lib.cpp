#include "lib.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>

using std::ifstream;
using std::cout;
using std::endl;
using std::hex;

void pcapngToCsv::fileOpen(const char* filename){
	//open an input pcapng file
    inputStream.open(filename, std::ifstream::binary);
}

void pcapngToCsv::setOffset(int x){
    //move the cursor in input file by offset x
    inputStream.seekg(x, inputStream.cur);
}

void pcapngToCsv::fileClose(){
	//close the opened pcapng file
    inputStream.close();
}

void pcapngToCsv::readFileHeader(){
	if (!inputStream.is_open() ){
		assert(0);	
	}
	unsigned int blockType=0;
	unsigned int blockLen=0;


	inputStream.seekg(0, inputStream.beg);
	//read in the section header block
	//currently skipping the optional part 
	inputStream.read((char*)&blockType, 4);
	assert(blockType == secHeaderBlock);
	inputStream.read((char*)&blockLen, 4);

	inputStream.read((char*)&byteOrderMagic, 4);
	inputStream.read((char*)&majorVersion, 2);
	inputStream.read((char*)&minorVersion, 2);
	inputStream.read((char*)&sectionLen, 8);
	setOffset(blockLen-24);
	
	//read in the interface description block
	//currently skipping the optional part
	inputStream.read((char*)&blockType, 4);
	assert( blockType == intfaceDscrpBlock);
	inputStream.read((char*)&blockLen, 4);


	inputStream.read((char*)&linkType, 2);
	setOffset(2);
	inputStream.read((char*)&snapLen, 4);
	setOffset(blockLen-16);
}	

int pcapngToCsv::readFileContent(){
	//read in enhanced packet block
	//add selection of ehanced, simple and obsolete packet types later
	//currently skipping the optional part
	unsigned int blockType=0;
	unsigned int blockLen=0;
	inputStream.read((char*)&blockType, 4);
	assert(blockType==enhancedPackBlock);
	inputStream.read((char*)&blockLen, 4);
	if (blockType!=6){
		return -1;
	}

	inputStream.read((char*)&interfaceId, 4);
	inputStream.read((char*)&timeHigh, 4);
	inputStream.read((char*)&timeLow, 4);
	inputStream.read((char*)&capLen, 4);
	inputStream.read((char*)&packLen, 4);
	packContent = new char[capLen+1];
	memset(packContent, 0, capLen+1);
	inputStream.read(packContent, capLen);
	setOffset(blockLen-28-capLen );	
	return 0;
}

void pcapngToCsv::printInfo(){
	cout<<"debug info\n";
	cout<<"section length = "<<hex<<sectionLen<<endl;
	cout<<"byteOrderMagic = "<<byteOrderMagic<<endl;
	cout<<"interfaceId = "<<interfaceId<<endl;
	cout<<"timeHigh = "<<timeHigh<<endl;
	cout<<"timeLow = "<<timeLow<<endl;
	cout<<"capLen = "<<capLen<<endl;
	cout<<"packLen = "<<packLen<<endl;
}

void pcapngToCsv::printblock(unsigned int blockType, unsigned int blockLen){
	cout<<hex<<"blockType = "<<blockType<<endl;
	cout<<hex<<"blockLen = "<<blockLen<<endl;
	cout<<endl;
}
	pcapngToCsv::pcapngToCsv(){
		packContent = nullptr;
	}

	pcapngToCsv::~pcapngToCsv(){
		delete[] packContent;
	}
