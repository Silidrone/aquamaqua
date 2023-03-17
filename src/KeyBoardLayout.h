#ifndef KEYBOARDLAYOUT_H_
#define KEYBOARDLAYOUT_H_

#include "Arduino.h"
#include <vector>


class KeyBoardLayout
{
	struct KeyBoardPosition
	{
		int row;
		int column;
	};

public:
	KeyBoardLayout(std::vector<std::vector <String>> keys, std::vector<String> specialKeys);
	virtual ~KeyBoardLayout() = 0;

	void insertKey(int row, int column, String key);
	void deleteKey(int row, int column);
	void deleteKey(String key);
	void pushBackKey(int row, String key);


	void insertRow(int pos, std::vector<String> row);
	void pushBackRow(std::vector<String> row);

	int getKeyCount();
	int getRowCount();

	std::vector<int> getAllColumnsCount();
	int getColumnCount(int row);
	int getSpecialKeyCount();
	std::vector<std::vector <String>> getAllKeys();

	String getKey(int row, int column);
	String getSpecialKey(int index);

	bool isSpecialKey(String);
protected:
	std::vector<std::vector <String>> m_keys;
	std::vector <String> m_specialKeys;
private:
	KeyBoardPosition getKeyPosition(String key);
};

#endif /* KEYBOARDLAYOUT_H_ */
