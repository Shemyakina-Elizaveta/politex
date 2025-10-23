#include "player/my_player.hpp"
#include "core/baseline.hpp"
#include "test_stats.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    std::cout << "Testing MyPlayer vs baseline player\n";
    if (argc >= 2) {
        std::srand(atoi(argv[1]));
    }

    
    ttt::my_player::MyPlayer p1("MyPlayer"); ////поместите вашего игрока сюда
    ttt::my_player::MyPlayer p2("MyPlayer"); ////поместите вашего игрока сюда
    
    // ttt::game::IPlayer *p2 = ttt::baseline::get_easy_player("BaselineEasy"); //здесь вы можете выбрать между базовыми игроками: сложным и лёгким
    
    // auto result = ttt::test::run_game_tests(p1, *p2, 1000); //здесь вы можете изменить количество тестовых итераций ~~ 100
    // auto result = ttt::test::run_game_tests(*p2, p1, 1000); //здесь вы можете изменить количество тестовых итераций ~~ 100
    auto result = ttt::test::run_game_tests(p2, p1, 1000); //здесь вы можете изменить количество тестовых итераций ~~ 100
    
    ttt::test::print_test_results(result, "MyPlayer", "MyPlayer");
    
    // ttt::test::print_test_results(result, "MyPlayer", "BaselineEasy");
    // ttt::test::print_test_results(result, "BaselineEasy", "MyPlayer");
    
    
    // delete p2;
    return 0;
}