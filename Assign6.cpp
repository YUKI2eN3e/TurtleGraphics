// Assign 6 Main Program - used to "test drive" the TurtleGraphics class
// File Name: Assign6.cpp
// Author: Bob Langelaan
// Date: Nov. 7, 2013

// This program implements Turtle Graphics

// include and using statments

#include <iostream>
using namespace std;

enum Commands { PEN_UP = 1, PEN_DWN = 2, TURN_RIGHT = 3, TURN_LEFT = 4, MOVE = 5, DISPLAY = 6, END_OF_DATA = 9 };
enum Directions { NORTH, EAST, SOUTH, WEST };

const static int NROWS = 22;
const static int NCOLS = 70;

const static int STARTING_ROW = 0;
const static int STARTING_COL = 0;

const static Directions STARTING_DIRECTION = SOUTH;

const static bool STARTING_PEN_POSITION = false;

bool m_Floor [NROWS][NCOLS];

//

void displayFloor();

void processTurtleMoves( const int commands[]);

//


Directions turnRight(void);
Directions turnLeft(void);

void drawLine(int dist);

//

const bool UP = false;
const bool DOWN = true;
const bool FILL = false;

int c_col;
int c_row;

bool pen_pos;
Directions pen_dir;

int main()
{
   // Declarations

   int cmds[] = { 5,5,4,5,9,2,5,12,1,3,5,1,4,2,5,1,1,3,5,1,2,5,2,1,3,5,1,4,2,5,1,1,3,5,1,2,5,11,3,5,5,1,3,5,12,3,5,5,5,1,4,2,5,1,1,3,5,1,2,5,2,1,3,5,1,4,2,5,1,1,3,5,1,2,5,11,3,5,5,1,5,5,3,5,22,2,5,10,1,3,5,1,4,2,5,1,1,3,5,1,2,5,7,1,3,5,1,4,2,5,1,1,3,5,1,2,5,10,1,3,5,1,4,2,5,1,1,3,5,1,2,5,7,1,3,5,1,4,2,5,1,1,3,5,19,2,5,12,1,3,5,1,4,2,5,1,1,3,5,1,2,5,2,1,3,5,1,4,2,5,1,1,3,5,1,2,5,11,3,5,5,1,3,5,12,3,5,5,5,1,4,2,5,1,1,3,5,1,2,5,2,1,3,5,1,4,2,5,1,1,3,5,1,2,5,11,3,5,5,1,6,9 }; // finish off

   for (int r = 0; r <= NROWS; r++)
	{
		for (int c = 0; c <= NCOLS; c++)
		{
			m_Floor[r][c] = true;
		}
	}
	pen_pos = STARTING_PEN_POSITION;
	pen_dir = STARTING_DIRECTION;  // create a TurtleGraphics object

   c_col = 0;
   c_row = 0;

   processTurtleMoves(cmds); // have turtle process commands

   system("pause");
   return 0;  // we are finished, let's go home
}

/*
	Will process the commands contained in array "commands"
*/
void processTurtleMoves(const int commands[])
{
	int dist = 0;
	int com = commands[0];
	for (int i = 0; com != 9; i++)
	{
		com = commands[i];
		switch (com)
		{
		case PEN_UP:
			//cerr << "PEN_UP\n";
			pen_pos = UP;
			break;
		case PEN_DWN:
			//cerr << "PEN_DWN\n";
			pen_pos = DOWN;
			break;
		case TURN_RIGHT:
			//cerr << "TURN_RIGHT\n";
			pen_dir = turnRight();
			break;
		case TURN_LEFT:
			//cerr << "TURN_LEFT\n";
			pen_dir = turnLeft();
			break;
		case MOVE:
			//cerr << "MOVE\n";
			++i;
			dist = commands[i];
			//drawLine(dist, (bool **)m_Floor, NROWS, NCOLS);
			drawLine(dist);
			break;
		case DISPLAY:
			//cerr << "DISPLAY\n";
			displayFloor();
			break;
		default:
			break;
		}
	}
}

Directions turnRight()
{
	switch (pen_dir)
	{
	case NORTH:
		return EAST;
		break;
	case EAST:
		return SOUTH;
		break;
	case SOUTH:
		return WEST;
		break;
	case WEST:
		return NORTH;
		break;
	default:
		return pen_dir;
		break;
	}
}

Directions turnLeft()
{
	switch (pen_dir)
	{
	case NORTH:
		return WEST;
		break;
	case WEST:
		return SOUTH;
		break;
	case SOUTH:
		return EAST;
		break;
	case EAST:
		return NORTH;
		break;
	default:
		return pen_dir;
		break;
	}
}

void drawLine(int dist)
{
	for (int i = 0; i < dist; i++)
	{
		switch (pen_dir)
		{
		case NORTH:
			if ((c_row - 1) > 0)
			{
            if(pen_pos == DOWN)
            {
               m_Floor[c_row][c_col] = FILL;
            }
            c_row--;
				//cerr << "Drawn at Row: " << c_row << " Col: " << c_col << "\n";
			}
			break;
		case EAST:
			if ((c_col + 1) < NCOLS)
			{
            if(pen_pos == DOWN)
            {
               m_Floor[c_row][c_col] = FILL;
            }
				c_col++;
				//cerr << "Drawn at Row: " << c_row << " Col: " << c_col << "\n";
			}
			break;
		case SOUTH:
			if ((c_row + 1) < NROWS)
			{
            if(pen_pos == DOWN)
            {
               m_Floor[c_row][c_col] = FILL;
            }
				c_row++;
				//cerr << "Drawn at Row: " << c_row << " Col: " << c_col << "\n";
			}
			break;
		case WEST:
			if ((c_col - 1) > 0)
			{
            if(pen_pos == DOWN)
            {
               m_Floor[c_row][c_col] = FILL;
            }
				c_col--;
				//cerr << "Drawn at Row: " << c_row << " Col: " << c_col << "\n";
			}
			break;
		default:
			break;
		}
	}
}

/*
	Will display floor on the screen
*/
void displayFloor()
{
	for (int r = 0; r < NROWS; r++)
	{
		for (int c = 0; c < NCOLS; c++)
		{
			if (m_Floor[r][c])
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << "\n";
	}
	cout << endl;
}