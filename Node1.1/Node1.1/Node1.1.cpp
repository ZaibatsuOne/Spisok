#include<iostream>



using namespace std;

	struct node
	{
		int data;
		node* next;
	};
	class list
	{
	private:
		node* head, * last;
	public:
		list()
		{
			head = NULL; // Голова списка
			last = NULL; // Хвост списка
		}
		bool isEmpty() {
			return head == nullptr;
		}
		// Создание списка с проверкой на 0 позицию 
		void crtNode(int value)
		{
			node* temp = new node;
			temp->data = value;
			temp->next = NULL;
			// Проверяем на наличие первого элемента
			if (head == NULL)
			{
				head = temp;
				last = temp;
				temp = NULL;
			}
			else
			{
				last->next = temp;
				last = temp;
			}
		}

		// Вывод списка в консоль
		void Screen()
		{
			node* temp = new node;
			temp = head;
			while (temp != NULL)
			{
				cout << temp->data << "\n";
				temp = temp->next;
			}
		}

		// Вставка в начало списка
		void pushFront(int value)
		{
			node* temp = new node;
			temp->data = value;
			temp->next = head;
			head = temp;
		}

		// Удаление первого элемента
		void popFront()
		{
			node* temp = new node;
			temp = head;
			head = head->next;
			delete temp;
		}

		// Удаление последнего элемента
		void popBack()
		{
			node* current = new node;
			node* previous = new node;
			current = head;
			while (current->next != NULL)
			{
				previous = current;
				current = current->next;
			}
			last = previous;
			previous->next = NULL;
			delete current;
		}

		// Удаление дубликатов
		void deleteNth(int data) {
			if (isEmpty()) {
				return;
			}
			if (head->data == data) {
				popFront();
				//return;
			}
			if (last->data == data) {
				popBack();
				//return;
			}
			Node* currEl = first;
			Node* nextEl = first->next;
			while (nextEl && nextEl->data != data) {
				currEl = currEl->next;
				nextEl = nextEl->next;
			}
			if (!nextEl) {
				cout « "Element does not exist" « endl;
				return;
			}
			currEl->next = nextEl->next;
			nextEl->next->prev = currEl;
			delete nextEl;
		}
		// Вставка в произвольную часть листа
		void getNth(int pos, int value)
		{
			node* pre = new node;
			node* cur = new node;
			node* temp = new node;
			cur = head;
			for (int i = 1; i < pos; i++)
			{
				pre = cur;
				cur = cur->next;
			}
			temp->data = value;
			pre->next = temp;
			temp->next = cur;
		}
	
		// Удаление из произвольного места
		void delNth(int pos)
		{
			node* current = new node;
			node* previous = new node;
			current = head;
			for (int i = 1; i < pos; i++)
			{
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
		}
};		
int main()
{
	setlocale(LC_ALL, "Russian");

		
		list list;

		// Создание листа
		list.crtNode(1);
		list.crtNode(2);
		list.crtNode(3);
		list.crtNode(4);


		cout << "\n Вывод всего списка: \n";
		list.Screen();

		cout << "\n Вставка в начало списка (pushFront): \n";
		list.pushFront(0);
		list.Screen();

		cout << "\n Удаление в начале списка (popFront): \n" ;
		list.popFront();
		list.Screen();

		cout << "\n Добавление в конец (pushBack): \n";
		list.crtNode(51);
		list.Screen();

		cout << "\n Удаление в конце списка (popBack): \n";
		list.popBack();
		list.Screen();

		cout << "\n Вставка произвольное место (getNth): \n";
		list.getNth(2, 10);
		list.Screen();

		cout << "\n Удаление из проивзольного места (delNth): \n";
		list.delNth(4);
		list.Screen();

		return 0;
}