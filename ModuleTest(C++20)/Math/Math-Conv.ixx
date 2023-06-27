export module Math:Conv;
import :Const;

namespace Math
{
	/// <summary> 度 -> 弧度法 </summary>
	export template<typename T>
	constexpr T ToRadians(const T& _degrees)noexcept
	{
		return _degrees * (Pi<T> / 180.0);
	}
	/// <summary> 弧度法 -> 度 </summary>
	export template<typename T>
	constexpr T ToDegrees(const T& _radians)noexcept
	{
		return _radians * (180.0 / Pi<T>);
	}
}