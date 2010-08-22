#include <new>
#include "LinkedList.h"

LinkedList::LinkedList(void) :
	count(0),
	anchor(0)
{
	anchor.prev = &anchor;
	anchor.next = &anchor;
}

LinkedList::~LinkedList(void)
{
	Clear();
}

int LinkedList::Count()
{
	return count;
}

void LinkedList::Add(int value)
{
	anchor.prev->Add(new Node(value));
	count++;
}

void LinkedList::Remove(Node* node)
{
	node->Remove();
	delete node;
	count--;
}

void LinkedList::Remove(int value)
{
	Node* node = anchor.next;
	while (node != &anchor) {
		if (node->value == value) {
			Remove(node);
			break;
		}
		node = node->next;
	}
}

void LinkedList::RemoveAt(int index)
{
	Node* node = anchor.next;
	for (int i = 0; node != &anchor && i < index; i++) {
		node = node->next;
	}
	if (node != &anchor) {
		Remove(node);
	}
}

void LinkedList::Clear()
{
	while (anchor.next != &anchor) {
		anchor.next->Remove();
	}
}

LinkedList::Iterator LinkedList::Begin()
{
	return Iterator(anchor);
}

LinkedList::Node::Node(int value) :
	prev(NULL),
	next(NULL),
	value(value)
{
}

LinkedList::Node::~Node()
{
}

void LinkedList::Node::Add(Node* node)
{
	next->prev = node;
	node->next = next;
	next = node;
	node->prev = this;
}

void LinkedList::Node::Remove()
{
	prev->next = next;
	next->prev = prev;
}


LinkedList::Iterator::Iterator(const Node& anchor) :
	anchor(anchor),
	current(&anchor)
{
}

LinkedList::Iterator::~Iterator()
{
}

bool LinkedList::Iterator::HasNext()
{
	return (current->next != &anchor);
}

int LinkedList::Iterator::Next()
{
	current = current->next;
	return current->value;
}
