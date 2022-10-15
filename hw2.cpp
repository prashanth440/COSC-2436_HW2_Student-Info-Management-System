#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "hw2Functions.h"
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        return -1;
    }
    
    ArgumentManager am(argc, argv);
    string inFileName = am.get("input");
    string sortFileName = am.get("sort");
    string outFileName = am.get("output");
    
    ifstream fileInput, sortFile;
    string line, sortCommand;
    vector<string> deleteID;
    int start, end, numRecords;
    numRecords = 0;
    record *data = new record;
    record *head = data;
    
    fileInput.open(inFileName);
    sortFile.open(sortFileName);
    //fileInput.open("/Users/saiprashanthharihar/Desktop/hw2-late/input29.txt");
    //sortFile.open("/Users/saiprashanthharihar/Desktop/hw2-late/sort29.txt");
    
    while(!fileInput.eof())
    {
        line = "";
        getline(fileInput, line);
        if(line != "" && line != "\r" && line != "\n" && line.find("delete") == 0)
        {
            start = (int) line.find("delete ") + 7;
            deleteID.push_back(line.substr(start, (int) line.length() - start - 1));
        }
        else if(line != "" && line != "\r" && line != "\n")
        {
            start = (int) line.find("id:") + 3;
            end = (int) line.find(",first");
            data->ID = line.substr(start, end - start);
            
            start = (int) line.find(",first:") + 7;
            end = (int) line.find(",last");
            data->firstName = line.substr(start, end - start);
            
            start = (int) line.find(",last:") + 6;
            end = (int) line.find(",DOB");
            data->lastName =  line.substr(start, end - start);
            
            start = (int) line.find(",DOB:") + 5;
            end = (int) line.find(",GPA");
            data->DOB = line.substr(start, end - start);
            
            start = (int) line.find(",GPA:") + 5;
            end = (int) line.find("}");
            data->GPA = line.substr(start, end - start);
            
            data->next = new record;
            data = data->next;
            numRecords++;
        }
    }
    data->next = nullptr;
    
    bubbleSortLinkedList(&head, numRecords, "id");
    //printLinkedList(head, "");
    
    while(!sortFile.eof())
    {
        sortCommand = "";
        getline(sortFile, sortCommand);
        if(sortCommand != "" && sortCommand != "\n" && sortCommand != "\r")
        {
            bubbleSortLinkedList(&head, numRecords, sortCommand);
        }
    }
    
    for(int i = 0; i < (int) deleteID.size(); i++)
    {
        deleteRecord(&head, deleteID[i]);
    }
    record *Head = removeDuplicate(head);
    //printLinkedList(Head, "");
    
    printLinkedList(Head, outFileName);
    
    fileInput.close();
    sortFile.close();
}
