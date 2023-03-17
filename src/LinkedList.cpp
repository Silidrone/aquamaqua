#include "LinkedList.h"
#include <stdio.h>

LinkedList::LinkedList()
{
	start = new Node();
	end = new Node();
	start->value = 0;
	end->value = 0;
	start->next = end;
	start->prev = 0;
	end->next = 0;
	end->prev = start;
	m_dirty = false;
}

LinkedList::~LinkedList()
{
	Node *x = start;
	Node *tmp;
	while (x) {
		tmp = x->next;
		delete x;
		x = tmp;
	}
}

void LinkedList::addNodeAfter(Node* prevNode, int value)
{
	Node *newNode = new Node();
	newNode->value = value;
	newNode->prev = prevNode;
	newNode->next = prevNode->next;
	prevNode->next->prev = newNode;
	prevNode->next = newNode;
	m_dirty = true;
}

void LinkedList::addNodeBefore(Node* nextNode, int value)
{
	addNodeAfter(nextNode->prev->prev, value);
}

void LinkedList::removeNode(Node* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;

	delete node;
	m_dirty = true;
}

void LinkedList::emptyList()
{
	for (Node *tmp = NULL, *x = start->next; x != end;) {
		tmp = x->next;
		removeNode(start->next);
		x = tmp;
	}
	m_dirty = true;
}

void LinkedList::clean()
{
	m_dirty = false;
}

void LinkedList::setDirty()
{
	m_dirty = true;
}

void LinkedList::copyList(LinkedList *list)
{
	emptyList();
	for (Node *x = list->end->prev; x != list->start; x = x->prev) {
		addNodeAfter(start, x->value);
	}
	m_dirty = true;
}

bool LinkedList::isDirty() const
{
	return m_dirty;
}

int LinkedList::getCount() const
{
	Node *x = start->next;
	int count = 0;
	while (x != end) {
		count++;
		x = x->next;
	}
	return count;
}

void LinkedList::printAll() const
{
	Node *x = start->next;
	while (x != end) {
		x = x->next;
	}
}
