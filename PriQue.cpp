
//https://www.journaldev.com/35189/priority-queue-in-c-plus-plus
//https://stackoverflow.com/questions/51828816/why-do-we-need-to-add-a-vector-as-an-argument-in-priority-queue-declaration
//https://en.cppreference.com/w/cpp/container/priority_queue

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Person {
private:
    std::string nombre;
    int edad;

public:
    Person(std::string name, int ed) {
        nombre = name;
        edad = ed;
    }

    int getEdad()
    {
        return edad;
    }

    // sobrecargar 
    //friend ostream& <<
          //  << p1.getname << p1.getedad

};

//customizar el orden
class CompareClass {
public:
    bool operator() (int a, int b) {
        if (a > b)
            return true;
        return false;
    }
};

class CompareClassP {
public:
    bool operator() (Person P1, Person P2) {
        if (P1.getEdad() > P2.getEdad())
            return true;
        return false;
    }
};

void print_pqueue(priority_queue<int, vector<int>, CompareClass> pq) {

    priority_queue<int, vector<int>, CompareClass> copy_q = pq;
    cout << "Priority Queue : ";
    while (!copy_q.empty()) {
        cout << copy_q.top() << " ";
        copy_q.pop();
    }
    cout << "\n";
}


void print_pqueue_Basic(priority_queue<int, vector<int>> pq) {

    priority_queue<int, vector<int>> copy_q = pq;
    cout << "Priority Queue : ";
    while (!copy_q.empty()) {
        cout << copy_q.top() << " ";
        copy_q.pop();
    }
    cout << "\n";
}


void print_pqueueP(priority_queue<Person, vector<Person>, CompareClassP> pq) {

    priority_queue<Person, vector<Person>, CompareClassP> copy_q = pq;
    cout << "Priority Queue : ";
    while (!copy_q.empty()) {
        //cout << copy_q.top() << " ";
        copy_q.pop();
    }
    cout << "\n";
}


void print_p(priority_queue<int> pq) {

    priority_queue<int> copy_q = pq;
    cout << "Priority Queue : ";
    while (!copy_q.empty()) {
        cout << copy_q.top() << " ";
        copy_q.pop();
    }
    cout << "\n";
}

int main() {


    priority_queue<int, vector<int>> queue_int_Basic;
    queue_int_Basic.push(1300);
    queue_int_Basic.push(200);
    queue_int_Basic.push(400);
    queue_int_Basic.push(1900);

    cout << "Number of elements : " << queue_int_Basic.size() << endl;
    cout << "Top element : " << queue_int_Basic.top() << endl << endl;

    print_pqueue_Basic(queue_int_Basic);


    priority_queue<int, vector<int>, CompareClass> queue_int;
    cout << "Is the Queue empty now? : " << (queue_int.empty() ? "Yes" : "No") << endl;
    queue_int.push(9000);
    queue_int.push(200);
    queue_int.push(400);
    queue_int.push(5000);
    cout << "Number of elements : " << queue_int.size() << endl;
    cout << "Top element : " << queue_int.top() << endl << endl;
    print_pqueue(queue_int);

    cout << "Popping element from the top...\n\n";
    queue_int.pop();
    print_pqueue(queue_int);


        
    priority_queue<Person, vector<Person>, CompareClassP> queue_Person;

    queue_Person.push(Person("Carlos", 44));
    queue_Person.push(Person("Batman", 40));
    queue_Person.push(Person("Carlos Jr", 22));

        

    return 0;
}