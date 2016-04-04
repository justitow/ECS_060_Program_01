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

vector<CursorNode <int> > cursorSpace(500001);

using namespace std;

void NewChoice()
{
  cout << "Your choice is not between 0 and 6.\n" <<"Please try again.\n";
}



void parseCommand(string str, char& command, int& number)
{
  char * charstr = new char [str.length()+1];
  strcpy(charstr, str.c_str());
  command = charstr[0];
  charstr++;
  number = atoi(charstr);
  //cout << command << number << endl;
}

int getChoice()
{
  int choice;
  
  cout << "   ADT Menu\n"
  << "0. Quit\n"
  << "1. LinkedList\n"
  << "2. CursorList\n"
  << "3. StackAr\n"
  << "4. StackLi\n"
  << "5. QueueAr\n"
  << "6. SkipList\n"
  << "Your choice >> ";
  
  cin >> choice;
  //cout << "\n";
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
  CursorList<int> myList(cursorSpace);
  
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
      myList.insert(number, myList.zeroth());
    }
    else
    {
      myList.remove(number);
    }
  }
  
  
}

void RunStackAr(char* filename)
{
  StackAr<int> myList(500001);
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
      myList.push(number);
    }
    else
    {
      while(!myList.isEmpty())
      {myList.pop();}
    }
  }
  
}

void RunStackLi(char* filename)
{
  StackLi<int> myList;
  
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
      myList.push(number);
    }
    else
    {
     while(!myList.isEmpty())
      myList.pop();
    }
  }
  
}

void RunQueueAr(char* filename)
{
  Queue<int> myList(500000);
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
      myList.enqueue(number);
    }
    else
    {
      while(!myList.isEmpty())
      myList.dequeue();
    }
  }
  
}

void RunSkipList(char* filename)
{
  SkipList<int> myList(-1, 500000);
  
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
      myList.insert(number);
    }
    else
    {
      myList.deleteNode(number);
    }
  }
  
}

int main(int argc, char **argv)
{
  int choice;
  string str;
  CPUTimer ct;
  
  
  cout << "File name >> ";
  cin >> str;
  char* filename = new char[str.length() + 1];
  strcpy(filename, str.c_str());
  cout << "\n";

  do
  {
    choice = getChoice();
    ct.reset();
    /*if (choice > 6 || choice < 0)
    { 
      cout << "Your choice is not between 0 and 6.\n" <<"Please try again.\n\n";
      choice = getChoice();
    }*/
    switch (choice)
    {
      case 1: RunList(filename); break;
      case 2: RunCursorList(filename); break;
      case 3: RunStackAr(filename); break;
      case 4: RunStackLi(filename); break;
      case 5: RunQueueAr(filename); break;
      case 6: RunSkipList(filename); break;
      default: cout << "Your choice is not between 0 and 6.\n" <<"Please try again.\n\n"; break;
    }
    
    cout << "CPU time: " << ct.cur_CPUTime() << "\n"<<"\n";

  } while(choice > 0);
    
}