#ifndef ___LINKED_LIST___
#define ___LINKED_LIST___

class LinkedList
{
private:
	struct Node
	{
		Node(int value);
		virtual ~Node();

		void Add(Node* node);
		void Remove();

		Node* prev;
		Node* next;
		int value;
	};

public:
	class Iterator
	{
	public :
		Iterator(const Node& anchor);
		virtual ~Iterator();

		bool HasNext();
		int Next();

		const Node& anchor;
		const Node* current;
	};

public:
	LinkedList();
	virtual ~LinkedList();

	int Count();
	void Add(int value);
	void Remove(Node* node);
	void Remove(int value);
	void RemoveAt(int index);
	void Clear();

	Iterator Begin();

private:
	int count;
	Node anchor;
};

#endif // ___LINKED_LIST___