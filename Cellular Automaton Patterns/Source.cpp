#include <SFML/Graphics.hpp>
#include <iostream>
#include <bitset>
using namespace sf;

constexpr int Window_Width = 1600;
constexpr int Window_Height = 900;
constexpr int box_dimenseions = 5;
constexpr int row = Window_Height / box_dimenseions;
constexpr int col = Window_Width / box_dimenseions;

typedef struct cell {
	RectangleShape rect;
	int state;
}cell;
cell matrix[row][col];
int index = 0;

void set_squres(void);
void generation(void);

//some good looking rules from the rule set
//next gen pattern drawing algo haahaa
int Rule_18(int, int);
int Rule_30(int, int);
int Rule_45(int, int);
int Rule_60(int, int);
int Rule_73(int, int);
int Rule_99(int, int);
int Rule_105(int, int);
int Rule_110(int, int);
int Rule_129(int, int);
int Rule_169(int, int);

int main()
{
	RenderWindow window(VideoMode(Window_Width, Window_Height), "Cellular Automaton", Style::Close);
	set_squres();

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				window.close();
			default:
				break;
			}
		}

		if (index < row - 1)
			generation();

		window.clear();

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				window.draw(matrix[i][j].rect);

		window.display();
	}
}

void generation(void)
{
	for (int j = 0; j < col; j++)
	{
		//change rule number here
		matrix[index + 1][j].state = Rule_99(index, j);

		if (matrix[index + 1][j].state == 1)
			matrix[index + 1][j].rect.setFillColor(Color::Black);
	}
	index++;
}

/////////////////////////////////////////////////////////

int Rule_18(int i, int j)
{
	//these are bad implementation but understandable
	if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 0;
}

int Rule_30(int i, int j)
{
	return matrix[i][j - 1].state ^ (matrix[i][j].state | matrix[i][j + 1].state);
}

int Rule_45(int i, int j)
{
	if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 1;
}

int Rule_60(int i, int j)
{
	return matrix[i][j - 1].state ^ (matrix[i][j].state);
}

int Rule_73(int i, int j)
{
	if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 1;
}

int Rule_99(int i, int j)
{
	if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 1;
}

int Rule_105(int i, int j)
{
	if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 1;
}

int Rule_110(int i, int j)
{
	if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 0;
}

int Rule_129(int i, int j)
{
	if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 1;
}

int Rule_169(int i, int j)
{
	if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 1 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 1) return 1;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 1 && matrix[i][j + 1].state == 0) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 1) return 0;
	else if (matrix[i][j - 1].state == 0 && matrix[i][j].state == 0 && matrix[i][j + 1].state == 0) return 1;
}


//////////////////////////////////////////////////////
void set_squres(void)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j].rect.setSize(Vector2f(box_dimenseions, box_dimenseions));
			matrix[i][j].rect.setFillColor(Color::White);
			matrix[i][j].state = 0;
			matrix[i][j].rect.setPosition(j*box_dimenseions, i*box_dimenseions);//i and j swapped
		}
	}
	matrix[0][col / 2].state = 1;
	matrix[0][col / 2].rect.setFillColor(Color::Black);
}




