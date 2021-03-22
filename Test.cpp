/**
 * Unit tests for message board exercise
 * AUTHOR: Mayan Bashan
 * Date: 2021-03
 */

#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
using namespace std;

TEST_CASE("Good Tests"){
    ariel::Board board;
    CHECK("_____" == board.read(1,1,Direction::Horizontal,5));
    board.post(1,1,Direction::Horizontal,"hello");
    CHECK("hello" == board.read(1,1,Direction::Horizontal,5));
    CHECK("h____" == board.read(1,1,Direction::Vertical,5));
    CHECK("l____" == board.read(1,3,Direction::Vertical,5));
    board.post(1,3,Direction::Horizontal,"bye");
    CHECK("hebye" == board.read(1,1,Direction::Horizontal,5));
    board.post(0,2,Direction::Horizontal,"l");
    board.post(2,2,Direction::Vertical,"t's go");
    CHECK("let's go" == board.read(0,2,Direction::Vertical,8));

    CHECK("__________" == board.read(0,0,Direction::Vertical,10));
    CHECK("s g" == board.read(4,2,Direction::Vertical,3));
    CHECK("_g_" == board.read(6,1,Direction::Horizontal,3));
    CHECK("__ ___" == board.read(5,0,Direction::Horizontal,6));

    board.post(2,3,Direction::Vertical,"ice cream");
    CHECK("ice cream_" == board.read(2,3,Direction::Vertical,10));
    CHECK("gc__" == board.read(6,2,Direction::Horizontal,4));
    CHECK("__  __" == board.read(5,0,Direction::Horizontal,6));
    board.post(5,1, Direction::Horizontal, "abcd");
    CHECK("_abcd_" == board.read(5,0,Direction::Horizontal,6));
    board.post(5,1, Direction::Horizontal, "wxyz ");
    CHECK("_wxyz " == board.read(5,0,Direction::Horizontal,6));
    

}

TEST_CASE("Cases that should not occur"){
    ariel::Board board;
    CHECK_FALSE("  " == board.read(4,3,Direction::Horizontal,2));
    board.post(0,0,Direction::Horizontal,"he");
    board.post(1,3,Direction::Horizontal,"lo");
    CHECK_FALSE("he lo" == board.read(0,0,Direction::Horizontal,5));
    board.post(0,0,Direction::Horizontal,"he lo");
    CHECK_FALSE("he_lo" == board.read(0,0,Direction::Horizontal,5));
    board.post(0,0,Direction::Horizontal,"world");
    CHECK_FALSE("he lo" == board.read(0,0,Direction::Horizontal,5));
    CHECK_FALSE("w " == board.read(0,0,Direction::Vertical,2));
    
}