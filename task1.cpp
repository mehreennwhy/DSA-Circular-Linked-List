#include<iostream>
using namespace std;

class node
{
    public:
    node* next;

    string process_id;
    int exTime;
    int rTime;

    //constructor
    node(string id, int time)
    {
        this->process_id=id;
        this->exTime=time;
        this->rTime=time;
        this->next=NULL;
    }

};

void addProcess(node* &head, string id, int time)
{
    node* n = new node(id,time);

    if(head==NULL)
    {
        n->next=n;
        head=n;
    }
    else
    {
        node* temp=head;

        while(temp->next != head)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->next=head;

    }
}

void remove(node* &head, node* prev)
{
    if(head==head->next)
    {
        delete head;
        head=NULL;
    }
    else
    {
        node* temp = prev->next;
        prev->next = temp->next;

        if (temp == head)  // If we're removing the head node, move the head pointer
        {
            head = head->next;
        }

        delete temp;
    }
}

void display(node* head)
{
    if (head == NULL)
    {
        cout << "No processes left in the system.\n";
        return;
    }

    node* temp=head;
    cout << "Current state of processes: ";
    do
    {
        cout<<"[ "<<temp->process_id<<" , "<<temp->rTime<< " ]";
        temp=temp->next;
    }while(temp != head);
    cout << endl;
}

void cpuTime(node* &head, int t)
{
    node* temp = head;
    node* prev = NULL;

    while (head != NULL)
    {
        if (temp->rTime > 0)  // Check if the process has remaining time
        {
            cout << "Process " << temp->process_id << " is running. ";

            if (temp->rTime <= t)  // Process can complete in this cycle
            {
                cout << "Assigned CPU time: " << temp->rTime << ". It completes execution.\n";
                temp->rTime = 0;

                // Remove the process as it has finished
                if (prev == NULL)
                {
                    node* nextProcess = temp->next;
                    remove(head, temp);
                    temp = nextProcess;
                    prev = temp;  // Adjust prev for the next iteration
                }
                else
                {
                    remove(head, prev);
                    temp = prev->next;
                }
            }
            else  // Process still has remaining time
            {
                cout << "Assigned CPU time: " << t << ". Remaining time: " << (temp->rTime - t) << ".\n";
                temp->rTime -= t;
                prev = temp;
                temp = temp->next;
            }

            display(head);  // Show the current state of the system after each cycle
        }
    }
}


int main()
{
    node* head = NULL;

    // Adding processes (process_id, execution_time)
    addProcess(head, "P1", 10);
    addProcess(head, "P2", 4);
    addProcess(head, "P3", 6);
    addProcess(head, "P4", 8);

    cout<<"Initial: ";
    display(head);

    int quantum = 4;  // CPU time assigned to each process in one cycle

    // Run the scheduling simulation
    cpuTime(head, quantum);

    return 0;
}