#include "grid.h"
#include <iostream>


MinesweeperGrid::MinesweeperGrid(const unsigned int width, const unsigned int height, float bombsPercentage) : m_Width(
        width), m_Height(height), m_BombsPercentage(bombsPercentage) {
    InitializeCells();
}

void MinesweeperGrid::InitializeCells() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution ran_bomb(m_BombsPercentage);

    m_Values.reserve(m_Width * m_Height);


    for (int w = 0; w < m_Width; ++w) {
        for (int h = 0; h < m_Height; ++h) {
            m_Values.emplace_back(int2(w, h), ran_bomb(gen));
        }
    }

    for (MinesweeperCell &cell: m_Values) {
        cell.m_NeighborBombCount = CalculateNeighboringBombsCount(cell.GetPosition());
    }

}

int MinesweeperGrid::CalculateNeighboringBombsCount(int2 location) {
    unsigned char out = 0;

    for (int x = -1; x < 2; ++x) {
        for (int y = -1; y < 2; ++y) {
            int2 test_location = location + int2(x, y);
            if (!(x == 0 && y == 0) && LocationInBounds(test_location) &&
                m_Values[GetIndexFromLocation(test_location)].IsBomb())
                out++;
        }
    }

    return out;
}

bool MinesweeperGrid::IsBomb(unsigned int index) const {
    return m_Values[index].IsBomb();
}

bool MinesweeperGrid::IsBomb(int2 location) const {
    return IsBomb(GetIndexFromLocation(location));
}

int MinesweeperGrid::GetNeighborBombCount(unsigned int index) const {
    return m_Values[index].m_NeighborBombCount;
}

int MinesweeperGrid::GetNeighborBombCount(int2 location) const {
    return m_Values[GetIndexFromLocation(location)].m_NeighborBombCount;
}

unsigned int MinesweeperGrid::GetIndexFromLocation(int2 location) const {
    if (!LocationInBounds(location)) {
        std::cout << "grid access out of bounds" << std::endl;
        return 0;
    }
    return m_Height * location.x + location.y;
}

int2 MinesweeperGrid::GetLocationFromIndex(unsigned int index) {
    if (!IndexInBounds(index)) {
        std::cout << "grid access out of bounds" << std::endl;
        return {0, 0};
    }
    return m_Values[index].GetPosition();
}

unsigned int MinesweeperGrid::GetWidth() const {
    return m_Width;
}

unsigned int MinesweeperGrid::GetHeight() const {
    return m_Height;
}

bool MinesweeperGrid::IndexInBounds(unsigned int index) const {
    if (index < m_Values.size()) return true;
    return false;
}

bool MinesweeperGrid::LocationInBounds(int2 location) const {
    if (m_Height > location.y && m_Width > location.x && location.x >= 0 && location.y >= 0) return true;
    return false;
}

void MinesweeperGrid::PrintGrid() const {

    std::cout << std::string(m_Width + 2, 'o') << std::endl;

    for (int h = 0; h < m_Height; ++h) {
        std::cout << 'o';
        for (int w = 0; w < m_Width; ++w) {
            MinesweeperCell cell = m_Values[GetIndexFromLocation({w, h})];
            if (cell.IsBomb()) std::cout << 'X';
            else if (cell.m_NeighborBombCount == 0) std::cout << ' ';
            else std::cout << std::to_string(cell.m_NeighborBombCount);
        }
        std::cout << 'o' << std::endl;
    }

    std::cout << std::string(m_Width + 2, 'o') << std::endl;

}