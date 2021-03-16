//#include <iostream>
//#include <list>
//#include <cstring>
//using namespace std;
//
//class HashTable
//{
//private:
//	static const int hashGroups = 10;
//	list<pair<int, string>> table[hashGroups];
//public:
//	bool isEmpty() const;
//	int hashFunction(int key);
//	void insertItem(int key, string value);
//	void removeItem(int key);
//	string searchTable(int key);
//	void printTable();
//};
//
//bool HashTable::isEmpty() const
//{
//	int sum{};
//	for (size_t i{}; i < hashGroups; i++)
//	{
//		sum += table[i].size();
//	}
//
//	if (!sum)
//	{
//		return true;
//	}
//	return false;
//}
//
//int HashTable::hashFunction(int key)
//{
//	return key % hashGroups;
//}
//
//void HashTable::insertItem(int key, string value)
//{
//	int hashValue = hashFunction(key);
//	auto& cell = table[hashValue];
//	auto bItr = begin(cell);
//	bool keyExists = false;
//	for (; bItr != end(cell); bItr++)
//	{
//		if (bItr->first == key)
//		{
//			keyExists = true;
//			bItr->second = value;
//			cout << "Key exists. Value replaced" << endl;
//			break;
//		}
//	}
//	if (!keyExists)
//	{
//		cell.emplace_back(key, value);
//	}
//	return;
//}
//
//void HashTable::removeItem(int key)
//{
//	int hashValue = hashFunction(key);
//	auto& cell = table[hashValue];
//	auto bItr = begin(cell);
//	bool keyExists = false;
//	for (; bItr != end(cell); bItr++)
//	{
//		if (bItr->first == key)
//		{
//			keyExists = true;
//			bItr = cell.erase(bItr);
//			cout << "Item removed" << endl;
//			break;
//		}
//	}
//
//	if (!keyExists)
//	{
//		cout << "Key not found. Pair" << endl;
//	}
//	return;
//}
//
//void HashTable::printTable()
//{
//	for (size_t i{}; i < hashGroups; i++)
//	{
//		if (table[i].size() == 0)
//		{
//			continue;
//		}
//		auto bItr = table[i].begin();
//		for (; bItr != table[i].end(); bItr++)
//		{
//			cout << "Key: " << bItr->first << "Value: " << bItr->second;
//		}
//	}
//	return;
//
//}
//
//int main()
//{
//	HashTable table;
//
//	if (table.isEmpty())
//	{
//		cout << "Correct answer" << endl;
//	}
//	else
//	{
//		cout << "No" << endl;
//	}
//
//	table.insertItem(15, "Sam");
//	table.insertItem(78, "Rufat");
//	table.insertItem(42, "Escanor");
//	table.insertItem(99, "Sun");
//
//	table.printTable();
//
//	table.removeItem(78);
//
//	if (table.isEmpty())
//	{
//		cout << "No" << endl;
//	}
//	else
//	{
//		cout << "Correct answer" << endl;
//	}
//
//
//
//}
