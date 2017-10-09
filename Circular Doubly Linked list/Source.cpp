#include<iostream>
#include<iomanip>

using namespace std;

struct node
{
	int data;
	struct node *previous;
	struct node *next;
};

node *head = new node;
node *ptr = NULL;
node *temp1 = NULL;
node *temp2 = NULL;

void initCDLL()
{
	head = new node;
	head->next = head;
	head->previous = head;
}

int appendNode(int i, int data)
{
	ptr = new node;
	ptr->data = data;

	while (true)
	{
		if (i == 0)//執行一次(除非重置)
		{
			head = ptr;
			head->next = head;
			head->previous = head;
			//cout << head->data << endl;
		}
		else if (i != 0)
		{
			temp1 = head;
			while (temp1->next != head)
			{
				temp1 = temp1->next;
			}
			temp1->next = ptr;
			ptr->previous = temp1;
			head->previous = ptr;
			ptr->next = head;
		}
		i++;
		break;
	}
	return i;
}

bool searchNode(int data)
{
	ptr = new node;
	ptr->data = data;
	temp1 = head->next;
	if (head->data == ptr->data)
	{
			return true;
	}
	while (temp1->data != head->data)
	{

		if (temp1->data == ptr->data)
		{
			return true;
			break;
		}
		else if (temp1->data != ptr->data)
		{
			temp1 = temp1->next;
		}
		else if (temp1->next == head)
		{
			if (temp1->data == ptr->data)
			{
				return true;
			}
		}
	}
	if (temp1->data != ptr->data)
	{
		return false;
	}
}

void Delete(int data)
{
	ptr = new node;
	ptr->data = data;
	if (searchNode(data) && ptr->data != head->data)
	{
		temp1 = head;
		while (temp1->data != ptr->data)
		{
			temp1 = temp1->next;
		}
		ptr = temp1->previous;
		ptr->next = temp1->next;
		(temp1->next)->previous = ptr;
		free(temp1);
	}

	else if (searchNode(data) && ptr->data == head->data)
	{
		temp1 = head;
		head = head->next;
		head->previous = temp1->previous;
		(temp1->previous)->next = head;
		free(temp1);
	}

	else
		cout << "The number is not in the CDLL!!" << endl;
}
void printForward_CDLL()
{
	cout << "Which position you want to start:";
	int num;
	cin >> num;
	cout << endl;

	temp1 = head;
	for (int i = 1; i < num; i++)
	{
		temp1 = temp1->next;
	}
	
	temp2 = temp1;//temp2紀錄COUT起始點的位置
	while (temp1->next != temp2)
	{
		cout << temp1->data << " ";
		temp1 = temp1->next;
	}
	if (temp1->next == temp2)//彌補while的缺漏
	{
		cout << temp1->data << endl<<endl;
	}
}

void printBackward_CDLL()
{
	cout << "Which position you want to start:";
	int num;
	cin >> num;
	cout << endl;

	temp1 = head;
	for (int i = 1; i < num; i++)
	{
		temp1 = temp1->next;
	}

	temp2 = temp1;//temp2紀錄COUT起始點的位置
	while (temp1->previous != temp2)
	{
		cout << temp1->data << " ";
		temp1 = temp1->previous;
	}
	if (temp1->previous == temp2)//彌補while的缺漏
	{
		cout << temp1->data << endl<<endl;
	}
}

int main()
{
	int i = 0;
	while (true)
	{
		cout << "<1> Initialize"<<endl<<"<2> Append"<<endl<<"<3> Search"<<endl
			<<"<4> Delete"<<endl<<"<5> Print Forward"<<endl<<"<6> Print Backward"
			<< endl << "<7> Exit!!" << endl << "Enter your choice:"<<endl<<endl;
		int choice;
		cin >> choice;
		cout << endl;
		
		if (choice == 1)
		{
			initCDLL();
		}
		if (choice == 2)
		{
			cout << "Append a number:";
			int data;
			cin >> data;
			i = appendNode(i,data);
			cout << endl;
		}
		if (choice == 3)
		{
			cout << "Which number your want to search:";
			int data;
			cin >> data;
			int a = 0;
			a = searchNode(data);
			cout << endl;
			if (a == 1)
			{
				cout << ptr->data << " is in the CDLL."<<endl<<endl;
			}
			else
			{
				cout << ptr->data << " is not in the CDLL."<<endl<<endl;
			}
		}
		if (choice == 4)
		{
			cout << "Which number your want to delete:";
			int data;
			cin >> data;
			Delete(data);
			cout << endl;
		}
		if (choice == 5)
		{
			printForward_CDLL();
		}
		if (choice == 6)
		{
			printBackward_CDLL();
		}
		if (choice == 7)
		{
			exit;
		}
	}

	system("pause");

}