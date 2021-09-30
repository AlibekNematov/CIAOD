#include <iostream>
#include <vector>

using namespace std;


// Ќаименование товара, артикул, кол-во товара
struct ProductData
{
	string name;
	int count1;
	int article;
};

class HashTab 
{
	vector<ProductData> list;
	int a = 3;
	int count = 0;

public:
	HashTab() 
	{
		list.resize(a);
		for (auto& s : list) {
			s.name = "-1";
		}

	}
	//хеширование
	int hash(int key) { return key; };

	int getIndex(int hash) { return hash % a; };

	//рехеширование
	void rehash() 
	{
		a *= 2;
		vector<ProductData> New;
		New.resize(a);
		for (auto& s : New) 
		{
			s.name = -1;
		}
		for (auto& product : list)
		{
			int b = getIndex(hash(product.article));
			while (New[b].name != "-1" && New[b].name != product.name)
			{
				b = (b + 1) % a;

				New[b] = product;
			}
			list.clear();
			list = New;
		}
	}

	//добавление продукта
	void add(int key, ProductData product)
	{
		if (count == a)
		{
			rehash();
		}
		int b = getIndex(hash(key));
		while (list[b].name != "-1" && list[b].article != key)
		{
			b = (b + 1) % a;
		}
		if (list[b].article != key){
			count++;
		}
		list[b] = product;
		list[b].article = key;
	}

	//удаление продукта
	int pop(int key) 
	{
		int b = getIndex(hash(key));
		while (list[b].name != "-1") 
		{
			if (list[b].article == key) 
			{
				list[b].name = "-1";
				count--;
				return 1;
			}
			b = (b + 1) % a;
		}
		return 0;
	}

	ProductData getProduct(int key) 
	{
		int b = getIndex(hash(key));
		while (list[b].name != "-1") 
		{
			if (list[b].article == key) 
			{
				return list[b];
			}
			b = (b + 1) % a;
		}
		return {"not found"};
	};

	int getSize() { return a; };
	int getCount() { return count; }
};

int main()
{
	HashTab c;
	c.add(11231241, { "Hello", 10 });
	cout << "Size: " << c.getSize() << " count: " << c.getCount() << endl;
	c.add(11231241, { "hot-dog", 5});
	cout << "Size: " << c.getSize() << " count: " << c.getCount() << endl;
	cout << "name - " << c.getProduct(11231241).name << ", " << "quantity - " << c.getProduct(11231451).count1 << endl;
}