// (C) 2023.7.1 - 2023.7.2 elAsTeru. //

export module ComponentSystem:Component;

namespace ComponentSystem
{
	// コンポーネント側に継承させる。
	// O : owner class
	export template <class O> class Component
	{
	public:
		Component() :
			owner(nullptr)
		{}
		virtual ~Component(){}

		O* owner;	// コンポーネントを所持しているインスタンス

		virtual void Init() {}
		virtual void Update() {}
	};
}