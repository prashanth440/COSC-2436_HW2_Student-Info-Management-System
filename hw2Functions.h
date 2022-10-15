#ifndef hw2Functions_h
#define hw2Functions_h
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*
 Sources:
 1) https://www.geeksforgeeks.org/bubble-sort-for-linked-list-by-swapping-nodes/
 2) https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
 */
struct record
{
    string ID, firstName, lastName, DOB, GPA;
    record *next;
};

void printLinkedList(record *head, string outFileName)
{
    ofstream fileOutput;
    fileOutput.open(outFileName);
    //fileOutput.open("/Users/saiprashanthharihar/Desktop/hw2Output.txt");
    record *current = head;
    while(current->next != nullptr)
    {
        cout << "{id:" << current->ID << ",first:" << current->firstName << ",last:" << current->lastName << ",DOB:" << current->DOB << ",GPA:" << current->GPA << "}" << endl;
        fileOutput << "{id:" << current->ID << ",first:" << current->firstName << ",last:" << current->lastName << ",DOB:" << current->DOB << ",GPA:" << current->GPA << "}" << endl;
        current = current->next;
    }
    fileOutput.close();
}

record *Swap(record *ptr1, record *ptr2)
{
    record *temp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = temp;
    return ptr2;
}

void bubbleSortLinkedList(record **head, int size, string command)
{
    record **h;
    int i, j;
    bool flag;
    
    
    if(command.find("id") == 0)
    {
        for(i = 0; i <= size; i++)
        {
            h = head;
            flag = false;
            
            for(j = 0; j < size - i - 1; j++)
            {
                record *p1 = *h;
                record *p2 = p1->next;
                
                if(stoi(p1->ID) > stoi(p2->ID))
                {
                    *h = Swap(p1, p2);
                    flag = true;
                }
                h = &(*h)->next;
            }
            if(flag == 0)
            {
                break;
            }
        }
    }
    else if(command.find("first") == 0)
    {
        for(i = 0; i <= size; i++)
        {
            h = head;
            flag = false;
            
            for(j = 0; j < size - i - 1; j++)
            {
                record *p1 = *h;
                record *p2 = p1->next;
                
                if(p1->firstName > p2->firstName)
                {
                    *h = Swap(p1, p2);
                    flag = true;
                }
                h = &(*h)->next;
            }
            if(flag == 0)
            {
                break;
            }
        }
    }
    else if(command.find("last") == 0)
    {
        for(i = 0; i <= size; i++)
        {
            h = head;
            flag = false;
            
            for(j = 0; j < size - i - 1; j++)
            {
                record *p1 = *h;
                record *p2 = p1->next;
                
                if(p1->lastName > p2->lastName)
                {
                    *h = Swap(p1, p2);
                    flag = true;
                }
                h = &(*h)->next;
            }
            if(flag == 0)
            {
                break;
            }
        }
    }
    else if(command.find("DOB") == 0)
    {
        for(i = 0; i <= size; i++)
        {
            h = head;
            flag = false;
            
            for(j = 0; j < size - i - 1; j++)
            {
                record *p1 = *h;
                record *p2 = p1->next;
                
                if(p1->DOB > p2->DOB)
                {
                    *h = Swap(p1, p2);
                    flag = true;
                }
                h = &(*h)->next;
            }
            if(flag == 0)
            {
                break;
            }
        }
    }
    else if(command.find("GPA") == 0)
    {
        for(i = 0; i <= size; i++)
        {
            h = head;
            flag = false;
            
            for(j = 0; j < size - i - 1; j++)
            {
                record *p1 = *h;
                record *p2 = p1->next;
                
                if(p1->GPA > p2->GPA)
                {
                    *h = Swap(p1, p2);
                    flag = true;
                }
                h = &(*h)->next;
            }
            if(flag == 0)
            {
                break;
            }
        }
    }
    
    
}

void deleteRecord(record **head, string deleteID)
{
    record* temp = *head;
    record* prev = nullptr;
    if(temp != nullptr && temp->ID.find(deleteID) == 0)
    {
            *head = temp->next;
            delete temp;
            return;
    }
    else
    {
       while(temp != nullptr && temp->ID.find(deleteID) != 0)
       {
           prev = temp;
           temp = temp->next;
       }
       if (temp == nullptr)
       {
           return;
       }
        prev->next = temp->next;
        delete temp;
    }
}

record *removeDuplicate(record *head)
{
    record *current = head;
    record *newHead = new record;
    record *ptr1 = newHead;
    
    while(current->next != nullptr)
    {
        if(current->ID.find(current->next->ID) == 0 && current->next->ID != "")
        {
            newHead->ID = current->next->ID;
            newHead->firstName = current->next->firstName;
            newHead->lastName = current->next->lastName;
            newHead->DOB = current->next->DOB;
            newHead->GPA = current->next->GPA;
            //numRecords--;
        }
        else
        {
            newHead->ID = current->ID;
            newHead->firstName = current->firstName;
            newHead->lastName = current->lastName;
            newHead->DOB = current->DOB;
            newHead->GPA = current->GPA;
            newHead->next = new record;
            newHead = newHead->next;
        }
        current = current->next;
    }
    newHead->ID = current->ID;
    newHead->firstName = current->firstName;
    newHead->lastName = current->lastName;
    newHead->DOB = current->DOB;
    newHead->GPA = current->GPA;
    newHead->next = nullptr;
    return ptr1;
}
    

#endif /* hw2Functions_h */
