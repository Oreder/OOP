#include <gcroot.h>
#include "model.h"
#include "conversion.h"
#include "matrix.h"
using namespace System::Drawing;

//обёртка для холста
 struct sCanvasContainer
{
	gcroot<System::Windows::Forms::PictureBox^> pb;
};

//мольберт для рисования
/*typedef value*/ struct sEasel
{
	gcroot<Graphics^> canvas;
	gcroot<System::Drawing::Color> backColor;
	int cx, cy; //center
};

void DrawModel(sModel *mdl, sEasel *easel, sRenderData *params);
void ClearCanvas (sEasel *easel);
