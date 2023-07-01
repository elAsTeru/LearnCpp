export module ComponentSystem:Owner;
import :Component;
import <vector>;

namespace ComponentSystem
{
	// �R���|�[�l���g�g�p���Ɍp��������B
	// O : owner class
	// C : component class
	export template <class O>
	class Owner
	{
	protected:
		std::vector<Component<O>*> components;

	public:
		Owner() {}
		virtual ~Owner()
		{
			// �t���폜
			for (auto itr = this->components.rbegin(); itr != this->components.rend(); ++itr)
			{
				if (*itr != nullptr)
				{
					delete *itr;
					*itr = nullptr;
				}
			}
			components.shrink_to_fit();
		}

		template <class C> C* AddComp()
		{
			C* comp{ new C };
			// ���N���X��ComponentSystem::Component���`�F�b�N
			if (dynamic_cast<Component<O>*>(comp) == nullptr)
			{
				delete comp;
				comp = nullptr;
				return comp;
			}
			this->components.emplace_back(comp);
			comp->owner = dynamic_cast<O*>(this);
			comp->Start();
			return comp;
		}

		template <class C> C* GetComp(short _index = 0)
		{
			for (auto& comp : this->components)
			{
				if (C* temp{ dynamic_cast<C*>(comp) }; temp != nullptr && _index-- <= 0)
				{
					return temp;
				}
			}
			return nullptr;
		}

		// �����R���|�[�l���g�𕡐��������Ă���ꍇ���Ԗڂ�������(0~)
		template <class C> void RmComp(short _index = 0)
		{
			for (auto itr{ this->components.begin() }; itr != this->components.end(); ++itr)
			{
				if (dynamic_cast<C*>(*itr) != nullptr && _index-- <= 0)
				{
					delete* itr;
					*itr = nullptr;
					this->components.erase(itr);
					return;
				}
			}
		}
	};
}