#include <iostream>
#include <string>

class NPC
{
public:
	NPC() { std::cout << "기본 생성자\n"; }
	NPC(int npcCode, const std::string& name): npcCode(npcCode), name(name) { std::cout << "인자 있는 생성자\n"; }

	NPC(const NPC& other) { std::cout << "복사 생성자\n"; }
	NPC& operator=(const NPC& other) { std::cout << "대입 연산자\n"; return *this; }

	NPC(NPC&& other) { std::cout << "Move 생성자\n"; }
	NPC& operator=(NPC&& other) { std::cout << "Move 대입 연산자\n"; return *this; }

	int npcCode;
	std::string name;
};

int main()
{
	/*std::cout << "1\n";
	NPC npc1(NPC(10, "Orge1"));

	std::cout << "\n2\n";
	NPC npc2(11, "Orge2");
	NPC npc3 = npc2;

	std::cout << "\n3\n";
	NPC npc4;
	NPC npc5;
	npc5 = npc4;

	std::cout << "\n4\n";
	NPC npc6 = NPC(12, "Orge3");*/
	NPC* npc10 = new NPC(12, "odfd");
	std::cout << npc10 << std::endl;

	NPC* npc11;
	npc11 = std::move(npc10);
	std::cout << npc11 << std::endl;
	//npc10 = std::move(npc11);
	std::cout << npc10->name << std::endl;
	std::cout << npc10->npcCode << std::endl;
	std::cout << npc11->name << std::endl;
	std::cout << npc11->npcCode << std::endl;
	std::cout << npc10 << std::endl;
	std::cout << npc11 << std::endl;
	//std::cout << "\n5\n";
	//NPC npc7;
	//NPC npc8;
	//npc8 = std::move(npc7);

	std::cin.get();
}