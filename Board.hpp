/**
 * Author: Mayan Bashan
 */

#pragma once
#include <string>
using namespace std;
#include "Direction.hpp"

namespace ariel{
    class Board{
        public:
            void post(const unsigned row, const unsigned col, ariel::Direction dir, const string &str);
            static string read(const unsigned row, const unsigned col,ariel::Direction dir, const unsigned len);
            void show();
    };
}