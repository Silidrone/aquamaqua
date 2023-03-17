#ifndef MEEPROM_H_
#define MEEPROM_H_

#include "Arduino.h"
#include <EEPROM.h>
#include <vector>

class MEEPROM
{
public:
	static MEEPROM &instance();
	void printEEPROM();
	void reset();
	void write(String, String); // This function will overwrite if it gets the same id as the one already stored.
	String read(String);
private:
	MEEPROM();
	static const std::vector<char> m_authenticationLayout;
	static const int EEPROM_SIZE;
	//static const char END_OF_EEPROM_CHAR;
	static const char ENTRY_TERMINATOR_CHAR;
	static const char SEPERATOR_CHAR;

	struct Entry
	{
		String id;
		String val;
	};

	struct RangedPosition
	{
		int start;
		int end;
	};

	enum class Direction
		: int {
			LEFT, RIGHT
	};

	RangedPosition writeEntry(int, Entry);
	RangedPosition readEntry(int, Entry&);
	RangedPosition readEntry(String, Entry&);
	RangedPosition getEntryPosition(int);
	RangedPosition getEntryPosition(String);

	int writeString(int, String);
	void move(int, int, Direction, unsigned int);
	void moveLeft(int, int, unsigned int);
	void moveRight(int, int, unsigned int);

	int getBegginingAddress();
	void saveAddrIndex();
	int getAddrIndex();
	void begin();
	void start();
	bool isStarted();
	void commit();

	//static const char TERMINATOR_CHAR;
	int m_addr_index;
};

#endif /* MEEPROM_H_ */
