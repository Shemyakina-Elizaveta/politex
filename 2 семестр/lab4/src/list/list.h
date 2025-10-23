#ifndef __list_h__
#define __list_h__

#include <iostream>

#include "../geometry/circle/circle.h"

class List
{
private:

  class Node
  {
    friend class List;
    friend std::ostream & operator<<( std::ostream &os, const List &list );

  private:
    Node *prev, *next;
    Circle data;

  public:

    Node( void );
    Node( Node *nprev, Node *nnext, const Circle &ndata );
    ~Node( void );
  };

  Node *head;
  Node *tail;
  int length;

public:

  List( void );
  ~List( void );

  List( const List &nlist );
  List( List &&nlist ) noexcept;

  List & operator=( const List &nlist );
  List & operator=( List &&nlist ) noexcept;
  // TODO: ~List();
  // TODO: List(const List&), List(List&&), operator=

  int get_length( void );

  void push_front( const Circle &ndata );
  void push_back( const Circle &ndata );

  Circle pop_front( void );
  Circle pop_back( void );

  bool remove_first( const Circle &data );
  int remove_all( const Circle &data );

  void clear( void );

  void sort_by_area( void );

  void save_to_file( const char *filename );
  void load_from_file( const char *filename );

  friend std::ostream & operator<<( std::ostream &os, const List &list );
};

std::ostream & operator<<( std::ostream &os, const List &list );


#endif /* __list_h__ */
