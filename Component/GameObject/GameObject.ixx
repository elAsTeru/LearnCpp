export module GameObject;
import ComponentSystem;
import <iostream>;

export class GameObject : public ComponentSystem::Owner<GameObject>
{
public:
	GameObject(const char* _name = "anonymous", const char* _tag = "untagged") :
		name(_name),
		tag(_tag)
	{
		// 実際に使う場合はGameObjectの管理リストに追加される。(シーン分けする場合：GameObject -> Mgr -> Scene)

		std::cout << this->name << " Instanced.\n";
	}

	~GameObject()
	{
		std::cout << this->name << " Deleted.\n";
	}

	const char* name;
	const char* tag;
};