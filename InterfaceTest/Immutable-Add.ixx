#define _interface			struct
#define IID_IMMUTABLE_0		0		// Immutableインターフェースの識別子

export module Immutable:Add;

__interface IImmutable
{
	virtual int Add(int) = 0;
};