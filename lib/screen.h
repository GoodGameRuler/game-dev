#ifndef SCREEN
#define SCREEN

#include <vector>
class GameScreen {
public:
    GameScreen(int rows = 160, int columns = 70, bool debug = false);
    ~GameScreen();

private:
    int _rows;
    int _columns;
    bool _debug;
    std::vector<std::vector<int>> _goxels;

};

#endif // !SCREEN
