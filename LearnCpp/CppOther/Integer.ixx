export module Integer;
import <iostream>;
import <compare>;	// <=> �𗘗p����ꍇ�K�{

namespace CppOther
{
	// ���Z�q�̃I�[�o�[���[�h�̃e�X�g
	export class Integer
	{
		int32_t value;
	public:
		// �g�ݍ��݂̐����^�̗l�Ɉ�������explicit�͕t���Ȃ�
		Integer(int32_t _value) :value(int32_t{ _value }) {};

		// �Z�p���Z�q�̃I�[�o�[���[�h
		// rhs�Fright hand side -> �E�ӂ̎�

		Integer operator+(const Integer& _rhs)const;
		Integer operator-(const Integer& _rhs)const;
		Integer operator*(const Integer& _rhs)const;
		Integer operator/(const Integer& _rhs)const;

		Integer operator+();		// �������]���Ȃ�
		Integer operator-();		// �������]

		Integer& operator++();		// �O�u�C���N�������g
		Integer& operator--();		// �O�u�f�N�������g
		Integer operator++(int);	// ��u�C���N�������g
		Integer operator--(int);	// ��u�f�N�������g
		
		// �r�b�g���Z�q�̃I�[�o�[���[�h

		Integer operator|(const Integer& _rhs)const;	// �r�b�g�a
		Integer operator&(const Integer& _rhs)const;	// �r�b�g��
		Integer operator^(const Integer& _rhs)const;	// �r�b�g�r���I�_���a
		Integer operator~()const;						// �r�b�g���]

		// �֌W���Z�q�̃I�[�o�[���[�h

		//bool operator==(const Integer& _rhs)const;
		//bool operator!=(const Integer& _rhs)const;
		//bool operator<(const Integer& _rhs)const;
		//bool operator>(const Integer& _rhs)const;
		//bool operator<=(const Integer& _rhs)const;
		//bool operator>=(const Integer& _rhs)const;

		// C++20����3����r���Z�q���`���邱�ƂŁA�ő�6�̔�r���Z�q���������o�ł���B
		auto operator<=>(const Integer&)const = default;

		// �t�����h�ȉ��Z�q�̃I�[�o�[���[�h

		//friend Integer operator+(const Integer&, int);	// �����o�[�֐��Ŏ������邱�Ƃ��ł���B
		//friend Integer operator+(int, const Integer&);	// �����o�[�֐��ł͎����ł��Ȃ��B
		//friend Integer operator-(const Integer&, int);	// �����o�[�֐��Ŏ������邱�Ƃ��ł���B
		//friend Integer operator-(int, const Integer&);	// �����o�[�֐��ł͎����ł��Ȃ��B

		// �R�s�[������Z�q�ƃ��[�u������Z�q

		Integer& operator=(const Integer& _rhs);

		// ����������Z�q(�G���[���o��̂ŃR�����g�A�E�g)

		//Integer operator+=(const Integer& _rhs)const;	// ���Z
		//Integer operator-=(const Integer& _rhs)const;	// ���Z
		//Integer operator*=(const Integer& _rhs)const;	// ��Z
		//Integer operator/=(const Integer& _rhs)const;	// ���Z

		// ���ɂ�
		// �Y�����Z�q�̃I�[�o�[���[�h
		// �F�z��Ȃǂ̕����̗v�f�����钆����A����̗v�f�ɃA�N�Z�X���邽�߂Ɏg���鉉�Z�q�B

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
		// �O�u�͕ύX������̎��g�̒l��Ԃ�
		++this->value;
		return *this;
	}

	Integer& Integer::operator--()
	{
		// �O�u�͕ύX������̎��g�̒l��Ԃ�
		--this->value;
		return *this;
	}

	Integer Integer::operator++(int)
	{
		// ��u�͕ύX�O�̒l��Ԃ��K�v������
		auto temp = *this;
		++*this;		// ����Ɉ�ѐ����������邽�߂ɑO�u���Ăяo���B
		return temp;	// �R�s�[���Ă������ύX�O�̒l��Ԃ��B
	}

	Integer Integer::operator--(int)
	{
		// ��u�͕ύX�O�̒l��Ԃ��K�v������
		auto temp = *this;
		--*this;		// ����Ɉ�ѐ����������邽�߂ɑO�u���Ăяo���B
		return temp;	// �R�s�[���Ă������ύX�O�̒l��Ԃ��B
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
	//	// == ���Ăяo���Ă��̔ے��Ԃ��B
	//	return { !(*this == _rhs) };
	//}

	//bool Integer::operator<(const Integer& _rhs) const
	//{
	//	return { this->value < _rhs.value };
	//}

	//bool Integer::operator>(const Integer& _rhs) const
	//{
	//	// ���E�����ւ��A���Ȃ���ĂԂ��Ƃő�Ȃ�̌��ʂ�
	//	return { _rhs < *this };
	//}

	//bool Integer::operator<=(const Integer& _rhs) const
	//{
	//	// ��Ȃ��ے肵�����ʂ����Ȃ�C�R�[���̌��ʂ�
	//	return { !(_rhs < *this) };
	//}

	//bool Integer::operator>=(const Integer& _rhs) const
	//{
	//	// ���E�����ւ��A���Ȃ�C�R�[�����ĂԂ��Ƃő�Ȃ�C�R�[���̌��ʂ�
	//	return { _rhs <= *this };
	//}

	//Integer operator+(const Integer& _lhs, int _rhs)
	//{
	//	// �t�����h�֐��Ȃ̂ŁA�v���C�x�[�g�����o�[�ɃA�N�Z�X�\
	//	return Integer{ _lhs.value + _rhs };
	//}

	//// Integer�̃C���X�^���X���E�ӂɗ���+�͂��̃I�[�o�[���[�h���g�p�����B
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

	// �R�s�[������Z�q�̓R�s�[���̃I�u�W�F�N�g��ύX�ł��Ȃ�
	// const�Q�ƂŎ󂯎��
	Integer& Integer::operator=(const Integer& _rhs)
	{
		std::cout << "�R�s�[:" << value << "->" << _rhs.value << std::endl;
		value = _rhs.value; // �l���R�s�[
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