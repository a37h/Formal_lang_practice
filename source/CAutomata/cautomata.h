#ifndef SOURCE_CAUTOMATA_H
#define SOURCE_CAUTOMATA_H

#include <iostream>
#include <vector>
#include <set>
#include <cassert>

#define varepsilon 'e'

// 0 подразумевается initial state всегда
class CAutomata {
public:

    CAutomata(): states_count(0) {};

    // Простой конструктор для автомата задающего язык из одной буквы
    explicit CAutomata(char symbol);

    // Конструктор для сложения или конъюнкции
    CAutomata(CAutomata *first, CAutomata *second, char operation);

    // Конструктор для звезды клини
    CAutomata(CAutomata *old_automata, char operation);

    void PrintAutomata();

    std::vector<std::pair<size_t,char>> GetNextVerts(size_t verticeFrom);

    size_t GetSize();

    bool isTerminal(size_t vertice);

protected:
    // Матрица n*n наборов (множеств) символов
    // Множество символов в [i][j] ячейке соответствует
    // множеству символов на ребре из i в j вершину
    // Напр.: a,b,varepsilon соответствует ребру a+b+\varepsilon
    std::vector<std::vector<char>> edges_matrix;
    std::set<size_t> accepting_states;
    size_t states_count;
};

#endif //SOURCE_CAUTOMATA_H