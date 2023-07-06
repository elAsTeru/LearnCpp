export module Component:SelfIntroduction;
import ComponentSystem;
import GameObject;
import <iostream>;


namespace Component
{
	export class SelfIntroduction : public ComponentSystem::Component<GameObject>
	{
	public:
		SelfIntroduction(){}
		~SelfIntroduction()
		{
			std::cout << this->owner->name << " ended Component\n";
		}

		void Init() override
		{
			std::cout << this->owner->name << " started SelfIntroduction component.\n";
		}

		void Update() override
		{
			std::cout << "Hello, My name is " << this->owner->name << ".\n";
		}
	};
}