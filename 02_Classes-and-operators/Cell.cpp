//
// Created by kay on 23.04.24.
//

#include "Cell.h"

Cell::Cell(int2 position): m_Position(position) {}

int2 Cell::GetPosition() {
    return m_Position;
}
