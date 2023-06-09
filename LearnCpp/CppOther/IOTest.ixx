export module IOTest;
import <iostream>;
//import <iomanip>;
import <string>;
import <fstream>;

namespace CppOther
{
	export void ConsoleOutTest()
	{
		std::cout << '\n';

		std::cout << "■ std::boolalpha\n";
		std::cout << "bool型の出力時、trueとfalseで出力される。\n";
		std::cout << std::boolalpha << "bool{0} : " << bool{ 0 } << " / bool{1} : " << bool{ 1 } << '\n';

		std::cout << "■ 数値を10進数で出力\n";
		std::cout << std::dec << "13 : " << 13 << '\n';

		std::cout << "■ 数値を16進数で出力\n";
		std::cout << std::hex << "13 : " << 13 << '\n';

		std::cout << "■ std::noboolalpha\n";
		std::cout << "bool型の出力が、trueとfalseでなくなる。\n";
		std::cout << std::noboolalpha << true << '\n';
	}

	export void OFStreamTest()
	{
		std::cout << "■ ofstreamテスト\n";
		// 指定したファイルがない場合作成される。
		std::ofstream ofs("ofs.txt");	// 出力用オブジェクトの作成
		ofs << "First Out";				// テキスト出力
		ofs.close();					// 操作終了時にはクローズ

		// オープンされたファイルの中身が空になる。
		std::ofstream ofs2("ofs.txt");
		ofs2 << "Second Out";
		ofs2.close();					// クローズしなくても、デストラクタで自動的にクローズされる。

		std::remove("ofs.txt");			// 作ったファイルの削除
		// 動きが見たかったらブレイクポイントを置く必要がある。
		// ofstreamは出力用の処理なので、中身を見れない。
	}

	export void IFStreamTest()
	{
		std::cout << "■ ifstreamテスト\n";
		// 指定したファイルがない場合、ファイルが作られることはなく、オブジェクトを使おうとするとエラーになる。
		std::ifstream ifs {"ifs.txt"};

		// 10回ファイル生成が失敗したら終了する。(何かで使えそうだから、使うときは10回失敗したときの分岐も作りたい。)
		for (int i = 0; !ifs.is_open() && i < 10; ++i)
		{
			std::cerr << "ifs.txtファイルがありません。\n";
			std::cout << "ファイルを作ります。\n";

			std::ofstream ofs("ifs.txt");
			ofs << "Hello File Test\n";
			ofs.close();			// 明示的にクローズ

			ifs = std::ifstream{ "ifs.txt" };
		}

		std::string line;
		std::getline(ifs, line);	// テキストファイルから1行読み取り
		std::cout << line << '\n';

		std::getline(ifs, line);
		std::cout << "現在位置はファイルの末尾？：" << std::boolalpha << ifs.eof() << std::noboolalpha << '\n';

		ifs.close();				// クローズしなくても、デストラクタで自動的にクローズされる。

		std::remove("ifs.txt");		// 作ったファイルの削除
	}
}