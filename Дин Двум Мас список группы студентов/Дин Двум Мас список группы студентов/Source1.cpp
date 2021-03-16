//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//void filter(const char* str, char** destlist);
//void sort(char** strlist, int strcnt);
//
//int main()
//{
//	char   str[80];
//	char** strlist;
//	int    delimcnt = 0;
//
//	cin.getline(str, 80);
//
//	for (int i = 0; str[i] != '\0'; i++)
//		if (str[i] == ',' || str[i] == '.')
//			delimcnt++;
//
//	if (delimcnt == 0) {
//		cout << "Wrong input string\n";
//		return 1;
//	}
//
//	strlist = new char* [delimcnt];
//	for (int i = 0; i < delimcnt; i++)
//		strlist[i] = new char[20];
//
//	filter(str, strlist);
//	sort(strlist, delimcnt);
//
//	for (int i = 0; i < delimcnt; i++)
//		cout << strlist[i] << endl;
//
//	return 0;
//}
//
//void filter(const char* str, char** destlist)
//{
//	for (int i = 0, j = 0, k = 0; str[i] != '\0'; i++) {
//		if (str[i] == ',' || str[i] == '.') {
//			// Если j не равно нулю, то прибавить единицу, дабы не скопировать запятую
//			strncpy(destlist[k], str + j + (j != 0), i - j - (j != 0));
//			destlist[k][i - j] = '\0';
//			k++;
//			j = i;
//		}
//	}
//}
//
//void sort(char** strlist, int strcnt)
//{
//	for (int i = 0; i < strcnt - 1; i++)
//		for (int j = i + 1; j < strcnt; j++)
//			if (strcmp(strlist[i], strlist[j]) > 0) {
//				char* tmp = strlist[i];
//				strlist[i] = strlist[j];
//				strlist[j] = tmp;
//			}
//}