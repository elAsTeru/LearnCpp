export module ComponentSystem:Base;
import <memory>;

namespace ComponentSystem
{
	// コンポーネント側に継承させる。
	export template <class T> class Base
	{
	public:
		Base() :
			parent(nullptr)
		{}
		virtual ~Base() {}

		std::shared_ptr<T> parent;	// コンポーネントの所持者

		virtual void Start() {}
	};
}