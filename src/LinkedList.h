#pragma once

#include "Node.h"
#include "Arduino.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	Node *start, *end;

	void addNodeAfter(Node*, int);
	void addNodeBefore(Node*, int);
	void removeNode(Node*);
	void emptyList();
	void clean();
	void setDirty();
	void copyList(LinkedList*);
	bool isDirty() const;
	int getCount() const;
	void printAll() const;
protected:
	bool m_dirty;

};
