export module ComponentSystem:Base;

namespace ComponentSystem
{
	// �R���|�[�l���g���Ɍp��������B
	export class Base
	{
	public:
		Base() :
			parent(nullptr)
		{}
		virtual ~Base() {}

		void* parent;	// �R���|�[�l���g��ۗL����N���X(void�^�͉��u��)

		virtual void Start() {}
	};
}