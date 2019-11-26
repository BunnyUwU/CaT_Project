#include "project.h"

//int main(int argc, char** argv) {
//	ifstream fi;
//	fi.open(argv[1]);
//	ofstream fo;
//	fo.open(argv[2]);
//
//	int count, array[3];
//	int p1, start, next;
//	long long p2;
//	string str, str1, str2, str3, str4, result;
//	QInt temp;
//
//	for (int i = 0; i < 3; i++) {
//		array[i] = 0;
//
//		while (!fi.eof()) {
//			count = 0;
//
//			getline(fi, str, '\n');
//
//			if (str == "")
//				break;
//
//			for (int i = 0; i < str.size(); i++) {
//				if (str[i] == ' ') {
//					count++;
//					array[count - 1] = i;
//				}
//			}
//
//			if (count == 3) {
//
//				start = 0;
//				next = array[0];
//				str1 = str.substr(start, next - start);
//
//				start = next + 1;
//				next = array[1];
//				str2 = str.substr(start, next - start);
//
//				start = next + 1;
//				next = array[2];
//				str3 = str.substr(start, next - start);
//
//				start = next + 1;
//				next = str.length();
//				str4 = str.substr(start, next - start);
//
//				p1 = stoi(str1);
//				QInt a(p1, str2);
//				QInt b(p1, str4);
//
//				if (str3 == "+") {
//					temp = a + b;
//				}
//				if (str3 == "-") {
//					temp = a - b;
//				}
//				if (str3 == "*") {
//					temp = a * b;
//				}
//				if (str3 == "/") {
//					temp = a / b;
//				}
//				if (str3 == "&") {
//					temp = a & b;
//				}
//				if (str3 == "|") {
//					temp = a | b;
//				}
//				if (str3 == "^") {
//					temp = a ^ b;
//				}
//				if (str3 == ">>") {
//					p2 = stoi(str4);
//					a = a >> p2;
//					temp = a;
//				}
//				if (str3 == "<<") {
//					p2 = stoi(str4);
//					a = a << p2;
//					temp = a;
//				}
//
//				if (p1 == 2) { result = temp.getData(); }
//				if (p1 == 10) { result = temp.toDe(); }
//				if (p1 == 16) { result = temp.toHex(); }
//			}
//
//			if (count == 2) {
//				start = 0;
//				next = array[0];
//				str1 = str.substr(start, next - start);
//
//				start = next + 1;
//				next = array[1];
//				str2 = str.substr(start, next - start);
//
//				start = next + 1;
//				next = str.length();
//				str3 = str.substr(start, next - start);
//
//				p1 = stoi(str1);
//				QInt a(p1, str3);
//
//				if (str2 == "~") {
//					a = ~a;
//					temp = a;
//				}
//				if (str2 == "ror") {
//					temp = a.roR();
//				}
//				if (str2 == "rol") {
//					temp = a.roL();
//				}
//				if (p1 == 2) { result = temp.getData(); }
//				if (p1 == 10) { result = temp.toDe(); }
//				if (p1 == 16) { result = temp.toHex(); }
//
//				if (str2 == "2") {
//					result = a.getData();
//				}
//				if (str2 == "10") {
//					result = a.toDe();
//				}
//				if (str2 == "16") {
//					result = a.toHex();
//				}
//
//			}
//
//			fo << result << endl;
//		}
//
//		fi.close();
//		fo.close();
//		std::system("pause");
//		return 0;
//	}
//}

int main()
{
	QInt bit(16, "15F2");
	QInt bit2(10, "675");
	QInt result = bit + bit2;

	//cout << result.getData() << endl;
	cout << result.getData() << endl;
	cout << result.toDe() << endl;

	return 0;
}