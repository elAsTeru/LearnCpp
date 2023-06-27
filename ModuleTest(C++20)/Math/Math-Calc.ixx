// module partition
export module Math:Calc;

namespace Math
{
	/// <summary> Power : 累乗 </summary>
	/// <param name="_radix">基数</param>
	/// <param name="_exponent">冪指数</param>
	export template<typename T>
	constexpr T Pow(const T& _radix, const int& _exponent)noexcept
	{
		T ans{ _radix };	// 累乗する値を1つ入れたのでループ回数を-1する必要がある。
		for (unsigned long i = _exponent; i > 1; --i)
		{
			ans *= _radix;
		}
		return ans;
	}
}