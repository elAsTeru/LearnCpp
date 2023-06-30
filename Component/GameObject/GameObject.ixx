export module GameObject;
import ComponentSystem;

export class GameObject : public ComponentSystem::Holder
{
public:
	GameObject(const char* _name = "anonymous", const char* _tag = "untagged") :
		name(_name),
		tag(_tag)
	{
		// GameObjectの管理リストに追加される。(シーン分けする場合：GameObject -> Mgr -> Scene)
	}

	~GameObject(){}

	const char* name;
	const char* tag;
};