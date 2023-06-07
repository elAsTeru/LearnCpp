export module CastTest;
import <iostream>;

namespace CppOther
{
	export void StaticCastTest()
	{
		char c(char{ 99 });
		// charをint型に変換
		std::uint16_t i(std::uint16_t{ static_cast<std::uint16_t>(c) });
		std::cout << "char型 : " << c << " -> " << "int型 : " << i << std::endl;
	}
}