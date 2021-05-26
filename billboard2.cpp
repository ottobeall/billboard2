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
        std::cout << "Creating new point with coordinates (" << x << "," << y << ") \n";
    }
    bool inside(int x1, int x2, int y1, int y2){
        return ((x >= x1 && x <= x2) && (y >= y1 && y <= y2));
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
        corners.push_back(Point(x1,y1));
        corners.push_back(Point(x1,y2));
        corners.push_back(Point(x2,y2));
        corners.push_back(Point(x2,y1));
    }
    int area(){
        return (x2-x1)*(y2-y1);
    }
};




int main(){
    std::ifstream fin("billboard.in");
    std::ofstream fout("billboard.out");
    std::string input;
    getline(fin,input);
    Billboard lawnmower(input);
    getline(fin,input);
    Billboard feed(input);
    std::vector<Point> cornersOverlapped;
    for(Point i : lawnmower.corners){
        if(i.inside(feed.x1,feed.x2,feed.y1,feed.y2)){
            cornersOverlapped.push_back(i);
        }
    }
    std::cout << "Corners overlapped: " << cornersOverlapped.size() << "\n";
    if(cornersOverlapped.size() == 0 || cornersOverlapped.size() == 1){
        fout << lawnmower.area();
    }
    else if(cornersOverlapped.size() == 2){
        int x1Final;
        int x2Final;
        int y1Final;
        int y2Final;
        if(cornersOverlapped[0].x == cornersOverlapped[1].x){
            if(cornersOverlapped[0].x == lawnmower.x1){
                x1Final = feed.x2;
                x2Final = lawnmower.x2;
                y1Final = lawnmower.y1;
                y2Final = lawnmower.y2;
            }
            else if(cornersOverlapped[0].x == lawnmower.x2){
                x1Final = lawnmower.x1;
                x2Final = feed.x1;
                y1Final = lawnmower.y1;
                y2Final = lawnmower.y2;
            }
        }
        else if(cornersOverlapped[0].y == cornersOverlapped[1].y){
            if(cornersOverlapped[0].y == lawnmower.y1){
                x1Final = lawnmower.x1;
                x2Final = lawnmower.x2;
                y1Final = feed.y2;
                y2Final = lawnmower.y2;
            }
            else if(cornersOverlapped[0].y == lawnmower.y2){
                x1Final = lawnmower.x1;
                x2Final = lawnmower.x2;
                y1Final = lawnmower.y1;
                y2Final = feed.y1;
            }
        }
        std::string finalTag = std::to_string(x1Final) + " " + std::to_string(y1Final) + " " + std::to_string(x2Final) + " " + std::to_string(y2Final);
        Billboard finalBoard(finalTag);
        fout << finalBoard.area();
    }
    else if(cornersOverlapped.size() == 4){
        fout << 0;
    }
    return 0;
}