// (C) 2023.7.15 elAsTeru. //

export module PoolSystem;
import <vector>;
import <iostream>;

namespace PoolSystem
{
	export template <class T> class Pool
	{
	public:
		Pool() = delete;
		Pool(const uint32_t& _Size):
			FirstSize(_Size)
		{
			this->pool.resize(_Size);
			for (auto& element : this->pool)
			{
				element = new T;
			}
		}
		~Pool()
		{
			std::cout << static_cast<int32_t>(this->FirstSize - (this->pool.size() + this->use.size())) << '\n';

			for (auto& element : this->pool)
			{
				delete element;
			}
			this->pool.clear();

			for (auto& element : this->use)
			{
				delete element;
			}
			this->pool.clear();
		}

		std::vector<T*> pool;
		std::vector<T*> use;
		const uint32_t FirstSize;	// debug用 初期サイズの記録

		// 関数名変更する予定
		void Add()
		{
			this->use.emplace_back(new T);
		}

		T* Get()
		{
			if (this->pool.size() > 0)
			{
				this->use.emplace_back(this->pool.back());
				this->pool.pop_back();
			}
			else
			{
				this->Add();
			}
			return use.back();
		}

		void Rm(const T* _element)
		{
			// _elementが使われている要素かチェックを行う
			for (auto& element : this->use)
			{
				if (_element == element)
				{
					//std::swap(this->use.back(), _element);
					auto temp = element;
					element = this->use.back();
					this->use.back() = temp;

					this->pool.emplace_back(this->use.back());
					this->use.pop_back();
					break;
				}
			}
		}
	};
}