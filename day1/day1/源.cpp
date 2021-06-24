#include<iostream>
#include <string>
using namespace std;
/*
* warrior:编号、生命值、攻击力，编号从1到n，创建时有一个生命值
* 创造warrior有顺序，且消耗生命元，不足就跳过，直到所有的都不能创造了
* base:生命元、warrior数组，不同的种类要计数，阵营颜色，计时器
*/
class warrior {
public:
	int id;
	int strength;
	string name;
	//warrior(int id_, int strength_, string name_) {
		//id = id_; strength = strength_; name = name_;
	//}
};
class base {
public:
	string color;
	int money;
	int timer = 0;
	string rule[5];
	int rules[5];
	int ruless[5] = {0};//每个类型士兵数目
	int temp=0;//当前的次序
	warrior w[100];
	int number = 0;
	int endflag = 0;
	void new_warrior();
	void printtime() {
		if (timer < 100)
		{
			cout << 0;
			if (timer < 10)
				cout << 0;
		}
		cout << timer;
		timer++;
	}
};
void base::new_warrior() {
	int Min = 999;
	for (int i = 0; i < 5; i++) {
		if (rules[i] <= Min)
			Min = rules[i];
	}
	if (money < Min) {
		endflag = 1;
	}
	else {
		temp %= 5;
		if (money < rules[temp]) {
			for (int i = 1; i < 5; i++) {
				if (money >= rules[(temp + i) % 5]) {
					temp = (temp + i) % 5;
					break;
				}
			}
		}
		w[number].id = number;
		w[number].strength = rules[temp];
		w[number].name = rule[temp];
		ruless[temp]++;
		printtime();
		cout << " " << color << " " << w[number].name << " " << w[number].id+1 << " born with strength " << w[number].strength << ",";
		//printwarrior(w[number].name);
		cout << ruless[temp];
		cout << " " << w[number].name << " in " << color << " headquarter" << endl;
		number++;
		money -= rules[temp];
		temp++;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n;i++) {
		cout << "Case:" << i+1<<endl;
		base r, b;
		r.color = "red";
		b.color = "blue";
		r.rule[0] = "iceman"; r.rule[1] = "lion"; r.rule[2] = "wolf"; r.rule[3] = "ninja"; r.rule[4] = "dragon";
		b.rule[0] = "lion"; b.rule[1] = "dragon"; b.rule[2] = "ninja"; b.rule[3] = "iceman"; b.rule[4] = "wolf";
		int m;
		cin >> m;
		r.money = b.money = m;
		int t[5];
		for (int i = 0; i < 5; i++)
			cin >> t[i];
		r.rules[0] = t[2]; r.rules[1] = t[3]; r.rules[2] = t[4]; r.rules[3] = t[1]; r.rules[4] = t[0];
		b.rules[0] = t[3]; b.rules[1] = t[0]; b.rules[2] = t[1]; b.rules[3] = t[2]; b.rules[4] = t[4];
		int end1 = 0;int end2 = 0;
		while (!r.endflag || !b.endflag) {
			if (!end1)
			{
				r.new_warrior();
				if (r.endflag) {
					r.printtime();
					cout << " " << r.color << " headquarter stops making warriors" << endl;
					end1 = 1;
				}
			}
			if (!end2) {
				b.new_warrior();
				if (b.endflag) {
					b.printtime();
					cout << " " << b.color << " headquarter stops making warriors" << endl;
					end2 = 1;
				}
			}
		}

	}
}