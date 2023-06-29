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
	Immutable() = delete;			// �����Ȃ��R���X�g���N�^�̍폜(����ʓ|�Ȃ̂�)
	Immutable(const T _value):
		value(_value)
	{}
	// ���ɂ��s�σf�[�^�^�����Ƃ��́A�R���X�g���N�^��ݒ肷�邪�A���񃁃C���łȂ��̂Ŕ�΂��B
	~Immutable(){}

	static const T& Get() { return this->value; }

	void Print() { std::cout << this->value << '\n'; }
	int Add(int _value) { return this->value + _value; }
};