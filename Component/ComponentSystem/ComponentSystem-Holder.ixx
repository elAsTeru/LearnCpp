export module ComponentSystem:Holder;
import :Base;
import <memory>;
import <vector>;

namespace ComponentSystem
{
	// コンポーネント使用側に継承させる。
	export template <class T> class Holder
	{
	protected:
		std::vector<std::shared_ptr<Base<T>>> components;

	public:
		virtual ~Holder()
		{
			for (auto& comp : this->components)
			{
				comp.reset();
			}
		}

		/// <summary> コンポーネントの追加 /// </summary>
		template <class T> std::shared_ptr<T> AddComp()
		{
			std::shared_ptr<Base> comp = std::make_shared<T>();
			this->components.emplace_back(comp);

			//this->components.back()->parent = this;
			this->components.back()->Start();

			return std::weak_ptr<T>(comp);
		}

		/// <summary> コンポーネントの取得 </summary>
		template <class T> T* GetComp()
		{
			for (auto& comp : this->components)
			{
				T* buff = dynamic_cast<T*>(comp.get());
				if (buff != nullptr)
				{
					return buff;
				}
			}
			return nullptr;
		}

		/// <summary> コンポーネントの除外 </summary>
		template <class T> void RmComp()
		{
			// 指定したコンポーネントがあるか判定
			for (auto itr = this->components.begin(); itr != this->components.end(); ++itr)
			{
				std::shared_ptr<T> comp = std::dynamic_pointer_cast<T>(*itr);
				if (comp != nullptr)
				{
					itr->reset();
					this->components.erase(itr);
					break;
				}
			}
		}
	};
}