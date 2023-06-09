import ModuleTest;
import <iostream>;

// ここのクラスの情報はModuleで使うので消さないように。
class Base
{
public:
	Base() { std::cout << "Base" << '\n'; }
	virtual ~Base() { std::cout << "~Base" << '\n'; }
	// 基底クラスのポインタに、派生クラスのオブジェクトをいれると
	// Base* p = new Child;
	// pはBaseクラスへのポインタなので、~Base()が呼ばれる。
	// デストラクタにvirtualが付与されると~Base()の前に派生オブジェクトの
	// デストラクタが呼ばれるようになる。

	// 関数も同じく virtual を付けなければ、派生クラスで定義しても
	// 基底クラスのものが呼ばれる。
	void Greeting() { std::cout << "Hi, I am base class." << '\n'; }

	void BMethod() { std::cout << "This is the base method." << '\n'; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Child" << '\n'; }
	~Derived() { std::cout << "~Child" << '\n'; }

	// 関数も同じく 基底クラスでvirtual がなければ、基底クラスのものが
	// 呼ばれる。あとオーバーライドしたことを明示するためにoverrideを付けよう。
	void Greeting() { std::cout << "Hi, I am derived class." << '\n'; }

	// 基底クラスのポインターにオブジェクトをいれた場合、呼出し不可能。
	// 呼び出したい場合は、キャストする必要がある。
	// 逆に派生クラスのポインターにいれた場合は、基底のBMethodもDMethodも呼べる。
	void DMethod() { std::cout << "This is the derived method." << '\n'; }
};


int wmain()
{
	Cpp20Test::Greeting();

	//// 上に定義してるクラスのテスト
	//Base* derived = new Derived;
	//derived->Greeting();
	//derived->BMethod();
	//static_cast<Derived*>(derived)->DMethod();
	//delete derived;

	// Windows限定でプログラムの実行を一時停止する。
	system("pause\n");
	return 0;
}

// ラムダ
// インターフェース
// モジュール