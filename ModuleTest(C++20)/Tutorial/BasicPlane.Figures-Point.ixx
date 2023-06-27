// 『モジュール パーティション ファイル』
// : と パーティション名が付く
export module BasicPlane.Figures:Point;
// defines a module partition, Point, that's part of the module BasicPlane.Figures
// このパーティションはBasicPlane.Figuresモジュールの一部として認識される。

export struct Point
{
	int x, y;
};