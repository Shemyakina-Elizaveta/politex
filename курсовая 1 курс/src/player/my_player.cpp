#include "my_player.hpp"
#include <cstdlib>
#include <cstring>

namespace ttt::my_player {

MyPlayer::~MyPlayer( void )
{
  if (m_board != nullptr)
  {
    for (int i = 0; i < m_rows; i++)
      delete[] m_board[i];
    delete[] m_board;
  }
}

void MyPlayer::set_sign( Sign sign )
{ 
  m_sign = sign; 
}

const char *MyPlayer::get_name( void ) const
{ 
  return m_name; 
}

void MyPlayer::initialize_board( const State &state)
{
  if (m_board != nullptr) 
    return;
  
  m_cols = state.get_opts().cols;
  m_rows = state.get_opts().rows;
  
  m_board = new Sign*[m_rows];

  for (int i = 0; i < m_rows; i++)
  {
    m_board[i] = new Sign[m_cols];

    for (int j = 0; j < m_cols; j++)
      m_board[i][j] = Sign::NONE;
  }
}

void MyPlayer::update_board( const State &state)
{
  initialize_board(state);
  
  for (int y = 0; y < m_rows; y++) 
  {
    for (int x = 0; x < m_cols; x++)
    {
      Sign current_state = state.get_value(x, y);
      
      if (m_board[y][x] != current_state)
        m_board[y][x] = current_state;
    }
  }
}

int MyPlayer::check_line( int x, int y, int dx, int dy, Sign sign ) const
{
  int count = 0;
  int max_count = 0;
  
  for (int dir = -1; dir <= 1; dir += 2)
  {
    count = 0;

    for (int i = 1; i <= 4; i++)
    {
      int nx = x + i * dx * dir;
      int ny = y + i * dy * dir;
      
      if (nx < 0 || nx >= m_cols || ny < 0 || ny >= m_rows)
        break;
      if (m_board[ny][nx] == sign)
        count++;
      else if (m_board[ny][nx] == Sign::NONE)
        break;
      else
      {
        count = 0;
        break;
      }
    }
    max_count += count;
  }
  
  return max_count;
}

bool MyPlayer::find_win_move( Point &result, Sign sign ) const
{
  for (int y = 0; y < m_rows; y++)
  {
    for (int x = 0; x < m_cols; x++)
    {
      if (m_board[y][x] != Sign::NONE)
        continue;
      
      int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
      
      for (int d = 0; d < 4; d++)
      {
        int dx = directions[d][0];
        int dy = directions[d][1];
        
        if (check_line(x, y, dx, dy, sign) >= 4)
        {
          result.x = x;
          result.y = y;
          return true;
        }
      }
    }
  }
  return false;
}

bool MyPlayer::find_block_move( Point &result, Sign enemy_sign, int threat_level ) const
{
  for (int y = 0; y < m_rows; y++)
  {
    for (int x = 0; x < m_cols; x++)
    {
      if (m_board[y][x] != Sign::NONE)
        continue;
      
      int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
      
      for (int d = 0; d < 4; d++)
      {
        int dx = directions[d][0];
        int dy = directions[d][1];
        
        int threat = check_line(x, y, dx, dy, enemy_sign);
        
        if (threat >= threat_level)
        {
          result.x = x;
          result.y = y;
          return true;
        }
      }
    }
  }
  return false;
}

bool MyPlayer::find_double_threat( Point &result, Sign sign ) const
{
  for (int y = 0; y < m_rows; y++)
  {
    for (int x = 0; x < m_cols; x++)
    {
      if (m_board[y][x] != Sign::NONE)
        continue;
      
      int threat_count = 0;
      int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
      
      for (int d = 0; d < 4; d++)
      {
        int dx = directions[d][0];
        int dy = directions[d][1];
        
        if (check_line(x, y, dx, dy, sign) >= 2)
        {
          threat_count++;
          
          if (threat_count >= 2)
          {
            result.x = x;
            result.y = y;
            return true;
          }
        }
      }
    }
  }
  return false;
}

bool MyPlayer::find_strategic_move( Point &result, Sign sign ) const
{
  int center_x = m_cols / 2;
  int center_y = m_rows / 2;
  
  for (int radius = 0; radius <= center_x; radius++)
  {
    for (int y = center_y - radius; y <= center_y + radius; y++)
    {
      for (int x = center_x - radius; x <= center_x + radius; x++)
      {
        if (x < 0 || x >= m_cols || y < 0 || y >= m_rows)
          continue;
        if (m_board[y][x] == Sign::NONE)
        {
          for (int dy = -1; dy <= 1; dy++)
          {
            for (int dx = -1; dx <= 1; dx++)
            {
              if (dx == 0 && dy == 0)
                continue;
                
              int nx = x + dx;
              int ny = y + dy;
                
              if (nx < 0 || nx >= m_cols || ny < 0 || ny >= m_rows)
                continue;
              if (m_board[ny][nx] != Sign::NONE)
              {
                result.x = x;
                result.y = y;
                return true;
              }
            }
          }
        }
      }
    }
  }
  return false;
}

bool MyPlayer::find_any_move( Point &result) const
{
  for (int y = 0; y < m_rows; y++)
  {
    for (int x = 0; x < m_cols; x++)
    {
      if (m_board[y][x] == Sign::NONE)
      {
        result.x = x;
        result.y = y;
        return true;
      }
    }
  }
  return false;
}

Point MyPlayer::make_move( const State &state )
{
  Point result;
  
  if (state.get_move_no() == 0)
  {
    result.x = state.get_opts().cols / 2;
    result.y = state.get_opts().rows / 2;
    return result;
  }
  
  update_board(state);
  
  Sign enemy_sign = (m_sign == Sign::X) ? Sign::O : Sign::X;
  
  if (find_win_move(result, m_sign)) return result;           
  if (find_block_move(result, enemy_sign, 4)) return result;  
  if (find_double_threat(result, m_sign)) return result;      
  if (find_block_move(result, enemy_sign, 3)) return result;  
  if (find_strategic_move(result, m_sign)) return result;     
  
  for (int attempt = 0; attempt < 50; attempt++)
  {
    result.x = std::rand() % m_cols;
    result.y = std::rand() % m_rows;
    
    if (m_board[result.y][result.x] == Sign::NONE)
    {
      for (int dy = -1; dy <= 1; dy++)
      {
        for (int dx = -1; dx <= 1; dx++)
        {
          if (dx == 0 && dy == 0)
            continue;
          int nx = result.x + dx;
          int ny = result.y + dy;
          if (nx >= 0 && nx < m_cols && ny >= 0 && ny < m_rows && m_board[ny][nx] != Sign::NONE)
            return result;
        }
      }
    }
  }
  
  if (find_any_move(result))
    return result;
  
  result.x = 0;
  result.y = 0;
  return result;
}

}; // namespace ttt::my_player