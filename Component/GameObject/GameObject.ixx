export module GameObject;
import ComponentSystem;

export class GameObject : public ComponentSystem::Holder
{
public:
	GameObject(const char* _name = "anonymous", const char* _tag = "untagged") :
		name(_name),
		tag(_tag)
	{
		// GameObject�̊Ǘ����X�g�ɒǉ������B(�V�[����������ꍇ�FGameObject -> Mgr -> Scene)
	}

	~GameObject(){}

	const char* name;
	const char* tag;
};