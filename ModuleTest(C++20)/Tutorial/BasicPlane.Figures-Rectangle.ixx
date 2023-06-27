// 『モジュール パーティション ファイル』
export module BasicPlane.Figures:Rectangle;
// defines the module partition Rectangle
import :Point;

export struct Rectangle // make this struct visible to imports
{
	Point ul, lr;
};

// These functioins are declared, but will
// be defined in a module implementation file
export int area(const Rectangle& _r);
export int height(const Rectangle& _r);
export int width(const Rectangle& _r);