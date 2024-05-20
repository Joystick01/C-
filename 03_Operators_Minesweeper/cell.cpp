#include "cell.h"

MinesweeperCell::MinesweeperCell(int2 position, bool isBomb) : m_Position(position), m_IsBomb(isBomb) {}

MinesweeperCell::MinesweeperCell() : m_Position({0, 0}) {}

int2 MinesweeperCell::GetPosition() {
    return m_Position;
}

bool MinesweeperCell::IsBomb() const {
    return m_IsBomb;
}
