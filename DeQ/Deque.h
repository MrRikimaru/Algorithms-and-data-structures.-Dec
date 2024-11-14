#ifndef DEQUE_H
#define DEQUE_H

#include <vector>
#include <iostream>
#include <algorithm>

using std::endl;
using std::out_of_range;
using std::cout;
using std::cin;
using std::min;
using std::max;
using std::vector;

template <typename T>
class Deque
{
	/*
	��������� ������������ �������
	nullptr <- head <--> node_1 <--> ... <--> node_n <--> tail -> nullptr
	head - ������ node (����)
	tail - ��������� node (����)
	Deque[0] = head
	Deque[1] = head->next
	Deque[N-1] = tail
	Deque[N-2] = tail->previous
	*/
private:
	//���� ������, �������� ������ (data) ���� T, 
	//��������� �� ��������� (next) � ���������� ������� (previous)
	struct Node
	{
		T data;
		Node* next;
		Node* previous;

		Node(T data, Node* previous = nullptr, Node* current = nullptr) :
			data(data), next(current), previous(previous)
		{
			if (previous != nullptr)
				previous->next = this;

			if (current != nullptr)
				current->previous = this;
		}
	};

	Node* _head;
	Node* _tail;
	unsigned _nodesCount;

	// ������� �������, �������� ���������� ������
	// ���� ������� ������ �������, ������ true, ����� false
	bool _remove_node(Node* node)
	{
		if (node == nullptr)
			return false;
		if (node->previous != nullptr) // head
			node->previous->next = node->next;
		else
			_head = node->next;

		if (node->next != nullptr) // tail
			node->next->previous = node->previous;
		else
			_tail = node->previous;

		delete node;
		_nodesCount--;
		return true;
	}

	// ���� ������ ��� ��������� �������, ������ � ������� ����� value
	// ���������� ��������� �� ���� � ������ ������, ����� nullptr
	Node* _search(T value, bool isSearchFromEnd, Node* element = nullptr)
	{
		Node* current = element;
		if (element == nullptr)
			current = isSearchFromEnd ? _tail : _head;
		while (current != nullptr)
		{
			if (current->data == value)
				return current;
			current = isSearchFromEnd ? current->previous : current->next;
		}
		return nullptr;
	}

	// ���� ������� �� �������
	// � ������ ������ ���������� ��������� �� ����, ����� nullptr
	Node* _get_element(unsigned index)
	{
		if (index < 0 || index >= _nodesCount)
			return nullptr;
		Node* element;
		if (index <= _nodesCount / 2)
		{
			element = _head;
			for (int i = 0; i < index; i++)
				element = element->next;
		}
		else
		{
			element = _tail;
			for (int i = _nodesCount - 1; i > index; i--)
				element = element->previous;
		}
		return element;
	}

	// ���� ������ ��� ��������� ������� �� ��������
	// � ������ ������ ����� ������� ��������, ����� ��������� NOT_FOUND
	unsigned _find(T value, bool isStartingFromEnd, unsigned startIndex)
	{
		for (Node* current = _get_element(startIndex);
			current != nullptr;
			current = isStartingFromEnd ? current->previous : current->next)
		{
			if (current->data == value)
				return startIndex;
			startIndex = isStartingFromEnd ? --startIndex : ++startIndex;
		}
		return NOT_FOUND; // unsigned_max
	}

public:
	// ���������, ������� ������������ �� �������, � ������� �� ���� ����������
	static unsigned const NOT_FOUND = ~0;

	Deque() : _nodesCount(0), _head(nullptr), _tail(nullptr)
	{
	}

#pragma region Adding elements

	// ���������� �������� �� ��������� �������
	void insert(unsigned index, T newElement)
	{
		if (index < 0 || index > _nodesCount)
			throw out_of_range("Error! Incorrect index!");

		if (_nodesCount == 0)
		{
			_head = new Node(newElement);
			_tail = _head;
		}
		else
		{
			if (index == _nodesCount)
				_tail = new Node(newElement, _tail, nullptr);
			else if (index == 0)
				_head = new Node(newElement, nullptr, _head);
			else
			{
				Node* current = _get_element(index);
				new Node(newElement, current->previous, current);
			}
		}
		_nodesCount++;
	}

	// ���������� �������� � ������
	void push_front(T newElement)
	{
		insert(0, newElement);
	}

	// ���������� �������� � �����
	void push_back(T newElement)
	{
		insert(_nodesCount, newElement);
	}

#pragma endregion

#pragma region Methods remove

	// �������� ������ (�������) �������� �� �������� value
	// ����� true � ������ ��������� ��������, ����� false
	bool remove(T value)
	{
		return _remove_node(_search(value, false));
	}

	// �������� ������ (����������) �������� �� �������� value
	// ����� true � ������ ��������� ��������, ����� false
	bool remove_last(T value)
	{
		return _remove_node(_search(value, true));
	}

	// �������� ������ �������� �� ������� pos
	// ����� true � ������ ��������� ��������, ����� false
	bool remove_at(unsigned pos)
	{
		return _remove_node(_get_element(pos));
	}

	// �������� ���� ��������� �� ��������� value
	// ����� ���������� �������� ���������
	unsigned remove_all(T value)
	{
		unsigned removedCount = 0;
		while (remove(value))
			removedCount++;
		return removedCount;
	}

#pragma endregion

#pragma region Methods find

	// ����� ������ �������� �� ��������
	// � ������ ������ ����� ������� ������� ��������, ����� ��������� NOT_FOUND
	// ����� ���������� � ������� �������� � ������� �� ����� ������
	unsigned find(T value)
	{
		return _find(value, false, 0);
	}
	// ����� ������ �������� �� ��������
	// � ������ ������ ����� ������� ������� ��������, ����� ��������� NOT_FOUND
	// ����� �������� � ������� pos	� ������� �� ����� ������
	unsigned find(T value, unsigned startIndex)
	{
		return _find(value, false, startIndex);
	}

	// ����� ���������� �������� �� ��������
	// � ������ ������ ����� ������� ������� ��������, ����� ��������� NOT_FOUND
	// ����� ���������� � ���������� �������� � ������� �� ������ ������
	unsigned find_last(T value)
	{
		return _find(value, true, _nodesCount - 1);
	}

	// ����� ���������� �������� �� ��������
	// � ������ ������ ����� ������� ������� ��������, ����� ��������� NOT_FOUND
	// ����� �������� � ������� pos	� ������� �� ������ ������
	unsigned find_last(T value, unsigned startIndex)
	{
		return _find(value, true, startIndex);
	}

	// ����� ���� ��������� �� ��������� value
	// ����� ������ (vector<unsigned>) ���� ������� ��������� ���������
	vector<unsigned> find_all(T value)
	{
		vector<unsigned> founds = {};
		unsigned index = 0;
		do
		{
			index = find(value, index);
			if (index != NOT_FOUND)
				founds.push_back(index);
			else
				break;
			index++;
		} while (index < _nodesCount);
		return founds;
	}

#pragma endregion

#pragma region Methods update

	// �������� �������� ������� ���������� �������� �� ��������� oldValue �� newValue 
	// ����� true ��� � ������ ������, ����� false
	bool update(T oldValue, T newValue)
	{
		Node* element = _search(oldValue, false);
		if (element == nullptr)
			return false;
		element->data = newValue;
		return true;
	}

	// �������� �������� ���������� ���������� �������� �� ��������� oldValue �� newValue 
	// ����� true ��� � ������ ������, ����� false
	bool update_last(T oldValue, T newValue)
	{
		Node* element = _search(oldValue, true);
		if (element == nullptr)
			return false;
		element->data = newValue;
		return true;
	}

	// �������� �������� ���� ��������� �� ��������� oldValue �� newValue 
	// ����� ���������� �����
	// ���� oldValue � newValue �����, ������ 0
	unsigned update_all(T oldValue, T newValue)
	{
		if (oldValue == newValue)
			return 0;
		unsigned updatedCount = 0;
		while (update(oldValue, newValue))
			updatedCount++;
		return updatedCount;
	}

#pragma endregion

#pragma region Useful methods


	// ���������� ���������� ��������� � ������
	unsigned size()
	{
		return _nodesCount;
	}

	// ������� ������ �� �����, ���� �������� true ������� ������ � �������� �������
	void print_all(bool isPrintReversed = false)
	{
		cout << "List:" << endl;
		if (isPrintReversed == false)
		{
			for (Node* current = _head; current != nullptr; current = current->next)
				cout << current->data << endl;
		}
		else
		{
			for (Node* current = _tail; current != nullptr; current = current->previous)
				cout << current->data << endl;
		}
		if (_nodesCount != 0)
			cout << endl;
	}

	// �������� [ ] ��������� �� ������� �������� ������ �� ������ �������� ������
	T& operator[](unsigned index)
	{
		Node* element = _get_element(index);
		if (element == nullptr)
			throw out_of_range("Incorrect index");
		return element->data;
	}

	// ����� ������� ��������� ���� ���������
	void swap(unsigned firstElementIndex, unsigned secondElementIndex)
	{
		T tempdata = (*this)[firstElementIndex];
		(*this)[firstElementIndex] = (*this)[secondElementIndex];
		(*this)[secondElementIndex] = tempdata;
	}
#pragma endregion

#pragma region Methods pop erase clear

	// �������� ������� �������� � ������
	// ���� ������� ������ �������, ������ true, ����� false
	bool pop_back()
	{
		return remove_at(_nodesCount - 1);
	}

	// �������� ������� �������� � �����
	// ���� ������� ������ �������, ������ true, ����� false
	bool pop_front()
	{
		return remove_at(0);
	}

	// ������� ��� �������� �� ��������� [start..stop]
	// stopIndex ������ ���������� � ��������
	void erase(unsigned startIndex, unsigned stopIndex)
	{
		if (_nodesCount == 0)
			return;
		if (stopIndex >= _nodesCount)
			throw out_of_range("Error! Incorrect index!");
		long _max = max(startIndex, stopIndex);
		long _min = min(startIndex, stopIndex);

		while (_min <= _max)
		{
			remove_at(_min);
			_max--;
		}

	}

	// ������� ��� �������� ������� �� start
	void erase(unsigned startIndex)
	{
		erase(startIndex, _nodesCount - 1);
	}

	// ������� ���� ������
	void clear()
	{
		erase(0);
	}

	// ������� ������, �������� ������
	~Deque()
	{
		clear();
	}

#pragma endregion

};

#endif
