//
// Created by kay on 23.04.24.
//

#include "Grid.h"
#include "iostream"

Grid::Grid(unsigned int width, unsigned int height): m_Width(width), m_Height(height) {
    InitializeCells();
};

void Grid::InitializeCells() {

    m_Values.reserve(m_Height*m_Width);

    for (int h = 0; h < m_Height; ++h) {
        for (int w = 0; w < m_Width; ++w) {
            m_Values.emplace_back(int2(h, w));
        }
    }

}

unsigned int Grid::GetWidth() {
    return m_Width;
}

unsigned int Grid::GetHeight() {
    return m_Height;
}

bool Grid::IndexInBounds(unsigned int index) {
    if(index < m_Values.size()) return true;
    std::cout << "Grid access out of bounds" << std::endl;
    return false;
}

bool Grid::LocationInBounds(int2 location) {
    if(m_Height > location.x && m_Width > location.y) return true;
    std::cout << "Grid access out of bounds" << std::endl;
    return false;
}

int2 Grid::GetLocationFromIndex(unsigned int index) {
    if(IndexInBounds(index)) return int2(m_Values[index].GetPosition());
    return {};
}

unsigned int Grid::GetIndexFromLocation(int2 location) {
    if(LocationInBounds(location)) return location.x * m_Width + location.y;
    return false;
}

bool Grid::GetValueAtIndex(unsigned int index) {
    if(IndexInBounds(index)) return m_Values[index].blocked;
    return false;
}

bool Grid::GetValueAtLocation(int2 location) {
    if (LocationInBounds(location)) return GetValueAtIndex(GetIndexFromLocation(location));
    return false;
}

void Grid::SetValueAtIndex(unsigned int index, bool value) {
    if(IndexInBounds(index)) m_Values[index].blocked = value;
}

void Grid::SetValueAtLocation(int2 location, bool value) {
    if (LocationInBounds(location)) SetValueAtIndex(GetIndexFromLocation(location), value);
}

void Grid::Print() {
    for (int h = 0; h < m_Height; ++h) {
        for (int w = 0; w < m_Width; ++w) {
            std::cout << m_Values[h*m_Width + w].blocked;
        }
        std::cout << std::endl;
    }
}
