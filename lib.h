#ifndef LIB_H
#define LIB_H
#include <fstream>
#define secHeaderBlock 0x0A0D0D0A 
#define intfaceDscrpBlock 0x00000001 
#define enhancedPackBlock 0x00000006
#define simplePackBlock 0x00000003
#define obsoletePackBlock 0x00000002

class pcapngToCsv{
	public:
    
	std::ifstream inputStream;
	long long sectionLen;
	unsigned int byteOrderMagic;	
	char *hardWare;
	char *os;
	char *userappl;
	char *name;
	char *ipAddr;
	char *macAddr;
	unsigned interfaceId;
	unsigned int snapLen;
	unsigned int timeHigh;
	unsigned int timeLow;
	unsigned int capLen;
	unsigned int packLen;
	char *packContent;
	unsigned short majorVersion;
	unsigned short minorVersion;
	unsigned short linkType;

	void fileOpen(const char* filename);
	void setOffset(int x);
	void readFile();	
	void fileClose();
	void printInfo();
	void printblock(unsigned int blockType, unsigned int blockLen);
	pcapngToCsv();
	~pcapngToCsv();
};







#endif
