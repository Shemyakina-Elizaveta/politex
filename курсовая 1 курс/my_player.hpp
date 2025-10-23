#pragma once

#include "core/game.hpp"

namespace ttt::my_player {

using game::Event;
using game::IPlayer;
using game::Point;
using game::Sign;
using game::State;

class MyPlayer : public IPlayer {
  Sign m_sign = Sign::NONE;
  const char *m_name;
  
  // Представление игрового поля
  Sign** m_board = nullptr;
  int m_cols = 0;
  int m_rows = 0;

public:
  MyPlayer(const char *name) : m_sign(Sign::NONE), m_name(name) {}
  ~MyPlayer();
  
  void set_sign(Sign sign) override;
  Point make_move(const State &game) override;
  const char *get_name() const override;

private:
  // Вспомогательные методы
  void initialize_board(const State& state);
  void update_board(const State& state);
  
  int check_line(int x, int y, int dx, int dy, Sign sign) const;
  bool find_win_move(Point& result, Sign sign) const;
  bool find_block_move(Point& result, Sign enemy_sign, int threat_level) const;
  bool find_double_threat(Point& result, Sign sign) const;
  bool find_strategic_move(Point& result, Sign sign) const;
  bool find_any_move(Point& result) const;
};

}; // namespace ttt::my_player