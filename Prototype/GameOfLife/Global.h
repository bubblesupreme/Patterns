#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>

typedef  std::pair<int, int> Position;
typedef  std::pair<size_t, size_t> Size;
const size_t BOOTH_SIZE = 20;
const Size GRID_SIZE(40, 30);
enum State { UPDATE, MODIFY, COME_BACK, PAUSE };
const bool GAME_WITH_GENE = true;

#endif