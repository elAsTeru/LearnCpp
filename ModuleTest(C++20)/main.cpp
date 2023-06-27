// C++20で追加されたモジュール機能の使用方法を考える。

import <iostream>;			// 設定1をしたら使えるようになる。
#include <iomanip>			// #includeでないと実行できるがエラーの表示が邪魔になる。
import BasicPlane.Figures;	// モジュールのチュートリアル
import Math;

//Math.演算
//Math:constant

int main()
{
	// 1.モジュールを使って、Hello Worldを表示させる。(設定できてないと何もできないので。)
	// C++20に設定後、main.cppの[プロパティ]->[詳細設定]->[コンパイル言語の選択]->[モジュールコードとしてコンパイル]
	std::cout << "Hello\n";

	// 2.モジュールインターフェースユニット内で定義してある関数を呼び出す。
	Rectangle r{ {1,8},{11,3} };
	std::cout << "area:" << area(r) << '\n';
	std::cout << "width:" << width(r) << '\n';

	// 3.適当にMathモジュールを作成したので使用。
	std::cout << std::setprecision(16) << Math::Pi<double> << '\n';
	std::cout << std::setprecision(8) << Math::Pi<float> << '\n';

	std::cout << Math::Pow<unsigned long long>(2, 32) << '\n';

	using Vec3 = Math::Vector3;
	Vec3 vecA{1.0, 2.0, 3.0};
	Vec3 vecB{4.0, 5.0, 6.0};
	
	std::cout << "ベクトルA：" << vecA << "ベクトルB：" << vecB << '\n';

	std::cout << "内積：" << vecA.Dot(vecB) << '\n';
	std::cout << "外積：" << vecA.Cross(vecB) << '\n';
	std::cout << "長さ：" << vecA.Length() << '\n';
	std::cout << "正規：" << vecA.Normalize() << '\n';
}