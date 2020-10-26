#include <iostream>
#include <locale.h>

using namespace std;

class People {
protected:

	int Rost;
	string rabota;

public:

	virtual void RostM() = 0;

	virtual void print() = 0;

	People() {
		this->Rost = 0;
		this->rabota = ' ';
	}

	People(int Rost1, string rabota1):Rost(Rost1),rabota(rabota1){
		
	}
	void setRost(int Rost1) {
		Rost = Rost1;
	}
	void setrabota(string rabota1) {
		rabota = rabota1;
	}

	virtual ~People()
	{
		cout << "dectr" << endl;
	}
};

class Trener : public People {

protected:

	int stazh;
	string name;

public:

	Trener() : People() {
		this->stazh = 0;
		this->name = ' ';
	}

	Trener(int stazh1, string name1, int Rost1, string rabota1) : People(Rost, rabota), stazh(stazh1), name(name1) {
		
	}

	~Trener()
	{

	}
	void RostM() {
		int Rost2 = Rost/100;
		cout << "���� � ������ = " << Rost2;
	}
	void setstazh(int stazh1) {
		stazh = stazh1;
	}
	void setname(string name1) {
		name = name1;
	}
	void print()  {
		cout << endl;
		cout << "��� ������� : " << this->name << endl;
		cout << "���� : " << stazh << endl;
		cout << "���� :" << Rost << endl;
		cout << "������ :" << this->rabota << endl;
	}
};

class OsnovnoiSostav : public People {

protected:

	int kol;
	int kolNap;
public:

	OsnovnoiSostav() : People() {
		this->kol = 0;
		this->kolNap = 0;
	}

	OsnovnoiSostav(int kol1, int kolNap1, int Rost1, string rabota1) : People(Rost, rabota), kol(kol1), kolNap(kolNap1) {
	
	}

	~OsnovnoiSostav()
	{
	
	}
	void RostM() {
		int Rost2 = Rost / 100;
		cout << "���� � ������ = " << Rost2;
	}
	void setkol(int kol1) {
		kol = kol1;
	}
	void setkolNap(int kolNap1) {
		kolNap = kolNap1;
	}

	void print() {
		cout << endl;
		cout << "���������� ���������� : " << kolNap << endl;
		cout << "���������� ������� : " << kol << endl;
		cout << "���� :" << Rost << endl;
		cout << "������ :" << rabota << endl;
	}

};

class Football : public OsnovnoiSostav {
protected:

	int kolClub;
	int godSozdania;

public:

	Football() : OsnovnoiSostav() {
		this->kolClub = 0;
		this->godSozdania = 0;
	}

	Football(int kolClub1, int godSozdania1, int Rost1, string rabota1, int kol1, int kolNap) {

	}

	~Football()
	{
	
	}
	void RostM() {
		int Rost2 = Rost / 100;
		cout << "���� � ������ = " << Rost2;
	}
	void setkolClub(int kolClub1) {
		kolClub = kolClub1;
	}

	void setgodSozdania(int godSozdania1) {
		godSozdania = godSozdania1;
	}

	void print() {
		cout << endl;
		cout << "���-�� ������:" << kolClub << endl;
		cout << "��� �������� :" << godSozdania << endl;
		cout << "���� :" << Rost << endl;
		cout << "������ :" << rabota << endl;
		cout << "���������� ������� : " << kol << endl;
		cout << "���������� ���������� : " << kolNap << endl;
	}
};

int check_int()
{
	while (true)
	{
		int a;
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "��������� �������: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return a;
		}
	}
}

string check_string(string s)
{
	int i = 0;
	string str;
	while (s[i])
	{
		if ((s[i] >= 97) && (s[i] <= 122))
			str = str + s[i];
		else
		{
			cout << "��������� ������� : ";
			cin >> s;
			return check_string(s);
		}
		i++;
	}
	return str;
}
void setPeople(People& People1) {
	int Rost1;
	cout << "���� : ";
	Rost1 = check_int();
	People1.setRost(Rost1);
	string rabota1;
	cout << "������ : ";
	cin >> rabota1;
	check_string(rabota1);
	People1.setrabota(rabota1);
}

void setTrener(Trener& Trener1) {
	setPeople(Trener1);
	int stazh1;
	cout << "���� : ";
	cin >> stazh1;
	stazh1 = check_int();
	Trener1.setstazh(stazh1);
	string name1;
	cout << "��� ������� : ";
	cin >> name1;
	check_string(name1);
	Trener1.setname(name1);
}

void setOsnovnoiSostav(OsnovnoiSostav& OsnovnoiSostav1) {
	setPeople(OsnovnoiSostav1);
	int kol1;
	cout << "���������� ������� : ";
	kol1 = check_int();
	OsnovnoiSostav1.setkol(kol1);
	int kolNap1;
	cout << "���������� ���������� : ";
	kolNap1 = check_int();
	OsnovnoiSostav1.setkolNap(kolNap1);
}

void setFootball(Football& Football1) {
	setOsnovnoiSostav(Football1);
	int kolClub1;
	cout << "���������� ������ : ";
	kolClub1 = check_int();
	Football1.setkolClub(kolClub1);
	int godSozdania1;
	cout << "��� ������� : ";
	cin >> godSozdania1;
	godSozdania1 = check_int();
	Football1.setgodSozdania(godSozdania1);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	string name; int stazh1 = 0; int kol1 = 0; int kolNap = 0; int godSozdania = 0; int kolClub;
	
	Trener* ptrTrener = new Trener[2];
	OsnovnoiSostav* ptrOsnovnoiSostav = new OsnovnoiSostav[2];
	Football* ptrFootball = new Football[2];
	People* people;

	for (int i = 0; i < 2; i++)
	{
		cout << endl << "-----" << endl;
		setTrener(ptrTrener[i]);
		people = &ptrTrener[i];
		people->print();
		people->RostM();
	}
	cout << endl << "----------------------" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << endl << "-----" << endl;
		setOsnovnoiSostav(ptrOsnovnoiSostav[i]);
		people = &ptrOsnovnoiSostav[i];
		people->print();
		people->RostM();
	}
	cout << endl << "----------------------" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << endl << "-----" << endl;
		setFootball(ptrFootball[i]);
		people = &ptrFootball[i];
		people->print();
		people->RostM();
	}
	cout << endl << "----------------------" << endl;
	cout << endl;

	system("pause");

}