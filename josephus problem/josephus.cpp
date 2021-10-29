#include<iostream>
using namespace std;
class node{
	public:
		node *next;
		int val;
		node(int val);
};
node::node(int val)
{
	this->val = val;
}
class List{
	node *current , *head;
	public:
		List(){
		current = head = NULL;
		}
		void add(int val);
		void print();
		int josephus();
};
void List::add(int val)
{
	node *n = new node(val);
	if(head == NULL)
	{
		head = n;
		head->next = head;
		current = head;
		return;
	}
	current->next = n;
	current = current->next;
	current->next = head;
}
int List::josephus()
{
	current = head;
	node *del = head->next;
	int val;
	while(head->next != head)
	{
		for(int i = 1; i < 3; i++)
		{
			current = current->next;
			del = del->next;
		}
		
		current->next = del->next;
		if(del == head)
		{
			head = head->next;
		}
		val = del->val;
		delete del;
		current = current->next;
		del = current->next;
		std::cout << "( " << val << " out ) " << "  "; 
		
	}
	std::cout << std::endl;
	return head->val;
}
void List::print()
{
	current = head;
	std::cout << "[ ";
	do{
		std::cout << current->val << " ";
		current = current->next;
	}while(current != head);
	std::cout << "]\n";
	
	
}
int main()
{
	List l;
	l.add(1);	
	l.add(2);	
	l.add(3);
	l.add(4);
    l.add(5);
	l.add(6);	
	l.add(7);
	l.add(8);	
	l.add(9);	
	l.add(10);
    l.add(11);
    l.add(12);
	l.print();
    cout<<endl;
	std::cout << "The Leader is ( " << l.josephus()<< " )";
}