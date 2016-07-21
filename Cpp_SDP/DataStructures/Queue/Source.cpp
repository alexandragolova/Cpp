#include<iostream>
#include<string>
#include"Queue.cpp"
using namespace std;

int main()
{
	Queue<int> queue= Queue<int>(5);
	int choice,data;

	cout << "\n1. Enqueue\n2. Dequeue\n3. Size\n4. Display all element\n5. Quit";
	cin >> choice;

	switch (choice) {
	case 1:
		if (!queue.IsFull()) {
			cout << "\nEnter data: ";
			cin >> data;
			queue.Enqueue(data);
		}
		else {
			cout << "Queue is Full" << endl;
		}
		break;
	case 2:
		if (!queue.IsEmpty()) {
			cout << "The data dequeued is :" << queue.Dequeue();
		}
		else {
			cout << "Queue is Emtpy" << endl;
		}
		break;
	case 3:
		cout << "Size of Queue is " << queue.Size();
		break;
	case 4:
		queue.Display();
		break;
	case 5:
		exit(0);
		break;
	}

	
	return 0;
}