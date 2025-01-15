#pragma once
class Actor;

class Component {
public:
	Component(Actor* owner = nullptr);
	~Component();




public:
	//Getter and Setter
	Actor* GetOwner() { return m_owner; }
	void SetOwner(Actor* owner) { m_owner = owner; }
	bool GetEnabled() { return m_enabled; }
	void SetEnabled(bool value);

	//Functions
	virtual void OnEnable();
	virtual void OnDisable();
	virtual void Start();
	virtual void Update(double deltaTime);
	virtual void End();

private:
	Actor* m_owner;
	bool m_enabled;
	bool m_started;


};
