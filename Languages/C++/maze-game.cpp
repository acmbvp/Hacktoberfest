#include 
#include 
#include "maze.h"


// =============================> Maze Objects <====================
// Maze object data members:
//   int _max_row;
//   int _max_col;
//   char _map[MAX_MAZE_DIM+1][MAX_MAZE_DIM+1];

// ============================> report_err <=======================
static void report_err(const char* message)
{  
  cout << "FATAL ERROR (Maze): " << message << endl;
  exit(1);
}

// ========================> member functions <=====================

// ========================> Constructors <==================
Maze::Maze()
{
  *this = Maze(7,7);
}

Maze::Maze(int rows, int cols)
{
  if (rows > MAX_MAZE_DIM || cols > MAX_MAZE_DIM)
    report_err("Attempted to create overly large Maze");
  _max_row = rows;
  _max_col = cols;
  for(int row = 1; row <= rows; row++)
    for(int col = 1; col <= cols; col++)
      _map[row][col] = '.';
}

// =======================> max_row <========================
int Maze::max_row() const
{ return _max_row;
}

// ======================> max_col <=========================
int Maze::max_col() const
{ return _max_col;
}

// =====================> is_open <==========================
int Maze::is_open(int i, int j) const
// PRE:  VALID_POS(i, j)
// POST: FCTVAL == position (i, j) of this maze is open (contains a '.')
{
   if (i < 1 || i > _max_row)
   		report_err("Attempted to check cell row outside of maze dimensions");
   		
   if (j < 1 || j > _max_col)
   		report_err("Attempted to check cell column outside of maze dimensions");
   		 
   if (_map[i][j] == '.')	// if current spot in maze is passible
   		return (1);			//    return 1 ==> TRUE
   else
   		return (0);
}

// ====================> mark <==============================
void Maze::mark(int row, int col, char marker)
{
  if (!is_open(row,col))
    report_err("Attempt to mark an non-open Maze cell");
  _map[row][col] = marker;
}

// ===================> unmark <=============================
void Maze::unmark(int row, int col)
// PRE: VALID_POS(row, col) &&
//      _map[row][col] != '*'
// POST: is_open(row, col)
{
	if (_map[row][col] != '*')
		_map[row][col] = '.';		// reset current spot in maze to passible
	
	return;
}

// ===================> stream output <======================
ostream& operator<<(ostream& stream, Maze m)
{ 
  for(int row = 1; row <= m._max_row; row++)
    { 
      for(int col = 1; col <= m._max_col; col++)
		stream.put(m._map[row][col]);
      stream << endl;
    }
  stream << flush;
  return stream;
}

// ==================> stream input <=======================
istream& operator>>(istream& stream, Maze& m)
{ char ch;

  for(int row = 1; row <= m._max_row; row++)
    { 
      for(int col = 1; col <= m._max_col; col++)
	{ 
	  stream.get(ch);
	  if (ch == '.' || ch == ' ')
	    m._map[row][col] = '.';
	  else
	    m._map[row][col] = '*';
	}
      stream.ignore(50,'\n');
    }
  return stream;
}
