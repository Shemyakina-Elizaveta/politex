#include "other.h"

size_t inc_by_value( size_t val )
{
  return val + 1;
}

size_t inc_by_posize_ter( size_t *val )
{
  *val += 1;

  return *val;
}

size_t inc_by_reference( size_t &val )
{
  val++;

  return val;
}

void swap( size_t *x, size_t *y )
{
  size_t tmp = *x;

  *x = *y;
  *y = tmp;
}

void swap( size_t &x, size_t &y )
{
  size_t tmp = x;

  x = y;
  y = tmp;
}

size_t find_min( const size_t *A, const size_t N )
{
  size_t mi = A[0];

  for (size_t i = 0; i < N; i++)
    mi = std::min(mi, A[i]);
  return mi;
}

size_t find_min( const size_t * const *A, const size_t N, const size_t M )
{
  size_t mi = A[0][0];

  for (size_t i = 0; i < N; i++)
    mi = std::min(mi, find_min(A[i], M));

  return mi;
}

size_t my_str_cmp( const char *str1, const char *str2 )   // TODO: добавьте константность
{
  while (*str1 != '\0' && *str2 != '\0')
  {
    if (*str1 < *str2)
      return -1;
    else if (*str1 > *str2)
      return 1;

    str1++;
    str2++;
  }

  if (*str1 == '\0' && *str2 != '\0')
    return -1;
  else if (*str1 != '\0' && *str2 == '\0')
    return 1;

  return 0;
}

size_t day_of_year( size_t day, size_t month, size_t year, size_t (* MIY)[12] )
{
  size_t res = 0, flag = 0;

  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    flag = 1;

  for (size_t i = 0; i < month - 1; i++)
    res += MIY[flag][i];
  res += day;

  return res;
}

size_t day_of_month( size_t day, size_t year, size_t &month, size_t (* MIY)[12] )
{
  size_t res_day = day, res_month = 0, flag = 0;

  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    flag = 1;

  while (res_day > MIY[flag][res_month])
    res_day -= MIY[flag][res_month++];

  month = res_month + 1;

  return res_day;
}

void add_unique( size_t * &ar, size_t &n, size_t new_value )
{
  for (size_t i = 0; i < n; i++)
    if (new_value == ar[i])
       return;

  size_t *new_ar;

  n++;
  new_ar = new size_t [n];

  for (size_t i = 0; i < n - 1; i++)
    new_ar[i] = ar[i];

  new_ar[n - 1] = new_value;

  delete[] ar;
  ar = new_ar;
}

// тип_вовзращаемого_значения название_функции( параметры функции )
// size_t / char / double / float / void / char * / size_t * / size_t ** / ....

void prsize_t_array( const size_t *ar, const size_t n )       // TODO: const
{
  for (size_t i = 0; i < n; i++)
    std::cout << ar[i] << ' ';
  std::cout << '\n';
}

size_t sum_size_t( size_t N )
{
  if (N == 0)
    return 0;
  if (N == 1)
    return 1;

  return N + sum_size_t(N - 1);
}


// TODO: сделать для восьмибитных байтов
size_t encoded32_size( size_t raw_size )
{
  if (raw_size <= 0)
    return 0;
  return (raw_size * 8 + 4) / 5;
}

size_t decoded32_size( size_t encode_size )
{
  // TODO: сделать округление вверх без дробных чисел
  if (encode_size <= 0)
    return 0;
  return (encode_size * 5) / 8;
}

size_t encode32( const char *raw_data, size_t raw_size, char *dst )
{
  if (raw_data == nullptr || raw_size == 0 || dst == nullptr)
    return 1;

  const char table[33] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456";
  size_t buf = 0, bs = 0, ds = 0;

  for (size_t i = 0; i < raw_size; i++)
  {
    buf = (buf << 8) | (unsigned char)raw_data[i];
    bs += 8;

    while (bs >= 5)
    {
      dst[ds++] = table[(buf >> (bs - 5)) & 0x1f];
      bs -= 5;
    }
  }

  if (bs > 0)
    dst[ds++] = table[(buf << (5 - bs)) & 0x1f];

  return 0;
}

size_t decode32( const char *encoded_data, size_t encoded_size, char *dst )
{
  if (encoded_data == nullptr || encoded_size == 0 || dst == 0)
    return 1;

  const char table[33] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456";
  size_t buf = 0, bs = 0, ds = 0;

  for (size_t i = 0; i < encoded_size; i++)
  {
    const char *ptr = strchr(table, encoded_data[i]);

    if (ptr == nullptr)
      return 2;

    size_t index = (size_t)(ptr - table);

    buf = (buf << 5) | index;
    bs += 5;

    if (bs >= 8)
    {
      dst[ds++] = (buf >> (bs - 8)) & 0xFF;
      bs -= 8;
    }
  }

  return 0;
}

void var_args( size_t n1, ... )
{
  va_list arg;
  size_t cnt = 0, x;

  va_start(arg, n1);

  if (n1 == 0)
    return;

  std::cout << n1 << ' ';
  cnt++;

  while ((x = va_arg(arg, size_t)) != 0)
  {
    std::cout << x << ' ';
    cnt++;
  }

  std::cout << "\nArguments count: " << cnt << "\n\n";
  va_end(arg);
  // TODO: вызвать va_end
}

size_t *my_min( size_t *ar, size_t size )
{
  size_t *min = &ar[0];

  for (size_t i = 1; i < size; i++)
    if (*min > ar[i])
      min = &ar[i];

  return min;
}