#include <algorithm>
#include <iostream>
#include <utility>
#include <fstream>
#include <random>
#include <chrono>

std::istream& operator>>(std::istream& in, std::pair<int, int>& pair)
{
    in >> pair.first >> pair.second;
    return in;
}

void operator>>(const std::string& path, std::vector<std::pair<int, int>>& obj)
{
    std::ifstream fin;
    fin.open(path);
    if (fin.is_open()) {
        while (!fin.eof()) {
            std::pair<int, int> temp;
            fin >> temp;
            obj.push_back(temp);
        }
        fin.close();
    } else
        std::cerr << "File not found." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const std::pair<int, int>& pair)
{
    out << pair.first << std::endl << pair.second << std::endl;
    return out;
}

void operator<<(const std::string& path, const std::vector<std::pair<int, int>>& obj)
{
    std::ofstream fout;
    fout.open(path);
    if (fout.is_open()) {
        for (const auto &i : obj)
            fout << i;
        fout.close();
    } else
        std::cerr << "File not found." << std::endl;
}

int main() {
    std::vector<std::pair<int, int>> tree;
    R"(D:\files\lab10\tree.txt)" >> tree;
    std::default_random_engine URNG(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(std::begin(tree), std::end(tree), URNG);
    R"(D:\files\lab10\unbalanced_tree.txt)" << tree;
    return 0;
}
