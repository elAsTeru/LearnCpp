#define _interface			struct
#define IID_IMMUTABLE_0		0		// Immutableインターフェースの識別子

export module Immutable:Print;

__interface IImmutable
{
	virtual void Print() = 0;
};