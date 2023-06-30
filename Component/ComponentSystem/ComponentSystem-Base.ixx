export module ComponentSystem:Base;

namespace ComponentSystem
{
	// コンポーネント側に継承させる。
	export class Base
	{
	public:
		Base() :
			parent(nullptr)
		{}
		virtual ~Base() {}

		void* parent;	// コンポーネントを保有するクラス(void型は仮置き)

		virtual void Start() {}
	};
}