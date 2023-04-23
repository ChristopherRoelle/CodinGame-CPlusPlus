/*
Christopher Roelle
04-23-2023
Binary Search Solution
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

bool LikeChar(string dir, char charToCheckFor)
{
    for(int i = 0; i < dir.length(); i++)
    {
        if(dir[i] == charToCheckFor)
        {
            return true; //Found it.
        }
    }

    return false; //Did not find it...
}

int main()
{
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0; //Batman Start X
    int y0; //Batman Start Y
    cin >> x0 >> y0; cin.ignore();

    int batman_x = x0; //New Batman coordinates
    int batman_y = y0; //New Batman coordinates

    int low_x, low_y = 0; //Low bounds
    int high_x = w;
    int high_y = h;

    int mid_x, mid_y = 0;

    // game loop
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cerr << "Midpoints: (" << mid_x << ", " << mid_y << ")" << endl;

        //Determine the Y
        if(LikeChar(bomb_dir, 'U'))
        {
            cerr << "LowY set to Batman's Y" << endl;
            high_y = batman_y; //Set our high to Batman's y. (inverted grid)
        } 
        else if (LikeChar(bomb_dir, 'D'))
        {
            cerr << "HighY set to Batman's Y" << endl;
            low_y = batman_y;
        }

        //Determine the X
        if(LikeChar(bomb_dir, 'R'))
        {
            cerr << "LowX set to Batman's X" << endl;
            low_x = batman_x; //Set our low to Batman's x. 
        } 
        else if (LikeChar(bomb_dir, 'L'))
        {
            cerr << "HighX set to Batman's X" << endl;
            high_x = batman_x;
        }

        //Determine the midpoints
        mid_x = (high_x + low_x) / 2;
        mid_y = (high_y + low_y) / 2;

        //Set Batman's temp positions to midpoints
        batman_x = mid_x;
        batman_y = mid_y;


        // the location of the next window Batman should jump to.
        cout << batman_x << " " << batman_y << endl;
    }
}

