#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
class Point{
    
public:
    int x;
    int y;
    Point(int new_x, int new_y){
        x = new_x;
        y = new_y;
        std::cout << "Creating new point with coordinates (" << x << "," << y << ")";
    }
};



class Billboard{
public:
    int x1;
    int x2;
    int y1;
    int y2;
    std::vector<Point> corners;
    Billboard(std::string input){
        std::istringstream sin(input);
        sin >> x1;
        sin >> y1;
        sin >> x2;
        sin >> y2;
        corners[0] = Point(x1,y1);
    }
};




int main(){
    std::ifstream fin("billboard.in");
    std::ofstream fout("billboard.out");
    
    Billboard lawnmower("1 2 3 4");
    
    int input;
    std::vector<int> coordinates;
    while(fin >> input)
    {
        coordinates.push_back(input);
    }
    for(int coordinate : coordinates)
    {
        std::cout << coordinate << "\n";
    }
    Point newPoint(2,5);

    return 0;
}
