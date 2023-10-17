export module TestObject;
import ComponentSystem;
import <iostream>;

export class TestObject : public ComponentSystem::Owner<TestObject>
{
public:
	TestObject(const char* _name = "anonymous", const char* _tag = "untagged") :
		name(_name),
		tag(_tag)
	{
		// 実際に使う場合はTestObjectの管理リストに追加される。(シーン分けする場合：TestObject -> Mgr -> Scene)

		std::cout << this->name << " Instanced.\n";
	}

	~TestObject()
	{
		std::cout << this->name << " Deleted.\n";
	}

	const char* name;
	const char* tag;
};