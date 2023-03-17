#include "KeyBoardLayout.h"

KeyBoardLayout::KeyBoardLayout(std::vector<std::vector<String>> keys, std::vector<String> specialKeys)
{
	m_keys = std::move(keys);
	m_specialKeys = std::move(specialKeys);
}

KeyBoardLayout::~KeyBoardLayout()
{

}

void KeyBoardLayout::insertKey(int row, int column, String key){
	m_keys[row].insert(m_keys[row].begin() + column, key);
}

void KeyBoardLayout::deleteKey(int row, int column){
	m_keys[row].erase(m_keys[row].begin() + column);
}

void KeyBoardLayout::deleteKey(String key){
	KeyBoardLayout::KeyBoardPosition key_position = getKeyPosition(key);
	deleteKey(key_position.column, key_position.row);
}

void KeyBoardLayout::pushBackKey(int row, String key){
	m_keys[row].push_back(key);
}

void KeyBoardLayout::insertRow(int pos, std::vector<String> row){
	m_keys.insert(m_keys.begin() + pos, row);
}

void KeyBoardLayout::pushBackRow(std::vector<String> row){
	m_keys.push_back(row);
}

KeyBoardLayout::KeyBoardPosition KeyBoardLayout::getKeyPosition(String the_key){
	for(int row = 0; row < getRowCount(); row++){
		for(int col = 0; col < (getAllColumnsCount())[row]; col++){
			String key = getKey(row, col);
			if(key == the_key){
				KeyBoardPosition position{row, col};
				return position;
			}
		}
	}
	KeyBoardPosition failure_position{10000, 10000};
	return failure_position;
}


int KeyBoardLayout::getKeyCount()
{
	int size = 0;
	for(auto& it : m_keys){
		size += it.size();
	}
	return size;
}

int KeyBoardLayout::getRowCount()
{
	return m_keys.size();
}

std::vector<int> KeyBoardLayout::getAllColumnsCount()
{
	std::vector<int> columnCountVector;
	for(auto& it : m_keys){
		columnCountVector.push_back(it.size());
	}
	return columnCountVector;
}

int KeyBoardLayout::getColumnCount(int row)
{
	return m_keys[row].size();
}

int KeyBoardLayout::getSpecialKeyCount()
{
	return m_specialKeys.size();
}

std::vector<std::vector <String>> KeyBoardLayout::getAllKeys(){
	return m_keys;
}

String KeyBoardLayout::getKey(int row, int column)
{
	if(row >= getRowCount() || column >= getColumnCount(row) || row < 0 || column < 0){
		return String("");
	}
	return m_keys[row][column];
}

String KeyBoardLayout::getSpecialKey(int index)
{
	return m_specialKeys[index];
}

bool KeyBoardLayout::isSpecialKey(String key)
{
	for (auto& specialKey : m_specialKeys) {
		if (key == specialKey) {
			return true;
		}
	}
	return false;
}
