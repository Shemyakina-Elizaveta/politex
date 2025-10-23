#ifndef __worker_db_h__
#define __worker_db_h__

#include "../my_string/my_string.h"

struct WorkerData
{
  MyString name;
  int age;

  WorkerData( void );
  WorkerData( const MyString &n, int a );
};

class WorkerDbIterator;

struct WorkerNode
{
  MyString key;
  WorkerData data;
  WorkerNode *next;
};

class WorkerDb
{
  WorkerNode *head;
  int count;

public:
  WorkerDb( void );
  ~WorkerDb( void );

  WorkerData & operator[]( const MyString &surname );
  const WorkerData & operator[]( const MyString &surname ) const;

  WorkerDbIterator begin( void );
  WorkerDbIterator end( void );

  friend class WorkerDbIterator;
};

class WorkerDbIterator
{
  WorkerNode *current;

public:
  WorkerDbIterator( WorkerNode *node );

  WorkerData & operator*( void );
  WorkerData * operator->( void );
  const MyString & key( void ) const;

  WorkerDbIterator & operator++( void );
  WorkerDbIterator operator++( int );

  bool operator==( const WorkerDbIterator &other ) const;
  bool operator!=( const WorkerDbIterator &other ) const;

  friend class WorkerDb;
};

void print_db( WorkerDb &db );
double get_avg_age( WorkerDb &db );


#endif /* __worker_db_h__ */