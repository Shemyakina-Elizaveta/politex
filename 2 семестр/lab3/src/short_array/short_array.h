#ifndef __short_array_h__
#define __short_array_h__

#include <iostream>

/*
class ShortArray
{
private:
 static constexpr size_t INLINE_CAPACITY = (sizeof(short *) + sizeof(size_t)) / sizeof(short);

  union Storage
  {
    struct
    {
      short *data;
      size_t capacity;
    } heap;
    
    short stack[INLINE_CAPACITY];
  };

  Storage storage;
  size_t length;
  bool is_heap = false;


public:
  ShortArray( void );
  ShortArray( size_t size, short fill_value = 0 );
  ShortArray( const ShortArray &other );
  ShortArray( ShortArray &&other ) noexcept;
  ~ShortArray( void );

  ShortArray & operator=( const ShortArray &other );
  ShortArray & operator=( ShortArray &&other ) noexcept;

  short & operator[]( size_t index );
  const short & operator[]( size_t index ) const;

  void push( short new_val );
  short pop( void );
  size_t size( void ) const;
  void resize( size_t new_size, short fill_value = 0 );

  bool is_heap_storage( void ) const { return is_heap; }
  size_t inline_capacity( void ) const { return INLINE_CAPACITY; }
};
*/

class ShortArray
{
private:
  static constexpr size_t INLINE_CAPACITY = (sizeof(short *) + sizeof(size_t)) / sizeof(short);

  union Storage
  {
    struct
    {
      short *data;
      size_t capacity;
    } heap;
    
    short stack[INLINE_CAPACITY];
  };

  Storage storage;
  short length_is_heap;

  void move_from( ShortArray &&other );

  size_t get_length( void ) const { return static_cast<size_t>(length_is_heap >> 1); }
  bool get_is_heap( void ) const { return length_is_heap & 1; }
  void set_length( size_t len ) { length_is_heap = (len << 1) | (length_is_heap & 1); }
  void set_is_heap( bool heap ) { length_is_heap = (length_is_heap & ~1) | (heap ? 1 : 0); }

public:
  ShortArray( void );
  ShortArray( size_t size, short fill_value = 0 );
  ShortArray( const ShortArray &other );
  ShortArray( ShortArray &&other ) noexcept;
  ~ShortArray( void );

  ShortArray & operator=( const ShortArray& other );
  ShortArray & operator=( ShortArray&& other ) noexcept;

  short & operator[]( size_t index );
  const short & operator[]( size_t index ) const;

  void push( short new_val );
  short pop( void );
  size_t size( void ) const { return get_length(); }
  void resize( size_t new_size, short fill_value = 0 );

  bool is_heap_storage( void ) const { return get_is_heap(); }
  size_t inline_capacity( void ) const { return INLINE_CAPACITY; }
};


#endif /* __short_array_h__ */