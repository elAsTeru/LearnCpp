export module Component:SelfIntroduction;
import ComponentSystem;
import TestObject;
import <iostream>;


namespace Component
{
	export class SelfIntroduction : public ComponentSystem::Component<TestObject>
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