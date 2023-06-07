// [C / C++] ->[詳細設定] ->[コンパイル言語の選択] ->[C++モジュールコードとしてコンパイル]

export module ModuleTest;
import <iostream>;
import <string>;


namespace Cpp20Test
{
	// export されていないので外部からアクセスが不可能
	std::string greet(std::string{"Hello C++20 Module Test"});

	/// <summary>
	/// "Hello C++20をコンソールに表示する。"
	/// </summary>
	export void Greeting()
	{
		std::cout << greet << std::endl;
	}
}