#include <iostream>
#include <fstream>

#include "list.h"

List::Node::Node( void ) : prev(nullptr), next(nullptr), data() {}

List::Node::Node( Node *nprev, Node *nnext, const Circle &ndata ) : prev(nprev), next(nnext), data(ndata) {}

List::Node::~Node( void )
{
  if (prev != nullptr)
    prev->next = next;

  if (next != nullptr)
    next->prev = prev;
}

List::List( void ) : head(nullptr), tail(nullptr), length(0) {}


List::~List( void )
{
  clear();
}

List::List( const List &nlist ) : head(nullptr), tail(nullptr) ,length(0)
{
  Node *current = nlist.head;

  while (current != nullptr) 
  {
    push_back(current->data);
    current = current->next;
  }
}

List::List( List &&nlist ) noexcept : head(nlist.head), tail(nlist.tail), length(nlist.length)
{
  nlist.head = nullptr;
  nlist.tail = nullptr;
  nlist.length = 0; 
}


List & List::operator=( const List &nlist )
{
  if (this != &nlist)
  {
    clear();

    Node *current = nlist.head;
    
    while (current != nullptr)
    {
      push_back(current->data);
      current = current->next;
    }
  }

  return *this;
}

List & List::operator=( List &&nlist ) noexcept
{
  if (this != &nlist)
  {
    clear();
    head = nlist.head;
    tail = nlist.tail;
    length = nlist.length;

    nlist.head = nullptr;
    nlist.tail = nullptr;
    nlist.length = 0;
  }

  return *this;
}

int List::get_length( void )
{
  return length;
}

void List::push_front( const Circle &ndata )
{
  Node *nnode = new Node(nullptr, head, ndata);

  if (head != nullptr)
    head->prev = nnode;
  else
    tail = nnode;

  head = nnode;
  length++;
}

void List::push_back( const Circle &ndata )
{
  Node *nnode = new Node(tail, nullptr, ndata);

  if (tail != nullptr)
    tail->next = nnode;
  else
    head = nnode;

  tail = nnode;
  length++;
}
     
Circle List::pop_front( void )
{
  if (head == nullptr)
    throw;

  Circle data = head->data;
  Node *del = head;

  head = head->next;

  if (head != nullptr)
    head->prev = nullptr;
  else
    tail = nullptr;

  delete del;
  length--;

  return data;
}

Circle List::pop_back( void )
{
  if (tail == nullptr)
    throw;

  Circle res = tail->data;
  Node *del = tail;

  tail = tail->prev;

  if (tail != nullptr)
    tail->next = nullptr;
  else
    head = nullptr;

  delete del;
  length--;

  return res;
}


bool List::remove_first( const Circle &data )
{
  Node *current = head;

  while (current != nullptr)
  {
    if (current->data == data)
    {
      if (current->prev != nullptr)
        current->prev->next = current->next;
      else
        head = current->next;

      if (current->next != nullptr)
        current->next->prev = current->prev;
      else
        tail = current->prev;

      delete current;
      length--;

      return true;
    }

    current = current->next;
  }

  return false;
}


int List::remove_all( const Circle &data )
{
  int cnt = 0;
  Node *current = head;

  while (remove_first(data))
    cnt++;

  return cnt;
}

void List::clear( void )
{
  while (head != nullptr)
  {
    Node *tmp = head;

    head = head->next;
    delete tmp;
  }

  head = nullptr;
  tail = nullptr;
  length = 0;
}

void List::sort_by_area( void )
{
  if (length < 2)
    return;

  bool flag = 0;

  do
  {
    Node *current = head; 
    
    flag = 0;

    while (current->next != nullptr)
    {
      if (current->data.get_area() > current->next->data.get_area())
      {
        Circle tmp = current->data;
        
        current->data = current->next->data;
        current->next->data = tmp;
        flag = true;
      }

      current = current->next;
    }
  } while (flag);
}


std::ostream & operator<<( std::ostream &os, const List &list )
{
  List::Node *current = list.head;
  
  while (current)
  {
    current->data.print(os);       // TODO: передать объект ostream
    os << "\n";
    current = current->next;
  }

  return os;
}
    
void List::save_to_file( const char *filename )
{
  std::ofstream fout(filename);

  if (!fout)
    throw;
  
  Node *current = head;

  while (current)
  {
    const Circle& c = current->data;

    fout << c.get_pos().get_x() << " " 
         << c.get_pos().get_y() << " " 
         << c.get_radius() << "\n";
    current = current->next;
  }
  fout.close();
}

void List::load_from_file( const char *filename )
{
  std::ifstream fin(filename);

  if (!fin)
    throw;
  
  clear();

  double x, y, r;
  while (fin >> x >> y >> r)
    push_back(Circle(x, y, r));

  fin.close();
}