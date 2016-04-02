#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "CursorList.h"
#include "LinkedList.h"
#include "QueueAr.h"
#include "SkipList.h"
#include "StackAr.h"
#include "StackLi.h"
#include "vector.h"
#include "CPUTimer.h"

vector<CursorNode <int> > cursorSpace(250000);

using namespace std;

void parseCommand(string str, char& command, int& number)
{
  char * cstr = new char [str.length()+1];
  strcpy(cstr, str.c_str());
  command = cstr[0];
  cstr++;
  number = atoi(cstr);
  //cout << command << number << endl;
}

int getChoice()
{
  int choice;
  
  cout << "ADT Menu \n"
  << "0. Quit\n"
  << "1. LinkedList\n"
  << "2. CursorList\n"
  << "3. StackAr\n"
  << "4. StackLi\n"
  << "5. QueueAr\n"
  << "6. SkipList\n"
  << "Your choice >> ";
  
  cin >> choice;
  cout << "\n";
  return choice;
}

void RunList(char* filename)
{
  List<int> myList;
  
  ifstream inf;
  inf.open(filename);
  string str;
  char command;
  int number;
  
  while(inf >> str)
  {
    parseCommand(str, command, number);
    //cout << command << " " << number << endl;
    if (command == 'i')
    {
      myList.insert(number, myList.zeroth());
    }
    else
    {
      myList.remove(number);
    }
  }
  
}



void RunCursorList(char* filename)
{
  ifstream inf;
  inf.open(filename);
  string str;
  char command;
  int number;
  
  while(inf >> str)
  {
    parseCommand(str, command, number);
    if (command == 'i')
    {
    }
    else
    {
    }
  }
  
  
}

void RunStackAr(char* filename)
{
  ifstream inf;
  inf.open(filename);
  string str;
  char command;
  int number;
  
  while(inf >> str)
  {
    parseCommand(str, command, number);
    if (command == 'i')
    {
    }
    else
    {
    }
  }
  
}

void RunStackLi(char* filename)
{
  ifstream inf;
  inf.open(filename);
  string str;
  char command;
  int number;
  
  while(inf >> str)
  {
    parseCommand(str, command, number);
    if (command == 'i')
    {
    }
    else
    {
    }
  }
  
}

void RunQueueAr(char* filename)
{
  ifstream inf;
  inf.open(filename);
  string str;
  char command;
  int number;
  
  while(inf >> str)
  {
    parseCommand(str, command, number);
    if (command == 'i')
    {
    }
    else
    {
    }
  }
  
}

void RunSkipList(char* filename)
{
  ifstream inf;
  inf.open(filename);
  string str;
  char command;
  int number;
  
  while(inf >> str)
  {
    parseCommand(str, command, number);
    if (command == 'i')
    {
    }
    else
    {
    }
  }
  
}


int main(int argc, char **argv)
{
  int choice;
  char* filename = new char[1000];
  CPUTimer ct;
  
  
  cout << "File name >> ";
  cin >> filename;
  cout << "\n";

  do
  {
    choice = getChoice();
    ct.reset();

    switch (choice)
    {
      case 1: RunList(filename); break;
      case 2: RunCursorList(filename); break;
      case 3: RunStackAr(filename); break;
      case 4: RunStackLi(filename); break;
      case 5: RunQueueAr(filename); break;
      case 6: RunSkipList(filename); break;
    }
      
    cout << "CPU time: " << ct.cur_CPUTime() << endl;

  } while(choice > 0);
    
}