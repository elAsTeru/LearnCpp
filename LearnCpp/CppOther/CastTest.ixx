export module CastTest;
import <iostream>;

namespace CppOther
{
	uint16_t identity(uint16_t _v)
	{
		return _v;
	}

	// static_castはコンパイル時に決定
	export inline void StaticCastTest()
	{
		char c(char{ 99 });
		// charをint型に変換
		uint16_t i(uint16_t{ static_cast<uint16_t>(c) });
		std::cout << "char型 : " << c << " -> " << "int型 : " << i << '\n';
	}
}