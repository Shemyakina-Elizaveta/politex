#include "short_array.h"

/*
ShortArray::ShortArray( void ) : is_heap(false)
{
  storage.heap.data = nullptr;
  storage.heap.capacity = 0;
  length = 0;
}

ShortArray::ShortArray( size_t size, short fill_value )
{
  if (size <= INLINE_CAPACITY)
  {
    is_heap = false;
    length = size;
    for (size_t i = 0; i < size; i++)
      storage.stack[i] = fill_value;
  }
  else
  {
    is_heap = true;
    storage.heap.capacity = size + 1;
    storage.heap.data = new short[storage.heap.capacity];
    length = size;
    for (size_t i = 0; i < size; i++)
      storage.heap.data[i] = fill_value;
  }
}

ShortArray::ShortArray( const ShortArray &other )
{
  if (other.is_heap)
  {
    is_heap = true;
    storage.heap.data = new short[other.storage.heap.capacity];
    storage.heap.capacity = other.storage.heap.capacity;
    length = other.length;
    for (size_t i = 0; i < other.length; i++)
      storage.heap.data[i] = other.storage.heap.data[i];
  }
  else
  {
    is_heap = false;
    storage.heap.capacity = 0;
    storage.heap.data = nullptr;
    length = other.length;
    for (size_t i = 0; i < other.length; i++)
      storage.stack[i] = other.storage.stack[i];
  }
}

ShortArray::ShortArray( ShortArray &&other ) noexcept
{
  if (other.is_heap)
  {
    is_heap = true;
    storage.heap.data = other.storage.heap.data;
    storage.heap.capacity = other.storage.heap.capacity;
    length = other.length;
    
    other.storage.heap.data = nullptr;
    other.storage.heap.capacity = 0;
    other.length = 0;
    other.is_heap = false;
  }
  else
  {
    is_heap = false;
    storage.heap.capacity = 0;
    storage.heap.data = nullptr;
    length = other.length;
    for (size_t i = 0; i < other.length; i++)
      storage.stack[i] = other.storage.stack[i];
    
    other.length = 0;
  }
}

ShortArray::~ShortArray( void )
{
  if (is_heap && storage.heap.data != nullptr)
    delete[] storage.heap.data;
}

ShortArray & ShortArray::operator=( const ShortArray &other )
{
  if (this != &other)
  {
    if (is_heap && storage.heap.data != nullptr)
      delete[] storage.heap.data;

    if (other.is_heap)
    {
      is_heap = true;
      storage.heap.data = new short[other.storage.heap.capacity];
      storage.heap.capacity = other.storage.heap.capacity;
      length = other.length;
      for (size_t i = 0; i < other.length; i++)
        storage.heap.data[i] = other.storage.heap.data[i];
    }
    else
    {
      is_heap = false;
      storage.heap.capacity = 0;
      storage.heap.data = nullptr;
      length = other.length;
      for (size_t i = 0; i < other.length; i++)
        storage.stack[i] = other.storage.stack[i];
    }
  }

  return *this;
}

ShortArray & ShortArray::operator=( ShortArray &&other ) noexcept
{
  if (this != &other)
  {
    if (is_heap && storage.heap.data != nullptr)
      delete[] storage.heap.data;

    if (other.is_heap)
    {
      is_heap = true;
      storage.heap.data = other.storage.heap.data;
      storage.heap.capacity = other.storage.heap.capacity;
      length = other.length;
    
      other.storage.heap.data = nullptr;
      other.storage.heap.capacity = 0;
      other.length = 0;
      other.is_heap = false;
    }
    else
    {
      is_heap = false;
      storage.heap.capacity = 0;
      storage.heap.data = nullptr;
      length = other.length;
      for (size_t i = 0; i < other.length; i++)
        storage.stack[i] = other.storage.stack[i];
    
      other.length = 0;
    }
  }

  return *this;
}

short & ShortArray::operator[]( size_t index )
{
  if (index >= length)
    throw;

  return is_heap ? storage.heap.data[index] : storage.stack[index];
}

const short & ShortArray::operator[]( size_t index ) const
{
  if (index >= length)
    throw;

  return is_heap ? storage.heap.data[index] : storage.stack[index];
}

void ShortArray::push( short new_val )
{
  if (length >= (is_heap ? storage.heap.capacity : INLINE_CAPACITY))
  {
    size_t new_capacity = (is_heap ? storage.heap.capacity * 2 : INLINE_CAPACITY * 2);
    short *new_data = new short[new_capacity];

    if (is_heap)
    {
      for (size_t i = 0; i < length; i++)
        new_data[i] = storage.heap.data[i];
      delete[] storage.heap.data;
    }
    else
    {
      for (size_t i = 0; i < length; i++)
        new_data[i] = storage.stack[i];
    }

    is_heap = true;
    storage.heap.data = new_data;
    storage.heap.capacity = new_capacity;
  }

  if (is_heap)
    storage.heap.data[length++] = new_val;
  else
    storage.stack[length++] = new_val;
}

short ShortArray::pop( void )
{
  if (length == 0)
    throw;

  return is_heap ? storage.heap.data[--length] 
                 : storage.stack[--length];
}

size_t ShortArray::size( void ) const
{
  return length;
}

void ShortArray::resize( size_t new_size, short fill_value )
{
  if (new_size > (is_heap ? storage.heap.capacity : INLINE_CAPACITY))
  {
    size_t new_capacity = new_size;
    short *new_data = new short[new_capacity];

    if (is_heap)
    {
      for (size_t i = 0; i < length; i++)
        new_data[i] = storage.heap.data[i];
      delete[] storage.heap.data;
    }
    else
    {
      for (size_t i = 0; i < length; i++)
        new_data[i] = storage.stack[i];
    }

    is_heap = true;
    storage.heap.data = new_data;
    storage.heap.capacity = new_capacity;
  }

  if (new_size > length)
  {
    if (is_heap)
    {
      for (size_t i = length; i < new_size; i++)
        storage.heap.data[i] = fill_value;
    }
    else
    {
      for (size_t i = length; i < new_size; i++)
        storage.stack[i] = fill_value;
    }
  }

  length = new_size;
}

*/



ShortArray::ShortArray( void )
{
  storage.heap.data = nullptr;
  storage.heap.capacity = 0;
  length_is_heap = 0;  // length = 0, is_heap = false
}

ShortArray::ShortArray( size_t size, short fill_value )
{
  if (size <= INLINE_CAPACITY)
  {
    set_is_heap(false);
    set_length(size);
    for (size_t i = 0; i < size; i++)
      storage.stack[i] = fill_value;
  }
  else
  {
    set_is_heap(true);
    storage.heap.capacity = size + 1;
    storage.heap.data = new short[storage.heap.capacity];
    set_length(size);
    for (size_t i = 0; i < size; i++)
      storage.heap.data[i] = fill_value;
  }
}

ShortArray::ShortArray( const ShortArray &other )
{
  if (other.get_is_heap())
  {
    set_is_heap(true);
    storage.heap.data = new short[other.storage.heap.capacity];
    storage.heap.capacity = other.storage.heap.capacity;
    set_length(other.get_length());
    for (size_t i = 0; i < other.get_length(); i++)
      storage.heap.data[i] = other.storage.heap.data[i];
  }
  else
  {
    set_is_heap(false);
    storage.heap.capacity = 0;
    storage.heap.data = nullptr;
    set_length(other.get_length());
    for (size_t i = 0; i < other.get_length(); i++)
      storage.stack[i] = other.storage.stack[i];
  }
}

ShortArray::ShortArray( ShortArray&& other ) noexcept
{
  if (other.get_is_heap())
  {
    set_is_heap(true);
    storage.heap.data = other.storage.heap.data;
    storage.heap.capacity = other.storage.heap.capacity;
    set_length(other.get_length());
    
    other.storage.heap.data = nullptr;
    other.storage.heap.capacity = 0;
    other.set_length(0);
    other.set_is_heap(false);
  }
  else
  {
    set_is_heap(false);
    storage.heap.capacity = 0;
    storage.heap.data = nullptr;
    set_length(other.get_length());
    for (size_t i = 0; i < other.get_length(); i++)
      storage.stack[i] = other.storage.stack[i];
    
    other.set_length(0);
  }
}

ShortArray::~ShortArray( void )
{
  if (get_is_heap() && storage.heap.data != nullptr)
    delete[] storage.heap.data;
}

ShortArray & ShortArray::operator=( const ShortArray &other )
{
  if (this != &other)
  {
    if (get_is_heap() && storage.heap.data != nullptr)
      delete[] storage.heap.data;

    if (other.get_is_heap())
    {
      set_is_heap(true);
      storage.heap.data = new short[other.storage.heap.capacity];
      storage.heap.capacity = other.storage.heap.capacity;
      set_length(other.get_length());
      for (size_t i = 0; i < other.get_length(); i++)
        storage.heap.data[i] = other.storage.heap.data[i];
    }
    else
    {
      set_is_heap(false);
      storage.heap.capacity = 0;
      storage.heap.data = nullptr;
      set_length(other.get_length());
      for (size_t i = 0; i < other.get_length(); i++)
        storage.stack[i] = other.storage.stack[i];
    }
  }

  return *this;
}

ShortArray & ShortArray::operator=(ShortArray &&other) noexcept
{
  if (this != &other)
  {
    if (get_is_heap() && storage.heap.data != nullptr)
      delete[] storage.heap.data;

    if (other.get_is_heap())
    {
      set_is_heap(true);
      storage.heap.data = other.storage.heap.data;
      storage.heap.capacity = other.storage.heap.capacity;
      set_length(other.get_length());
    
      other.storage.heap.data = nullptr;
      other.storage.heap.capacity = 0;
      other.set_length(0);
      other.set_is_heap(false);
    }
    else
    {
      set_is_heap(false);
      storage.heap.capacity = 0;
      storage.heap.data = nullptr;
      set_length(other.get_length());
      for (size_t i = 0; i < other.get_length(); i++)
        storage.stack[i] = other.storage.stack[i];
    
      other.set_length(0);
    }
  }

  return *this;
}

short & ShortArray::operator[]( size_t index )
{
  if (index >= get_length())
    throw;

  return get_is_heap() ? storage.heap.data[index] : storage.stack[index];
}

const short & ShortArray::operator[]( size_t index ) const
{
  if (index >= get_length())
    throw;

  return get_is_heap() ? storage.heap.data[index] : storage.stack[index];
}

void ShortArray::push( short new_val )
{
  size_t len = get_length();
  bool heap = get_is_heap();

  if (len >= (heap ? storage.heap.capacity : INLINE_CAPACITY))
  {
    size_t new_capacity = (heap ? storage.heap.capacity * 2 : INLINE_CAPACITY * 2);
    short *new_data = new short[new_capacity];

    if (heap)
    {
      for (size_t i = 0; i < len; i++)
        new_data[i] = storage.heap.data[i];
      delete[] storage.heap.data;
    }
    else
    {
      for (size_t i = 0; i < len; i++)
        new_data[i] = storage.stack[i];
    }

    set_is_heap(true);
    storage.heap.data = new_data;
    storage.heap.capacity = new_capacity;
  }

  if (get_is_heap())
    storage.heap.data[len] = new_val;
  else
    storage.stack[len] = new_val;

  set_length(len + 1);
}

short ShortArray::pop( void )
{
  if (get_length() == 0)
    throw;

  size_t new_len = get_length() - 1;
  
  set_length(new_len);

  return get_is_heap() ? storage.heap.data[new_len] 
                       : storage.stack[new_len];
}

void ShortArray::resize( size_t new_size, short fill_value )
{
  bool heap = get_is_heap();
  size_t old_len = get_length();

  if (new_size > (heap ? storage.heap.capacity : INLINE_CAPACITY))
  {
    size_t new_capacity = new_size;
    short* new_data = new short[new_capacity];

    if (heap)
    {
      for (size_t i = 0; i < old_len; i++)
        new_data[i] = storage.heap.data[i];
      delete[] storage.heap.data;
    }
    else
    {
      for (size_t i = 0; i < old_len; i++)
        new_data[i] = storage.stack[i];
    }

    set_is_heap(true);
    storage.heap.data = new_data;
    storage.heap.capacity = new_capacity;
  }

  if (new_size > old_len)
  {
    if (get_is_heap())
    {
      for (size_t i = old_len; i < new_size; i++)
        storage.heap.data[i] = fill_value;
    }
    else
    {
      for (size_t i = old_len; i < new_size; i++)
        storage.stack[i] = fill_value;
    }
  }

  set_length(new_size);
}
