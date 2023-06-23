#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
	string a;
	string file_name;
	cout << "Enter file name " << endl;
	getline(cin, file_name);
	ofstream MyFile("abdo.txt");
	//ifstream MyReadFile("New Text Document.txt");
	ifstream MyReadFile(file_name);
	int c = 0, v = 1;
	bool flag = 0;
	bool lord = true;
	bool trable = false;
	while (getline(MyReadFile, a)) {
		flag = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '/' && a[i + 1] == '/' && v && lord) {
				if (a[a.size() - 1] == '\\') {
					trable = true;
				}
				break;
			}
			else if (trable == true) {
				if (a[a.size() - 1] != '\\')
					trable = false;
				break;
			}
			//		else if ((a[i] == ' ' || a[i] == 9) && lord) {
			//			continue;
			//		}
			else if (a[i] == '"' && a[i - 1] != '\\') {
				lord = !(lord);
				MyFile << a[i];
			}
			else if (a[i] == '/' && a[i + 1] == '*' && v && lord) {
				i++;
				v = 0;
			}
			else if (a[i] == '*' && a[i + 1] == '/' && v == 0) {
				v = 1;
				i++;
				continue;
			}
			else if (v) {
				MyFile << a[i];
				flag = 1;
			}
		}
		if (flag && v == 1) {
			MyFile << endl;
		}
	}
	MyReadFile.close();
	MyFile.close();
	ifstream MyReadFile1("abdo.txt");
	ofstream MyFile1("tempo.txt");
	while (getline(MyReadFile1, a)) {
		long long exodia = 0;
		flag = 1;
		for (int i = 0; i < a.size(); i++) {
			if ((a[i] == '"' || a[i] == '\'') && a[i - 1] != '\\') {
				flag = !flag;
			}
			if (i != a.size() - 1&&i!=0)
				if ((a[i] == ' ' || a[i] == 9) && (((!((a[i + 1] >= 65 && a[i + 1] <= 90) || (a[i + 1] >= 97 && a[i + 1] <= 122))) || (!((a[i - 1] >= 65 && a[i - 1] <= 90) || (a[i - 1] >= 97 && a[i - 1] <= 122)))) && (a[i + 1] != '_' && a[i - 1] != '_')&& (a[i + 1] != '+' && a[i - 1] != '+') && (a[i + 1] != '-' && a[i - 1] != '-')&& i != 0 && flag)) {
					a.erase(i, 1);
					i--;
				}
			if(i != a.size() - 1 && i != 0&&flag)
				if (a[i] == ' ' && a[i - 1] == '=') {
					a.erase(i, 1);
					i--;
				}

			if ((a[i] == 9 && i != 0) && a[i - 1] != 9 && flag) {
				a[i] = ' ';
			}
			else if (a[i] == 9 && i == 0 && flag) {
				a.erase(0, 1);
				i--;
			}
		}
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == ' ' || a[i] == '	') {
				exodia++;
			}
		}
		if (a.empty() == true || exodia == a.size()) {
			continue;
		}
		else {
			MyFile1 << a << endl;
		}
	}
	MyReadFile1.close();
	MyFile1.close();
	remove("abdo.txt");
	rename("tempo.txt", "abdo.txt");
}