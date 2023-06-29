#include <utility>
export module Immutable;
import :Print;
import :Add;
import <iostream>;

export
template <typename T>
class Immutable : public IImmutable
{
	const T value;
public:
	Immutable() = delete;			// 引数なしコンストラクタの削除(今回面倒なので)
	Immutable(const T _value):
		value(_value)
	{}
	// 他にも不変データ型を作るときは、コンストラクタを設定するが、今回メインでないので飛ばす。
	~Immutable(){}

	static const T& Get() { return this->value; }

	void Print() { std::cout << this->value << '\n'; }
	int Add(int _value) { return this->value + _value; }
};