#include <iostream>
#include "TurtleGraphics.h"
using namespace std;

const bool UP = false;
const bool DOWN = true;
const bool FILL = false;

/*
	enum Commands { PEN_UP = 1, PEN_DWN = 2, TURN_RIGHT = 3, TURN_LEFT = 4, MOVE = 5, DISPLAY = 6, END_OF_DATA = 9 };
	enum Directions { NORTH, EAST, SOUTH, WEST };
*/

Directions turnRight(void);
Directions turnLeft(void);
//void drawLine(const int dist, bool *m_Floor[], int maxr, int maxc);

int c_col = 0;
int c_row = 0;

bool pen_pos;
Directions pen_dir;

//Public

/*
	ctor will init. floor to all "true" values, 
	as well as initialization of other data members
*/
TurtleGraphics::TurtleGraphics(void)
{
	for (int r = 0; r <= NROWS; r++)
	{
		for (int c = 0; c <= NCOLS; c++)
		{
			m_Floor[r][c] = true;
		}
	}
	pen_pos = TurtleGraphics::STARTING_PEN_POSITION;
	pen_dir = TurtleGraphics::STARTING_DIRECTION;
}

/*
	Will process the commands contained in array "commands"
*/
void TurtleGraphics::processTurtleMoves(const int commands[])
{
	cout << "commands[]: ";
	for (int x = 0; x < 222; x++)
	{
		cout << ", " << commands[x];
	}
	cout << endl;

	int dist = 0;
	int com = commands[0];
	for (int i = 0; com != 9; i++)
	{
		com = commands[i];
		switch (com)
		{
		case PEN_UP:
			cerr << "PEN_UP\n";
			pen_pos = UP;
			break;
		case PEN_DWN:
			cerr << "PEN_DWN\n";
			pen_pos = DOWN;
			break;
		case TURN_RIGHT:
			cerr << "TURN_RIGHT\n";
			pen_dir = turnRight();
			break;
		case TURN_LEFT:
			cerr << "TURN_LEFT\n";
			pen_dir = turnLeft();
			break;
		case MOVE:
			cerr << "MOVE\n";
			/*
			for (int n = 0; n < commands[i++]; n++)
			{
				switch (pen_dir)
				{
				case NORTH:
					if ((c_row - 1) > 0)
					{
						m_Floor[c_row--][c_col] = false;
					}
					break;
				case EAST:
					if ((c_col + 1) > NCOLS)
					{
						m_Floor[c_row][c_col++] = false;
					}
					break;
				case SOUTH:
					if ((c_row + 1) > NROWS)
					{
						m_Floor[c_row++][c_col] = false;
					}
					break;
				case WEST:
					if ((c_col - 1) > 0)
					{
						m_Floor[c_row][c_col--] = false;
					}
					break;
				default:
					break;
				}
			}
			*/
			++i;
			dist = commands[i];
			//drawLine(dist, (bool **)m_Floor, NROWS, NCOLS);
			drawLine(dist);
			break;
		case DISPLAY:
			cerr << "DISPLAY\n";
			displayFloor();
			break;
		default:
			break;
		}
	}
	cout << "commands[]: ";
	for (int x = 0; x < 222; x++)
	{
		cout << ", " << commands[x];
	}
	cout << endl;
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
/*
void drawLine(const int dist, bool *m_Floor[], int maxr, int maxc)
{
	for(int i = 0; i < dist; i++)
	{
		switch (pen_dir)
		{
		case NORTH:
			if ((c_row - 1) > 0)
			{
				m_Floor[c_row--][c_col] = FILL;
			}
			break;
		case EAST:
			if ((c_col + 1) < maxc)
			{
				m_Floor[c_row][c_col++] = FILL;
			}
			break;
		case SOUTH:
			if ((c_row + 1) < maxr)
			{
				m_Floor[c_row++][c_col] = FILL;
			}
			break;
		case WEST:
			if ((c_col - 1) > 0)
			{
				m_Floor[c_row][c_col--] = FILL;
			}
			break;
		default:
			break;
		}
	}
}
*/
void TurtleGraphics::drawLine(int dist)
{
	for (int i = 0; i < dist; i++)
	{
		switch (pen_dir)
		{
		case NORTH:
			if ((c_row - 1) > 0)
			{
				m_Floor[c_row--][c_col] = FILL;
				cerr << "Drawn at Row: " << c_row << " Col: " << c_col << "\n";
			}
			break;
		case EAST:
			if ((c_col + 1) < NCOLS)
			{
				m_Floor[c_row][c_col++] = FILL;
				cerr << "Drawn at Row: " << c_row << " Col: " << c_col << "\n";
			}
			break;
		case SOUTH:
			if ((c_row + 1) < NROWS)
			{
				m_Floor[c_row++][c_col] = FILL;
				cerr << "Drawn at Row: " << c_row << " Col: " << c_col << "\n";
			}
			break;
		case WEST:
			if ((c_col - 1) > 0)
			{
				m_Floor[c_row][c_col--] = FILL;
				cerr << "Drawn at Row: " << c_row << " Col: " << c_col << "\n";
			}
			break;
		default:
			break;
		}
	}
}

//Private

/*
	Will display floor on the screen
*/
void TurtleGraphics::displayFloor() const
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
				//cout << "Û";
				cout << "*";
			}
		}
		cout << "\n";
	}
	cout << endl;
}