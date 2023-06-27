// module partition
// 数学定数
export module Math:Const;

namespace Math
{
	// Perimeter : 円周率
	export template<typename T>
	constexpr T Pi{static_cast<T>(3.14159265358979323846)};
}