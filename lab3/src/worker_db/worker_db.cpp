#include "worker_db.h"


WorkerData::WorkerData( void ) : age(0) {}

WorkerData::WorkerData( const MyString &n, int a ) : name(n), age(a) {}

WorkerDb::WorkerDb( void ) : head(nullptr), count(0) {}

WorkerDb::~WorkerDb( void )
{
  WorkerNode *current = head;
  while (current != nullptr)
  {
    WorkerNode *next = current->next;
    delete current;
    current = next;
  }
}


WorkerData & WorkerDb::operator[]( const MyString &surname )
{
  WorkerNode *current = head;
  while (current != nullptr)
  {
    if (current->key == surname)
      return current->data;
    current = current->next;
  }

  WorkerNode *newNode = new WorkerNode;
  newNode->key = surname;
  newNode->next = head;
  head = newNode;
  count++;
  return newNode->data;
}

const WorkerData & WorkerDb::operator[]( const MyString &surname ) const
{
  WorkerNode *current = head;
  while (current != nullptr)
  {
    if (current->key == surname)
      return current->data;
    current = current->next;
  }
  throw;
}

WorkerDbIterator::WorkerDbIterator( WorkerNode *node ) : current(node) {}

WorkerDbIterator WorkerDb::begin( void )
{
  return WorkerDbIterator(head);
}

WorkerDbIterator WorkerDb::end( void )
{
  return WorkerDbIterator(nullptr);
}



WorkerData & WorkerDbIterator::operator*( void )
{
  return current->data;
}

WorkerData * WorkerDbIterator::operator->( void )
{
  return &current->data;
}

const MyString & WorkerDbIterator::key( void ) const
{
  return current->key;
}

WorkerDbIterator & WorkerDbIterator::operator++( void )
{
  if (current != nullptr)
    current = current->next;
  return *this;
}

WorkerDbIterator WorkerDbIterator::operator++( int )
{
  WorkerDbIterator tmp = *this;
  ++(*this);
  return tmp;
}

bool WorkerDbIterator::operator==( const WorkerDbIterator &other ) const
{
  return current == other.current;
}

bool WorkerDbIterator::operator!=( const WorkerDbIterator &other ) const
{
  return current != other.current;
}


void print_db( WorkerDb &db )
{
  for (auto it = db.begin(); it != db.end(); ++it)
  {
    std::cout << it.key() << ": " 
              << it->name << ", " 
              << it->age << " years\n";
  }
}

double get_avg_age( WorkerDb &db )
{
  if (db.begin() == db.end())
    return 0;

  double total_age = 0;
  int count = 0;

  for (auto it = db.begin(); it != db.end(); ++it)
  {
    total_age += it->age;
    count++;
  }

  return total_age / count;
}