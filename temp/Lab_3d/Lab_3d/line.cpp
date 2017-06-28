#include "line.h"
using namespace System::Drawing;

void lineto(Graphics^ g, DRAW_ACTION act, dot_t from, dot_t to)
{
    int CY = get_height(act) / 2,
		CX = get_width(act) / 2;

	Pen^ p = gcnew Pen(Color::Black);

	g->DrawLine(p, CX + get_coord(from, X_NAME), CY - get_coord(from, Y_NAME), CX + get_coord(to, X_NAME), CY - get_coord(to ,Y_NAME));
}
