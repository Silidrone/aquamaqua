#include "MEEPROM.h"

const std::vector<char> MEEPROM::m_authenticationLayout = { 'S', 'T', 'A', 'R', 'T' };
const int MEEPROM::EEPROM_SIZE = 4096;
//const char MEEPROM::END_OF_EEPROM_CHAR = (char) 243;
const char MEEPROM::ENTRY_TERMINATOR_CHAR = (char) 244;
const char MEEPROM::SEPERATOR_CHAR = (char) 245;

MEEPROM::MEEPROM()
{
	m_addr_index = 0;
	begin();
}

MEEPROM &MEEPROM::instance()
{
	static MEEPROM singleton;
	return singleton;
}

void MEEPROM::printEEPROM()
{
	Serial.println("----------EEPROM--------");
	for (int i = 0; i < m_addr_index; i++) {
		Serial.println((char) EEPROM.read(i));
	}
	Serial.println("----------EEPROM--------");
}

void MEEPROM::reset(){
	m_addr_index = 0;
	start();
}

void MEEPROM::write(String id, String s2)
{
	Entry new_entry { id, s2 };
	Entry old_entry { String(""), String("") };
	RangedPosition old_entry_position = readEntry(new_entry.id, old_entry);

	if (old_entry_position.start >= 0 && old_entry_position.end >= 0) {
		int new_val_size = new_entry.val.length();
		int old_val_size = old_entry.val.length();
		int move_amount = abs(new_val_size - old_val_size);

		if (new_val_size > old_val_size) {
			move(old_entry_position.end, m_addr_index - 1, Direction::RIGHT, move_amount);
			m_addr_index += move_amount;
		}
		else if (old_val_size > new_val_size) {
			move(old_entry_position.end, m_addr_index - 1, Direction::LEFT, move_amount);
			m_addr_index -= move_amount;
		}

		int write_position = old_entry_position.start;
		writeEntry(write_position, new_entry);
	}
	else {
		RangedPosition entry_position = writeEntry(m_addr_index, new_entry);
		m_addr_index = entry_position.end + 1;
	}
	commit();
}

String MEEPROM::read(String id)
{
	Entry entry {String(""), String("")};
	readEntry(id, entry);
	return entry.val;
}

MEEPROM::RangedPosition MEEPROM::writeEntry(int addr_index, MEEPROM::Entry entry)
{
	RangedPosition entry_position = { addr_index, -1 };
	addr_index = writeString(addr_index, entry.id);
	EEPROM.write(addr_index++, SEPERATOR_CHAR);
	addr_index = writeString(addr_index, entry.val);
	EEPROM.write(addr_index, ENTRY_TERMINATOR_CHAR);
	entry_position.end = addr_index;
	return entry_position;
}

MEEPROM::RangedPosition MEEPROM::readEntry(int addr_index, Entry &entry)
{
	RangedPosition failure = { -1, -1 };
	if (addr_index >= m_addr_index) {
		return failure;
	}

	RangedPosition entry_position = { addr_index, -1 };
	for (String parsed_string = ""; true;) {
		int val = EEPROM.read(addr_index++);
		if (val == SEPERATOR_CHAR) {
			entry.id = parsed_string;
			parsed_string.remove(0);
			continue;
		}
		else if (val == ENTRY_TERMINATOR_CHAR) {
			entry.val = parsed_string;
			break;
		} else if (addr_index >= m_addr_index){
			return failure;
		}
		parsed_string += (char) val;
	}
	entry_position.end = addr_index - 1;
	return entry_position;
}

MEEPROM::RangedPosition MEEPROM::readEntry(String id, Entry& entry)
{
	Entry parsed_entry { String(""), String("") };
	RangedPosition parsed_entry_position { -1, -1 };
	int addr_index = getBegginingAddress();

	while ((parsed_entry_position = readEntry(addr_index, parsed_entry)).start >= 0 && parsed_entry_position.end >= 0) {
		if (parsed_entry.id == id) {
			entry.id = parsed_entry.id;
			entry.val = parsed_entry.val;
			return parsed_entry_position;
		}
		addr_index = parsed_entry_position.end + 1;
	}

	return RangedPosition { -1, -1 };
}

MEEPROM::RangedPosition MEEPROM::getEntryPosition(int addr_index)
{
	MEEPROM::Entry tmp_entry = { String(""), String("") };
	return readEntry(addr_index, tmp_entry);
}

MEEPROM::RangedPosition MEEPROM::getEntryPosition(String id)
{
	MEEPROM::Entry tmp_entry = { String(""), String("") };
	return readEntry(id, tmp_entry);
}

int MEEPROM::writeString(int addr_index, String s)
{
	for (int i = 0; i < s.length(); i++) {
		EEPROM.write(addr_index++, s[i]);
	}
	return addr_index;
}

void MEEPROM::move(int start_addr_index, int end_addr_index, MEEPROM::Direction direction, unsigned int amount)
{
	if (direction == Direction::LEFT) {
		moveLeft(start_addr_index, end_addr_index, amount);
	}
	else if (direction == Direction::RIGHT) {
		moveRight(start_addr_index, end_addr_index, amount);
	}
}

void MEEPROM::moveLeft(int start_addr_index, int end_addr_index, unsigned int amount)
{
	for (int i = start_addr_index, j = i - amount; i <= end_addr_index && j <= end_addr_index - amount; i++, j++) {
		EEPROM.write(j, EEPROM.read(i));
	}
}

void MEEPROM::moveRight(int start_addr_index, int end_addr_index, unsigned int amount)
{
	for (int i = end_addr_index, j = i + amount; i >= start_addr_index && j >= start_addr_index + amount; i--, j--) {
		EEPROM.write(j, EEPROM.read(i));
	}
}

int MEEPROM::getBegginingAddress()
{
	return m_authenticationLayout.size();
}

void MEEPROM::saveAddrIndex()
{
	EEPROM.write(EEPROM_SIZE - 1, m_addr_index);
}

int MEEPROM::getAddrIndex()
{
	return EEPROM.read(EEPROM_SIZE - 1);

}

void MEEPROM::begin()
{
	EEPROM.begin(EEPROM_SIZE);
	if (!isStarted()) {
		start();
	}
	else {
		m_addr_index = getAddrIndex();
	}
}

void MEEPROM::start()
{
	for (int i = 0; i < m_authenticationLayout.size(); i++) {
		EEPROM.write(m_addr_index++, m_authenticationLayout[i]);
	}
	commit();
}

bool MEEPROM::isStarted()
{
	for (int i = 0; i < m_authenticationLayout.size(); i++) {
		if (m_authenticationLayout[i] != EEPROM.read(i)) {
			return false;
		}
	}
	return true;
}

void MEEPROM::commit()
{
	saveAddrIndex();
	EEPROM.commit();
}
