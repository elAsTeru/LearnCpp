export module Integer;
import <iostream>;
import <compare>;	// <=> を利用する場合必須

namespace CppOther
{
	// 演算子のオーバーロードのテスト
	export class Integer
	{
		int32_t value;
	public:
		// 組み込みの整数型の様に扱うためexplicitは付けない
		Integer(int32_t _value) :value(int32_t{ _value }) {};

		// 算術演算子のオーバーロード
		// rhs：right hand side -> 右辺の事

		Integer operator+(const Integer& _rhs)const;
		Integer operator-(const Integer& _rhs)const;
		Integer operator*(const Integer& _rhs)const;
		Integer operator/(const Integer& _rhs)const;

		Integer operator+();		// 符号反転しない
		Integer operator-();		// 符号反転

		Integer& operator++();		// 前置インクリメント
		Integer& operator--();		// 前置デクリメント
		Integer operator++(int);	// 後置インクリメント
		Integer operator--(int);	// 後置デクリメント
		
		// ビット演算子のオーバーロード

		Integer operator|(const Integer& _rhs)const;	// ビット和
		Integer operator&(const Integer& _rhs)const;	// ビット積
		Integer operator^(const Integer& _rhs)const;	// ビット排他的論理和
		Integer operator~()const;						// ビット反転

		// 関係演算子のオーバーロード

		//bool operator==(const Integer& _rhs)const;
		//bool operator!=(const Integer& _rhs)const;
		//bool operator<(const Integer& _rhs)const;
		//bool operator>(const Integer& _rhs)const;
		//bool operator<=(const Integer& _rhs)const;
		//bool operator>=(const Integer& _rhs)const;

		// C++20から3方比較演算子を定義することで、最大6つの比較演算子を自動導出できる。
		auto operator<=>(const Integer&)const = default;

		// フレンドな演算子のオーバーロード

		//friend Integer operator+(const Integer&, int);	// メンバー関数で実装することもできる。
		//friend Integer operator+(int, const Integer&);	// メンバー関数では実装できない。
		//friend Integer operator-(const Integer&, int);	// メンバー関数で実装することもできる。
		//friend Integer operator-(int, const Integer&);	// メンバー関数では実装できない。

		// コピー代入演算子とムーブ代入演算子

		Integer& operator=(const Integer& _rhs);

		// 複合代入演算子(エラーが出るのでコメントアウト)

		//Integer operator+=(const Integer& _rhs)const;	// 加算
		//Integer operator-=(const Integer& _rhs)const;	// 減算
		//Integer operator*=(const Integer& _rhs)const;	// 乗算
		//Integer operator/=(const Integer& _rhs)const;	// 除算

		// 他には
		// 添字演算子のオーバーロード
		// ：配列などの複数の要素がある中から、特定の要素にアクセスするために使われる演算子。

		void show() const;
	};

	Integer Integer::operator+(const Integer& _rhs) const
	{
		return Integer{ this->value + _rhs.value };
	}

	Integer Integer::operator-(const Integer& _rhs) const
	{
		return Integer{ this->value - _rhs.value };
	}

	Integer Integer::operator*(const Integer& _rhs) const
	{
		return Integer{ this->value * _rhs.value };
	}

	Integer Integer::operator/(const Integer& _rhs) const
	{
		return Integer{ this->value /_rhs.value };
	}

	Integer Integer::operator+()
	{
		return *this;
	}

	Integer Integer::operator-()
	{
		return Integer(-this->value);
	}

	Integer& Integer::operator++()
	{
		// 前置は変更した後の自身の値を返す
		++this->value;
		return *this;
	}

	Integer& Integer::operator--()
	{
		// 前置は変更した後の自身の値を返す
		--this->value;
		return *this;
	}

	Integer Integer::operator++(int)
	{
		// 後置は変更前の値を返す必要がある
		auto temp = *this;
		++*this;		// 動作に一貫性を持たせるために前置を呼び出す。
		return temp;	// コピーしておいた変更前の値を返す。
	}

	Integer Integer::operator--(int)
	{
		// 後置は変更前の値を返す必要がある
		auto temp = *this;
		--*this;		// 動作に一貫性を持たせるために前置を呼び出す。
		return temp;	// コピーしておいた変更前の値を返す。
	}

	Integer Integer::operator|(const Integer& _rhs) const
	{
		return Integer{ this->value | _rhs.value};
	}

	Integer Integer::operator&(const Integer& _rhs) const
	{
		return Integer{ this->value &_rhs.value };
	}

	Integer Integer::operator^(const Integer& _rhs) const
	{
		return Integer{ this->value ^ _rhs.value };
	}

	Integer Integer::operator~() const
	{
		return Integer{~this->value};
	}

	//bool Integer::operator==(const Integer& _rhs) const
	//{
	//	return { this->value == _rhs.value };
	//}

	//bool Integer::operator!=(const Integer& _rhs) const
	//{
	//	// == を呼び出してその否定を返す。
	//	return { !(*this == _rhs) };
	//}

	//bool Integer::operator<(const Integer& _rhs) const
	//{
	//	return { this->value < _rhs.value };
	//}

	//bool Integer::operator>(const Integer& _rhs) const
	//{
	//	// 左右を入れ替え、小なりを呼ぶことで大なりの結果に
	//	return { _rhs < *this };
	//}

	//bool Integer::operator<=(const Integer& _rhs) const
	//{
	//	// 大なりを否定した結果が小なりイコールの結果に
	//	return { !(_rhs < *this) };
	//}

	//bool Integer::operator>=(const Integer& _rhs) const
	//{
	//	// 左右を入れ替え、小なりイコールを呼ぶことで大なりイコールの結果に
	//	return { _rhs <= *this };
	//}

	//Integer operator+(const Integer& _lhs, int _rhs)
	//{
	//	// フレンド関数なので、プライベートメンバーにアクセス可能
	//	return Integer{ _lhs.value + _rhs };
	//}

	//// Integerのインスタンスが右辺に来る+はこのオーバーロードが使用される。
	//Integer operator+(int _lhs, const Integer& _rhs)
	//{
	//	return Integer{ _lhs + _rhs.value };
	//}

	//Integer operator-(const Integer& _lhs, int _rhs)
	//{
	//	return Integer{ _lhs.value - _rhs };
	//}

	//Integer operator-(int _lhs, const Integer& _rhs)
	//{
	//	return Integer{ _lhs - _rhs.value };
	//}

	// コピー代入演算子はコピー元のオブジェクトを変更できない
	// const参照で受け取る
	Integer& Integer::operator=(const Integer& _rhs)
	{
		std::cout << "コピー:" << value << "->" << _rhs.value << std::endl;
		value = _rhs.value; // 値をコピー
		return *this;
	}

	//Integer Integer::operator+=(const Integer& _rhs) const
	//{
	//	this->value += _rhs.value;
	//	return *this;
	//}

	//Integer Integer::operator-=(const Integer& _rhs) const
	//{
	//	this->value -= _rhs.value;
	//	return *this;
	//}

	//Integer Integer::operator*=(const Integer& _rhs) const
	//{
	//	this->value *= _rhs.value;
	//	return *this;
	//}

	//Integer Integer::operator/=(const Integer& _rhs) const
	//{
	//	this->value /= _rhs.value;
	//	return *this;
	//}

	void Integer::show() const
	{
		std::cout << "Integer.value : " << this->value << '\n';
	}
}